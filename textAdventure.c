#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
/* Have to use #define because using a const throws an error about variables
being used in array initializers.*/
#define MAX_MESSAGE_LENGTH 256

struct threadVars{ /* struct because I can only pass one argument to the threads */
        unsigned int* gameTime; /* Time travelers will (hopefully) never try to run this code before 1970 */
        FILE** finptr; /* double pointer because inputThread might change the file */
        int* paused;
};

/* Prevents the program from continuing for a certain amount of seconds */
/* seconds: the amount of seconds to wait */
void delay(unsigned int seconds){
    unsigned int start = time(0);
    while(time(0) - start < seconds)/*printf("%ld\b", time(0) - start)*/;
}

/* Reads the next line in the stream of events */
/* fin: the stream of events to read from */
/* gameTime: the time, in seconds, since the program started (not including pause time) */
/* timeDelay: the delay, in seconds, between the previous event and the current event */
/* returns 1 if the game should continue, or 0 if the game is over */
int readNextLine(FILE* fin, unsigned int* gameTime, unsigned int* timeDelay){
    *gameTime += *timeDelay; /* add the previous message's delay to the game's time */
    char input[MAX_MESSAGE_LENGTH];
    int stringIndex = 0;
    fgets(input, MAX_MESSAGE_LENGTH, fin);
    if(sscanf(input, "d%u] %n", timeDelay, &stringIndex)){
        printf("%s", input + stringIndex);
        delay(*timeDelay);
    }else if(strstr(input, "_end") != NULL || strstr(input, "_exit") != NULL){
        return 0;
    }
    return 1;
}

void* outputThread(void* arg){
    struct threadVars* vars = arg;
    unsigned int* gameTime = vars->gameTime;
    FILE** finptr = vars->finptr;
    /* store this as a pointer because it might get changed by the other thread */
    int* paused = vars->paused;
    /* declare timeDelay here because readNextLine needs to access the previous line's timeDelay */
    int timeDelay = 0;
    /* if paused is true, then it won't even bother checking the other side of
    the || so readNextLine will never be executed. */
    while(*paused || readNextLine(*finptr, gameTime, &timeDelay));
    /* if the code reaches this point, it's time to exit! */
    printf("The end! Feel free to play again using a different camera! Exiting...\n");
    exit(0);
}

/* If there exists a file named "Cameras/<name>.txt", will switch fin to that,
move the stream to the first message that comes chronologically after
previousMessageTime */
/* name: the name of the camera in question */
/* gameTime: the time, in seconds, since the program started (not including pause time) */
/* finptr: a pointer to the file stream in question */
/* returns 1 if the file exists, or 0 if it does not */
int switchCamera(char* name, unsigned int gameTime, FILE** finptr){
    char path[50];
    sprintf(path, "./Cameras/%s.txt", name);
    FILE* open = fopen(path, "r");
    if(open == NULL) return 0;
    fclose(*finptr); /* close the currently open file to prevent memory leaks */
    *finptr = open;
    int skipTime = 0;

    char nextLine[MAX_MESSAGE_LENGTH];
    /* loops until the stream is right before the first message that should be printed at or after the gameTime */
    while(skipTime < gameTime && fgets(nextLine, MAX_MESSAGE_LENGTH, *finptr)){
        int lineDelay, stringIndex;
        char eventType;
        sscanf(nextLine, "%c%d] %n", &eventType, &lineDelay, &stringIndex);
        switch(eventType){
             /* if it starts with a d, it is an instant event, and because it happened in the past,
             the message shouldn't print because the player didn't witness it */
            case 'd':
                skipTime += lineDelay;
                break;
            /* if it starts with a d, it is an ongoing event, and although the player didn't
            witness it starting, they still see it before it's over, so it should print */
            case 's':
                if(skipTime + lineDelay >= gameTime)
                    printf("%s", nextLine + stringIndex);
                break;
        }
    }
    return 1;
}

/* identifies the command that the player has input and executes it.*/
/* command: the command in question */
/* gameTime: the time, in seconds, since the program started (not including pause time) */
/* finptr: a pointer to the  event stream that might be changed by a command */
/* paused: boolean value representing whether or not the output is paused */
void handlePlayerCommand(char* command, unsigned int* gameTime, FILE** finptr, int* paused){
    /* use strcmp here because the string should consist solely of '\n' */
    if(strcmp(command, "\n") == 0){
        *paused = !*paused;
        if(*paused)
            printf("Game is paused. To unpause, press enter\n");
    }else if(strstr(command, "help") != NULL){
        printf("To switch cameras, type \"camera\"\n\
                To quit, type \"quit\"\n");
    }else if(strstr(command, "camera") != NULL){
        char arg[25];
        if(sscanf(command, "camera %s", arg)){
            /* dereference gameTime because there's no reason to expect that it would change during the execution of switchCamera */
            if(switchCamera(arg, *gameTime, finptr)) return;
            /* if no camera is specified or if it is not a valid camera, print out a list of valid cameras
               the list is hardcoded because there is no platform independent way to list files as far as I know */
            printf("The cameras are: start\n");
        }
    }else if(strstr(command, "quit") != NULL){
        exit(0);
    }else{
        printf("Command not recognised. Type \"help\" for a list of commands\n");
    }
}

/* Waits for player input and processes it */
void* inputThread(void* arg){
    struct threadVars* vars = arg;
    unsigned int* gameTime = vars->gameTime;
    FILE** finptr = vars->finptr;
    int* paused = vars->paused;

    int inputLength = 100;
    char input[inputLength];
    while(1)
        handlePlayerCommand(fgets(input, inputLength, stdin), gameTime, finptr, paused);
}

int main(){
    int gameTime = 0;
    FILE* fin = fopen("./Cameras/start.txt", "r");
    int paused = 0;
    struct threadVars vars = {&gameTime, &fin, &paused};
    /* declare threads */
    pthread_t outpThread;
    pthread_t inpThread;
    /* create threads */
    pthread_create(&outpThread, NULL, outputThread, &vars);
    pthread_create(&inpThread, NULL, inputThread, &vars);
    /* link the threads to their return values(?) */
    pthread_join(outpThread, NULL);
    pthread_join(inpThread, NULL);
    fclose(fin);
    return 0;
}
//FILE* fin = fopen("./Cameras/exampleCam.txt", "r");
