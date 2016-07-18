#include "Instructions.h"
#include <string.h>
#include <stdio.h>

/* Here's a dictionary mapping the types of instruction with the strings that call them */
/* to differentiate between instructions, it's best to put a space after instructions with arguments and '\n' after instructions without any */
const InstructionMap instructionCalls[] = {
    {INSTANT_EVENT, "i "},
    {INSTANT_EVENT, "instant "},
    {ONGOING_EVENT_ABSOLUTE, "oa "},
    {ONGOING_EVENT_ABSOLUTE, "ongoing_till "},
    {ONGOING_EVENT_RELATIVE, "or "},
    {ONGOING_EVENT_RELATIVE, "ongoing_for "},
    {WAIT_ABSOLUTE, "wa "},
    {WAIT_ABSOLUTE, "wait_till "},
    {WAIT_RELATIVE, "wr "},
    {WAIT_RELATIVE, "wait_for "},
    {COMMENT, "//"},
    {EXIT, "q\n"},
    {EXIT, "quit\n"},
    {EXIT, "exit\n"},
    {EXIT, "end\n"},
    {CHANGE_CAMERA, "c "},
    {CHANGE_CAMERA, "camera "},
    {LIST_CAMERAS, "cameras\n"},
    {PAUSE, "p\n"},
    {PAUSE, "pause\n"},
    {PAUSE, "\n"},
    {PAUSE_SILENT, "ps\n"},
    {PAUSE_SILENT, "pause_silent\n"},
    {HELP, "help\n"},
    {HELP, "h\n"},
    {HELP, "?\n"}
};

/* binds the commands that the player can input to their help text */
const InstructionMap playerInstructionHelp[] = {
    {CHANGE_CAMERA, "To change the camera, type \"camera <cameraName>\""},
    {LIST_CAMERAS, "To get a list of cameras, type \"cameras\""},
    {EXIT, "To quit, type \"quit\""},
    {PAUSE, "To pause, press enter"}
};

/* Finds the instruction that a string calls */
/* str: the string that calls an instruction */
/* Returns: instructionType and the instruction's arguments. If the string doesn't match any instruction, returns UNDEFINED and NULL */
InstructionMap getInstruction(char* str){
    for(int i = 0; i < sizeof(instructionCalls) / sizeof(InstructionMap); i++){
        if(strncmp(instructionCalls[i].args, str, strlen(instructionCalls[i].args)) == 0){
            return (InstructionMap){instructionCalls[i].type, str + strlen(instructionCalls[i].args)};
        }
    }
    return (InstructionMap){UNDEFINED, NULL};
}

void printHelpText(){
    for(int i = 0; i < sizeof(playerInstructionHelp) / sizeof(InstructionMap); i++)
        printf("%s\n", playerInstructionHelp[i].args);
}
