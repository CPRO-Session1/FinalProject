#ifndef FUNC_H
#define FUNC_H

typedef struct {
	char * room_name;
	char * connected_rooms[10];
	char * items[10];
	char entrance_msg[200];
	char description[200];
} room;

typedef struct {
	room current_room;
} character;

#endif // FUNC_H
