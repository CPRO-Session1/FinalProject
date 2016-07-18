typedef enum InstructionType{
    UNDEFINED,
    INSTANT_EVENT,
    ONGOING_EVENT_ABSOLUTE,
    ONGOING_EVENT_RELATIVE,
    WAIT_ABSOLUTE,
    WAIT_RELATIVE,
    COMMENT,
    EXIT,
    CHANGE_CAMERA,
    LIST_CAMERAS,
    PAUSE,
    PAUSE_SILENT,
    HELP
}InstructionType;

typedef struct InstructionMap { /* used to map an instruction to a string */
    InstructionType type;
    char* args;
}InstructionMap;

InstructionMap getInstruction(char* str);
void printHelpText();
