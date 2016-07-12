#include "func.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_room_summary(room room)
{
	printf("%s\n", room.description);
	int size = sizeof(room.items)/sizeof(room.items[0]);
	int saw = 0;
	if (size) 
	{
		printf("I see ");
		for (int i = 0; i < size - 1; i++)
		{
			if (room.items[i] == NULL && saw == 1) 
			{
				printf("and a %s.\n\n", room.items[i-1]);
				break;
			}
			else if (room.items[i] != NULL && room.items[i+1] != NULL) 
			{
				printf("a %s, ", room.items[i]);
				saw = 1;
			}
			
		}
		if (!saw) printf("nothing.\n\n");
	}
}

void get_args(char** arg1Ptr , char ** arg2Ptr, char* command)
{
	char * commandPtr = command;
	char * command_list[8] = {"look", "open", "goto", "take", "help", "yell", "put", "drop"};
	char *arg1 = (char*) malloc(strlen(command)*sizeof(char));
	char *arg2 = (char*) malloc(strlen(command)*sizeof(char));

	for(int i = 0; *commandPtr != ' ' && i <= (int) strlen(command); i++)
	{
		arg1[i] = *commandPtr;
		commandPtr++;
		if (*commandPtr == '\n')
		{
			arg1[i+1] = '\0';
			break;
		}
		if (*commandPtr == ' ') 
		{
			arg1[i+1] = '\0';
			break;
		}
	}
	realloc(arg1, (strlen(arg1)+1)*sizeof(char));
	for(int i = 0; *commandPtr != '\0'; i++)
	{
		commandPtr++;
		arg2[i] = *commandPtr;
		if (*commandPtr == '\n' || *commandPtr == '\0')
		{
			arg2[i] = '\0';
			break;
		}
	}
	realloc(arg2, (strlen(arg2)+1)*sizeof(char));
	printf("ARGS: |%s|, |%s|\n", arg1, arg2);

	int found_command = 0;
	for (int i = 0; i < (int) (sizeof(command_list)/sizeof(command_list[0])); i++)
	{
		if (strcmp(arg1, command_list[i]) == 0)
		{
			found_command = 1;
		}
	}

	if (found_command)
	{
		*arg1Ptr = arg1;
		*arg2Ptr = arg2;
	}
	else if (*arg1 == '\n')
	{
		*arg1Ptr = "none";
		*arg2Ptr = arg2;
	}
	else 
	{
		*arg1Ptr = NULL;
		*arg2Ptr = NULL;
	}

	if (sizeof(arg1)) 
	{ 
		arg1 = NULL;
	}
	if (sizeof(arg2)) 
	{ 
		arg2 = NULL;
	}
	printf("Made args: |%s|, |%s|\n", *arg1Ptr, *arg2Ptr);
}

void moveto(character*playerPtr, room droom, room sroom)
{
	int moved = 0;
	if (strcmp(sroom.room_name,droom.room_name) == 0)
	{
		printf("You're already here.\n");
		return;
	}
	for (int i = 0; i < (int) (sizeof(sroom.connected_rooms)/sizeof(sroom.connected_rooms[0])); i++)
	{
		if (sroom.connected_rooms[i])
		{
			if (strcmp(droom.room_name, sroom.connected_rooms[i]) == 0)
			{
				playerPtr->current_room = droom;
				printf("\033[2J");
				printf("%s\n", playerPtr->current_room.entrance_msg);
				moved = 1;
			}
		}
	}
	if (!moved)
	{
		printf("I can't get to the %s from here.\n", droom.room_name);
	}

}
int main()
{
	int running = 1;
	character player;
	character * playerPtr = &player;

	/* SET START --------------------------------*/
	room start = {"start", {"bedroom"}}; 
	strcpy(start.description , "Game Name. [goto] the bedroom to start.");
	/* SET START --------------------------------*/

	/* SET BEDROOM --------------------------------*/
	room bedroom = {"bedroom", {"start", "kitchen"}, {"pencil", "towel", "backpack"}};
	strcpy(bedroom.entrance_msg, "You wake up.");
	strcpy(bedroom.description, "My bedroom. Nothing special.");
	/* SET BEDROOM --------------------------------*/

	/*SET KITCHEN ----------------------------------*/
	room kitchen = {"kitchen", {"bedroom"}};
	/*SET KITCHEN ----------------------------------*/

	room rooms[3] = {start, bedroom, kitchen};
	player.current_room = start;

	printf("\033[2J");
	print_room_summary(player.current_room);
	printf("\n");
	while (running)
	{

		/* GET INPUT */
		int n = 3;
		char * command =  malloc(n*sizeof(char));
		fgets(command, n, stdin); //Take command
		size_t last = strlen(command);
		while (command[last-1] != '\n') //stolen from powerpoint
		{
			n *= 2;
			command = realloc(command, n);
			fgets(command+last, n/2, stdin);
			last = strlen(command);
		}
		char *arg1, *arg2;
		char ** arg1Ptr = &arg1;
		char ** arg2Ptr = &arg2;
		get_args(arg1Ptr, arg2Ptr, command);
		printf("Got args: |%s|, |%s|\n", arg1, arg2);
		free(command);
		/* GET INPUT*/

		printf("\033[2J");
		print_room_summary(player.current_room);

		if (arg1 == NULL && arg2 == NULL)
		{
			printf("I don't know how to do that.");
		}
		else if (strcmp(arg1, "none") == 0)
			;
		else if (strcmp(arg1, "goto") == 0)
		{
			char * room_names[3] = {"start", "bedroom", "kitchen"};
			int changed = 0;
			room to_room;
			for (int i = 0; i < (int) (sizeof(rooms)/sizeof(rooms[0])); i++)
			{
				if (strcmp(arg2, room_names[i]) == 0)
				{
					to_room = rooms[i];
					printf("\033[2J");
					moveto(playerPtr, to_room, player.current_room);
					changed = 1;
					print_room_summary(player.current_room);
				}
			}
			if (!changed)
			{
				printf("I don't know where that is.");
			}

		if (*arg1Ptr) free(*arg1Ptr);
		if (*arg2Ptr) free(*arg2Ptr);
		}
		printf("\n");
	}
	return 0;
}
