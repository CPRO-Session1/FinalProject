#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024  /* Making it stupidly long just in case */

#define INSTANT_EVENT_MARKER "_i "
#define ONGOING_EVENT_ABSOLUTE_MARKER "_ot "
#define ONGOING_EVENT_RELATIVE_MARKER "_ow "
#define WAIT_ABSOLUTE_MARKER "_wa "
#define WAIT_RELATIVE_MARKER "_wr "
#define COMMENT_MARKER "//"
#define QUIT_MARKER "_q"

typedef enum InstructionType {
    INSTANT_EVENT,
    ONGOING_EVENT_ABSOLUTE,
    ONGOING_EVENT_RELATIVE,
    WAIT_ABSOLUTE,
    WAIT_RELATIVE,
    COMMENT,
    QUIT,
    UNDEFINED
}InstructionType;

/* checks if the line starts with the marker */
/* line: the line in question */
/* marker: the marker that the line will be checked for */
/* args: The string to store the rest of the line, after the marker */
/* returns 1 if the line contains the marker, otherwise 0 */
int checkInstructionMarker(char* line, const char* marker, char** args){
    if(memcmp(line, marker, strlen(marker)) == 0){
        *args = line + strlen(marker);
        return 1;
    }
    return 0;
}

/* Parses the next instruction in the next line of stream */
/* camera: the stream to read the line from */
/* args: the string to copy the intstruction's arguments to, if there are any */
/* returns: the InstructionType of the next instruction */
InstructionType getNextInstruction(FILE* camera, char** args){
    /* currently, there is no need for this function, but in theory, there could be a command called
    "_a" and a command called "_ab" and this function could serve to make sure that the "_ab" gets checked
    before the "_a" to prevent false positives */
    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, camera);
    if(checkInstructionMarker(line, INSTANT_EVENT_MARKER, args)) return INSTANT_EVENT;
    if(checkInstructionMarker(line, ONGOING_EVENT_ABSOLUTE_MARKER, args)) return ONGOING_EVENT_ABSOLUTE;
    if(checkInstructionMarker(line, ONGOING_EVENT_RELATIVE_MARKER, args)) return ONGOING_EVENT_RELATIVE;
    if(checkInstructionMarker(line, WAIT_ABSOLUTE_MARKER, args)) return WAIT_ABSOLUTE;
    if(checkInstructionMarker(line, WAIT_RELATIVE_MARKER, args)) return WAIT_RELATIVE;
    if(checkInstructionMarker(line, COMMENT_MARKER, args)) return COMMENT;
    if(checkInstructionMarker(line, QUIT_MARKER, args)) return QUIT;
    return UNDEFINED;
}

/* parses a string formatted like a clock (IE %d:%d) */
/* timeToParse: The string to parse */
/* stLen: a pointer that will be set to the character length of the time string */
/* returns: the time that the string represents */
unsigned long int parseTimeString(char* timeToParse, int* stLen){
    unsigned int hours = 0, minutes = 0, seconds = 0;
    if(sscanf(timeToParse, "%u:%u:%u%n", &hours, &minutes, &seconds, stLen)
        || sscanf(timeToParse, "%u:%u%n", &minutes, &seconds, stLen)
        || scanf(timeToParse, "%u%n", &seconds, stLen)){
        return (((hours * 60) + minutes) * 60) + seconds;
    }
    printf("Error: Invalid time string. Exiting\n");
    exit(0);
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

/* Advances the camera till the time */
/* camera: the camera in question */
/* currentTime: the time that the camera is currently on */
/* to: the time that the camera should fast forward to */
/* returns 1 if the game should continue, or 0 if it should end */
int fastForward(FILE* camera, unsigned long int currentTime, unsigned long int to){
    /* Note: currentTime is not a pointer. It will not be changed outside the scope of this function */
    verifyTime(currentTime, to);

    while(currentTime < to){
        char* args;
        int argOffset;
        InstructionType instType = getNextInstruction(camera, &args);

        switch(instType){
            case WAIT_ABSOLUTE:
                currentTime = verifyTime(currentTime, parseTimeString(args, NULL));
                break;
            case WAIT_RELATIVE:
                currentTime += parseTimeString(args, NULL);
                break;
            case ONGOING_EVENT_ABSOLUTE:
                if(verifyTime(currentTime, parseTimeString(args, &argOffset)) > to)
                    printf("%s", args + argOffset);
                break;
            case ONGOING_EVENT_RELATIVE:
                if(currentTime + parseTimeString(args, &argOffset) > to)
                    printf("%s", args + argOffset);
                break;
            case QUIT:
            case UNDEFINED:
                return 0;
        }
    }
}

/* changes the camera to point to a txt file in the /Cameras directory, if such a file exists */
/* name: the name of the file in question. The full path to the file will be "./Cameras/<name>.txt" */
/* camera: the camera to change */
/* returns: 1 if the camera has been changed, or 0 if it has not been changed */
int setCamera(char* name, FILE** camera){
    char path[100]; /* stupidly long just in case */
}

/* Given a user-input string, will check if it is a valid command, and if so, execute it */
/* str: The string to check */
/* currentTime: the current game time. May be changed if the command requires it */
/* camera: the current event stream. May be changed if the command requires it */
/* paused: a boolean representing whether or not the output is paused. May be changed if the command requires it */
int handleCommand(char* str, unsigned long int* currentTime, FILE** camera, int* paused){
    /* remember to pause before changing the camera */

}

void delay(unsigned long int* currentTime, int* paused, unsigned long int seconds){
    /* do it with a for loop so that I can increment currentTime properly */
    for(int i = 0; i < seconds; i++){
        unsigned long int start = time(0);
        while((time(0) - start < 1)) if(*paused) return; /* Will loop for 1 second */
        *currentTime++; /* increase the time by 1 */
    }
}

int readNextLine(int* currentTime, FILE** camera, int* paused){
    char* nextLineArgs;
    InstructionType instType = getNextInstruction(*camera, &nextLineArgs);
    switch(instType){
        case INSTANT_EVENT:
            printf("%s", nextLineArgs);
            break;
        case WAIT_ABSOLUTE:
            delay(currentTime, paused, verifyTime(*currentTime, parseTimeString(nextLineArgs, NULL)) - *currentTime);
            break;
        case WAIT_RELATIVE:
            delay(currentTime, paused, parseTimeString(nextLineArgs, NULL));
            break;
        case QUIT:
        case UNDEFINED:
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
    unsigned long int* currentTime = args->currentTime;
    FILE** camera = args->camera;
    int* paused = args->paused;
    while(*paused || readNextLine(currentTime, camera, paused));
}

void* inputThread(void* args){
    GameData* gd = args;
    while()
}

int main(int argc, char* argv[]){
    unsigned long int gameTime = 0;
    FILE* camera;
    int paused = 0;
    GameData gameData = {&gameTime, &camera, &paused};
    pthread_t inTh;
    pthread_t outTh;
    pthread_create(&inTh, NULL, inputThread, &gameData);
    pthread_create(&outTh, NULL, outputThread, &gameData);
    pthread_join(inTh, NULL);
    pthread_join(outTh, NULL);

}
