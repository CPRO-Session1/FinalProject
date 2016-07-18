#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "Instructions.h"

#define MAX_LINE_LENGTH 1024  /* Making it stupidly long just in case */
#define MAX_COMMAND_LENGTH 256 /* Making this one stupidly long as well */

const char* CAMERA_LIST = "start"; /* Hardcoded because there's no platform-independent way to list files */

/* parses a string formatted like a clock (IE %d:%d) */
/* timeToParse: The string to parse */
/* stLen: a pointer that will be set to the character length of the time string */
/* returns: the time that the string represents */
unsigned long int parseTimeString(char** timeToParse){
    unsigned long int ret = 0;
    int i = 0;
    do{
        i++;
        ret *= 60;
        ret += strtoul(*timeToParse, timeToParse, 10);
    }while(**timeToParse == ':' && i < 3);
    return ret;
}

/* Exits the program if verify is less than current */
/* currentTime: the time to test against */
/* verify: the time to verify */
/* returns: nothing if verify is less than current, otherwise returns verify */
unsigned long int verifyTime(unsigned long int currentTime, unsigned long int verify){
    if(verify < currentTime){
        printf("Error: time (%lu seconds) is less than the current time (%lu seconds)\n", verify, currentTime);
        exit(0);
    }
    return verify;
}

/* delays the program for a certain amount of time, or until the program is paused */
/* currentTime: The current game time. Will be incremented each second */
/* paused: boolean representing whether or not the output is paused. If the output is paused,
there's no reason to continue delaying, as it is already being delayed elsewhere */
/* seconds: the time to delay for. */
void delay(unsigned long int* currentTime, int* paused, unsigned long int seconds){
    /* do it with a for loop so that I can increment currentTime properly */
    for(int i = 0; i < seconds; i++){
        unsigned long int startSecond = time(0);
        while((time(0) - startSecond < 1)){  /* Will loop for 1 second */
            if(*paused){
                *currentTime += seconds - i;
                return;
            }
        }
        ++*currentTime; /* increase the time by 1 */
    }
}

/* Advances the camera till the time */
/* camera: the camera in question */
/* fromTime: the time that the camera is currently on */
/* toTime: the time that the camera should fast forward to. */
/* returns 1 if the game should continue, or 0 if it should end */
int fastForward(FILE** camera, unsigned long int fromTime, unsigned long int* toTime){
    verifyTime(fromTime, *toTime);

    while(fromTime < *toTime){
        char line[MAX_LINE_LENGTH];
        memset(line, 0, MAX_LINE_LENGTH);
        fgets(line, MAX_LINE_LENGTH, *camera);
        InstructionMap inst = getInstruction(line);

        switch(inst.type){
            case WAIT_ABSOLUTE:
                fromTime = verifyTime(fromTime, parseTimeString(&inst.args));
                break;
            case WAIT_RELATIVE:
                fromTime += parseTimeString(&inst.args);
                break;
            case ONGOING_EVENT_ABSOLUTE:
                if(verifyTime(fromTime, parseTimeString(&inst.args)) > *toTime){
                    printf("%s", inst.args);
                }
                break;
            case ONGOING_EVENT_RELATIVE:
                if(fromTime + parseTimeString(&inst.args) > *toTime)
                    printf("%s", inst.args);
                break;
            case UNDEFINED:
                printf("Undefined instruction in stream. Exiting...\n");
                exit(0);
            case EXIT:
                printf("Stream has already ended. Exiting...\n");
                exit(0);
        }
    }
    /* fromTime will be equal to the closest time to the target that is not before it. This just makes sure that
    the time is correctly set to be the time of the next instruction. Trust me, it makes sense */
    *toTime = fromTime;
}

/* changes the camera to point to a txt file in the /Cameras directory, if such a file exists */
/* name: the name of the file in question. The full path to the file will be "./Cameras/<name>.txt" */
/* camera: the camera to change */
/* returns: 1 if the camera has been changed, or 0 if it has not been changed */
int setCamera(char* name, FILE** camera){
    char path[100]; /* stupidly long just in case */

    if(name[strlen(name) - 1] == '\n') name[strlen(name) - 1] = '\0';
    sprintf(path, "./Cameras/%s.txt", name);

    FILE* temp = fopen(path, "r");
    if(temp == NULL)return 0;
    if(*camera != NULL)fclose(*camera);
    *camera = temp;
    return 1;
}

/* Given a user-input string, will check if it is a valid command, and if so, execute it */
/* str: The string to check */
/* currentTime: the current game time. May be changed if the command requires it */
/* camera: the current event stream. May be changed if the command requires it */
/* paused: a boolean representing whether or not the output is paused. May be changed if the command requires it */
/* returns: 1 if the program should continue, otherwise 0 */
int handleCommand(char* str, unsigned long int* currentTime, FILE** camera, int* paused){
    char* args;
    InstructionMap inst = getInstruction(str);

    switch(inst.type){
        case PAUSE:
            *paused = !*paused;
            if(*paused) printf("Game is paused. Press enter to resume.\n");
            else printf("Game is unpaused. Resuming...\n");
            break;
        case EXIT:
            return 0;
        case CHANGE_CAMERA:
            if(setCamera(inst.args, camera))
                return fastForward(camera, 0, currentTime);
        case LIST_CAMERAS:
            printf("Valid cameras are: %s\n", CAMERA_LIST);
            break;
        case HELP:
            printHelpText();
            break;
        case UNDEFINED:
            printf("That is not a valid instruction. Type \"help\" for a list of valid instructions.\n");
            break;
        default:
            printf("That instruction can not be triggered by the player. Type \"help\" for a list of valid instructions.\n");
    }
}

/* Reads the next line in the event stream and executes its instruction */
/* currentTime: the current game time */
/* camera: the event stream in question */
/* paused: boolean representing whether or not the output is paused */
int readNextLine(unsigned long int* currentTime, FILE** camera, int* paused){
    char line[MAX_LINE_LENGTH];
    memset(line, 0, MAX_LINE_LENGTH);
    fgets(line, MAX_LINE_LENGTH, *camera);

    InstructionMap inst = getInstruction(line);
    switch(inst.type){
        case INSTANT_EVENT:
            printf("%s", inst.args);
            // for(int i = 0; i < strlen(inst.args); i++)printf("%hu ", inst.args[i]);
            // printf("\n");
            break;
        case WAIT_ABSOLUTE:
            delay(currentTime, paused, verifyTime(*currentTime, parseTimeString(&inst.args)) - *currentTime);
            break;
        case WAIT_RELATIVE:
            delay(currentTime, paused, parseTimeString(&inst.args));
            break;
        case UNDEFINED:
            printf("Undefined instruction in event stream.\n");
        case EXIT:
            return 0;
    }
    return 1;
}

typedef struct GameData{
    unsigned long int* currentTime;
    FILE** camera;
    int* paused; /* boolean */
}GameData;

void* outputThread(void* args){
    GameData* gd = args;
    unsigned long int* currentTime = gd->currentTime;
    FILE** camera = gd->camera;
    int* paused = gd->paused;

    /* if paused is true, then the || won't bother checking the other side, so readNextLine won't be executed */
    while(*paused || readNextLine(currentTime, camera, paused));
    printf("The end! Exiting...\n");
    exit(0);
}

void* inputThread(void* args){
    GameData* gd = args;
    unsigned long int* currentTime = gd->currentTime;
    FILE** camera = gd->camera;
    int* paused = gd->paused;

    char command[MAX_COMMAND_LENGTH];

    while(1){
        memset(command, 0, MAX_COMMAND_LENGTH);
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        if(handleCommand(command, currentTime, camera, paused) == 0) break;
    }
    printf("Exit command recieved. Exiting...\n");
    exit(0);
}

int main(int argc, char* argv[]){
    unsigned long int gameTime = 0;
    FILE* camera = NULL;
    /* Will only try to set the camera if there is a second argument */

    if(argc > 1 && setCamera(argv[1], &camera)){
        printf("Loaded camera: %s\n", argv[1]);
    }else{
        if(setCamera("start", &camera)){
            printf("Loaded default camera\n");
        }else{
            printf("Error: default camera is missing. Exiting...");
            exit(0);
        }
    }

    int paused = 0;
    GameData gameData = {&gameTime, &camera, &paused};
    pthread_t inTh;
    pthread_t outTh;
    pthread_create(&inTh, NULL, inputThread, &gameData);
    pthread_create(&outTh, NULL, outputThread, &gameData);
    pthread_join(inTh, NULL);
    pthread_join(outTh, NULL);
}
