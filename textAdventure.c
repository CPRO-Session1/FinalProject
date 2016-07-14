#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>
/* Have to use #define because using a const throws an error about variables
being used in array initializers.*/
#define MAX_MESSAGE_LENGTH 256
/* 3 digits for hours, 2 for minutes, 2 for seconds, 2 for colons, 1 for a
square bracket, and 1 for a space */
#define MAX_COMMAND_LENGTH 256

struct threadVars{ /* struct because I can only pass one argument to the threads */
        unsigned int* gameTime;
        FILE** finptr; /* double pointer because inputThread might change the file */
        int* stopPrinting;
};

/* If there exists a file named "Cameras/<name>.txt", will switch fin to that,
move the buffer to the first message that comes chronologically after
previousMessageTime, and returns 1. If the file doesn't exist, returns 0 */
int switchCamera(char* name, struct threadVars* vars){
    char path[50];
    sprintf(path, "./Cameras/%s.txt", name);
    FILE* open = fopen(path, "r");
    if(open == NULL) return 0;
    fclose(*(vars->finptr));
    *(vars->finptr) = open;
    int skipTime = 0;
    int lineDelay;
    char nextLine[MAX_MESSAGE_LENGTH];
    while(skipTime < *(vars->gameTime) && fgets(nextLine, MAX_MESSAGE_LENGTH, *(vars->finptr))){
        sscanf(nextLine, "%d]", &lineDelay);
        printf("skiptime: %d gametime: %u. skip!\n", skipTime, *(vars->gameTime));
        skipTime += lineDelay;
    }
    return 1;
}

int handlePlayerCommand(char* command, struct threadVars* vars){
    char arg[25]; /* No command has more than one arg */
    if(strcmp(command, "\n") == 0){
        *(vars->stopPrinting) = !*(vars->stopPrinting);
    }else if(strstr(command, "help") != NULL){
        printf("To switch cameras, type \"camera\"\n\
                To restart, type \"restart\"\n\
                To quit, type \"quit\"\n");
    }else if(strstr(command, "camera") != NULL){
        if(sscanf(command, "camera %s", arg)){
            if(switchCamera(arg, vars)) return 1;
            printf("The cameras are: start, cam1, cam2\n");
        }
    }else if(strstr(command, "quit") != NULL){
        exit(0);
    }else{
        printf("Command not recognised. Type \"help\" for a list of commands\n");
    }
    return 1;
}

/* Prevents the program from continuing for a certain amount of seconds */
void delay(unsigned int seconds){
    unsigned int start = time(0);
    while(time(0) - start < seconds);
}

int readNextLine(FILE* fin, int* gameTime){
    char input[MAX_MESSAGE_LENGTH];
    unsigned int timeDelay;

    if(fscanf(fin, "%u] ", &timeDelay)){
        char nextChar = fgetc(fin);
        while(nextChar != '\n' && nextChar != '\0' && nextChar != EOF){
            printf("%c", nextChar);
            nextChar = fgetc(fin);
        }
        printf("\n");
        delay(timeDelay);
        *gameTime += timeDelay;
    }else if(strstr(fgets(input, MAX_MESSAGE_LENGTH, fin), "_end") != NULL){
        return 0;
    }

    return 1;
}

void* outputThread(void* arg){
    struct threadVars* vars = arg;
    /* if stopPrinting is true, then it won't even bother checking the other side of
    the ||s so readNextLine will never be executed. */
    while(*(vars->stopPrinting) || readNextLine(*(vars->finptr), vars->gameTime));
    /* because the inputThread is still waiting for input, the user needs to input a quitting command */
    printf("Game over. Please type \"restart\" or \"quit\"\n");
}

/* Waits for player input, and then checks if it's a command and if so, executes it */
void* inputThread(void* arg){
    struct threadVars* vars = arg;
    int inputLength = 100;
    char input[inputLength];
    while(handlePlayerCommand(
        fgets(input, inputLength, stdin), vars)
    );
}

int main(){
    int gameTime = 0;
    FILE* fin = fopen("./Cameras/start.txt", "r");
    int stopPrinting = 0;
    struct threadVars vars = {&gameTime, &fin, &stopPrinting};
    pthread_t outpThread;
    pthread_t inpThread;
    pthread_create(&outpThread, NULL, outputThread, &vars);
    pthread_create(&inpThread, NULL, inputThread, &vars);
    pthread_join(outpThread, NULL);
    pthread_join(inpThread, NULL);
    // FILE* fin = fopen("./Cameras/start.txt", "r");
    // int prevMessageTime = 0;
    // int inputBuffLen = 50;
    // char playerInput[inputBuffLen];
    // while(readNextLine(fin, &prevMessageTime)){
    //     // for(int i = 0; i < inputBuffLen; i++) printf("%d, ", inputBuff[i]);
    //     // printf("\n");
    //     if(feof(stdin) == 0){ /* If the user is inputting something */
    //         fgets(playerInput, inputBuffLen, stdin);
    //         handlePlayerCommand(playerInput, fin);
    //     }
    // }

    fclose(fin);
    return 0;
}
//FILE* fin = fopen("./Cameras/exampleCam.txt", "r");
