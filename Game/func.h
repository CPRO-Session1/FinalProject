#ifndef FUNC_H
#define FUNC_H

typedef struct {
	char * room_name; //room's name
	char * connected_rooms[10]; //names of connected rooms. Note that this is not pointers as I didn't know how to make an array of room pointers while in a room
	char * items[10]; //names of items. There is no item struct, though that would have been a good idea.
	char entrance_msg[200];
	char description[200];
	char look_msg[200];
	int items_size; //size of items. Can't pass array size to function, so I have this.
} room;

typedef struct {
	room * current_room;
	int has_backpack; 
	int inventory_size;
	char * inventory[6];
	int notes_read;
	int has_poo;

} character;

//function prototypes!
void print_room_summary(character *playerPtr);
void get_args(char*, char*, char*);
void take(character*,char*,room*,int);
void moveto(character*, char*, room**);
void look(character*);
void note(character*);

#endif
