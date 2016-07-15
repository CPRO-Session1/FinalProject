#ifndef FUNC_H
#define FUNC_H
#include "func.c"

void print_room_summary(character *playerPtr);
void get_args(char**, char**, char*);
void take(character*,char*,room*,int);
void moveto(character*, char*, room**, char**);
void look(character*);
void note(character*);

#endif
