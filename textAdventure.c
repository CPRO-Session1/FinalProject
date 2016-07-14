#include <stdio.h>
#include <string.h>
#include <time.h>
/* Have to use #define because using a const throws an error about variables
being used in array initializers.*/
#define MAX_MESSAGE_LENGTH 256
/* 3 digits for hours, 2 for minutes, 2 for seconds, 2 for colons, 1 for a
square bracket, and 1 for a space */
#define MAX_COMMAND_LENGTH 256

typedef struct message{
    char str[MAX_MESSAGE_LENGTH];
    /* "time" was already being used somewhere */
    unsigned int seconds;
}Message;



void handlePlayerCommand(char* command, FILE* fin){
    char arg[25]; /* No command has more than one arg */
    if(sscanf(command, "help")){

    }else if(sscanf(command, "camera %s", arg)){

    }else if(sscanf(command, "quit")){

    }else{
        printf("Command not recognised. Type \"help\" for a list of commands\n");
    }
}

/* Prevents the program from continuing for a certain amount of seconds */
void delay(unsigned int seconds){
    unsigned int start = time(0);
    while(time(0) - start < seconds);
}

int readNextLine(FILE* fin, int* prevMessageTime){
    char input[MAX_MESSAGE_LENGTH];
    unsigned int hours, minutes, seconds;
    // fgets(command, MAX_COMMAND_LENGTH, fin);

    //char command[256];
    //fgets(command, 256, fin);

    //if(strstr(command, "_end") != NULL)return 0;
    if(fscanf(fin, "%u:%u:%u] ", &hours, &minutes, &seconds) == 3){

        minutes += hours * 60;
        seconds += minutes * 60;
        int relativeDelay = seconds - *prevMessageTime;
        *prevMessageTime = seconds;
        delay(relativeDelay);
        char nextChar = fgetc(fin);
        while(nextChar != '\n' && nextChar != '\0' && nextChar != EOF){
            printf("%c", nextChar);
            nextChar = fgetc(fin);
        }
        printf("\n");
        //printf("\n");
    }else if(strstr(fgets(input, MAX_MESSAGE_LENGTH, fin), "_end") != NULL){
        return 0;
    }

    return 1;
}



int main(){

    int inputBuffLen = 20;
    char inputBuff[inputBuffLen];
    memset(inputBuff, '\0', inputBuffLen);
    printf("Buffer success? %d\n", setvbuf(stdin, inputBuff, _IOLBF, inputBuffLen));

    // int length = 1024;
    // Message messages[length];
    // readFile(messages, &length);

    FILE* fin = fopen("./Cameras/start.txt", "r");
    int prevMessageTime = 0;
    while(readNextLine(fin, &prevMessageTime)){
        // for(int i = 0; i < inputBuffLen; i++) printf("%d, ", inputBuff[i]);
        // printf("\n");
        while(strlen(inputBuff) > 0){ /* If the user is inputting something */
            char playerInput[inputBuffLen];
            scanf("%s", playerInput);
            handlePlayerCommand(playerInput, fin);
        }
    }


    // for(int i = 0; i < length; i++){
    //     printf("Time: %u, Message: %s\n", messages[i].seconds, messages[i].str);
    //
    //     if(strlen(inputBuff) > 0){ /* If the user is inputting something */
    //         char playerInput[inputBuffLen];
    //         scanf("%s", playerInput);
    //         handleCommand(playerInput);
    //     }
    //
    //     if(i + 1 < length)
    //         delay(messages[i + 1].seconds - messages[i].seconds);
    // }

    fclose(fin);
    return 0;
}
//FILE* fin = fopen("./Cameras/exampleCam.txt", "r");
