#ifndef FUNC_H
#define FUNC_H

typedef struct {
	char * room_name;
	char * connected_rooms[10];
	char * items[10];
	char entrance_msg[200];
	char description[200];
	char look_msg[200];
	int items_size;
} room;

typedef struct {
	room * current_room;
	int has_backpack;
	int inventory_size;
	char * inventory[6];
	int notes_read;
	int has_poo;

} character;
void print_room_summary(character *playerPtr);
void get_args(char*, char*, char*);
void take(character*,char*,room*,int);
void moveto(character*, char*, room**);
void look(character*);
void note(character*);

#endif
