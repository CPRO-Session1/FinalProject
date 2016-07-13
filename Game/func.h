#ifndef FUNC_H
#define FUNC_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

} character;

void get_args(char** arg1Ptr , char ** arg2Ptr, char* command)
{
	char * commandPtr = command;
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
	*arg1Ptr = arg1;
	*arg2Ptr = arg2;
}

void print_room_summary(character *playerPtr)
{
	int saw = 0, is_last = 0;
	printf("|%s|\n", playerPtr->current_room->room_name);
	printf("%s\n", playerPtr->current_room->description);
	
	printf("I see");
	for (int i = 0; i < playerPtr->current_room->items_size; i++)
	{
		is_last =  1;
		for (int j = i+1; j < playerPtr->current_room->items_size; j++)
		{
			if (playerPtr->current_room->items[j] != NULL) is_last = 0;
		}
		if (playerPtr->current_room->items[i] == NULL)
			;
		else if (is_last && saw == 1)
		{
			printf(" and a %s", playerPtr->current_room->items[i]);
		}
		else 
		{
			printf(" a %s", playerPtr->current_room->items[i]);
			if (playerPtr->current_room->items[i+1] != NULL) printf(",");
			saw = 1;
		}
		
	}
	if (!saw) printf(" nothing here");
	printf(".\n");

	if (!playerPtr->has_backpack) return;
	printf("I have: ");
	for (int i = 0;i < playerPtr->inventory_size; i++) 
	{
		if (playerPtr->inventory[i] == NULL) continue;
		printf("|%s| ", playerPtr->inventory[i]);
	}

	printf("\n");
}
void take(character * playerPtr, char * item, room * roomPtr, int room_items_size)
{
	int slot = 0;
	while (playerPtr->inventory[slot] != NULL)
	{
		slot++;
	}
	if (slot+1 == playerPtr->inventory_size)
	{
		printf("\033[2J");
		printf("I have no room left in my bag. Might as well just sit here.");
		return;
	}
	for (int i = 0; i < room_items_size; i++)
	{
		if (playerPtr->current_room->items[i] != NULL)
		{
			if(strcmp(playerPtr->current_room->items[i], item) == 0)
			{
				if (strcmp(item, "backpack") == 0)
				{
					playerPtr->has_backpack = 1;
					playerPtr->current_room->items[i] = NULL;
					printf("\033[2J");
					print_room_summary(playerPtr);
					return;
				}
				if (playerPtr->has_backpack == 0)
				{
					printf("I try to pick up the %s, but I hopelessly fumble and drop it.", item);
					return;
				}
				playerPtr->inventory[slot] = playerPtr->current_room->items[i];
				roomPtr->items[i] = NULL;
				printf("%s\n", playerPtr->current_room->items[i]);
				printf("\033[2J");
				print_room_summary(playerPtr);
				return;
			}
		}
	}
	printf("I can't find a %s here.", item);
}
void moveto(character*playerPtr, char *droom, room * rooms[], char * room_strings[])
{
	int connected = 0, found = 0;
	room *to_room;
	for (int i = 0; ;i++)
	{
		if (strcmp(room_strings[i], "END") == 0)
			break;
		if (strcmp(droom, room_strings[i]) == 0)
			{
				to_room = rooms[i];
				found = 1;
			}
	}
	if (!found)
	{
		printf("I don't know where that is.");
		return;
	}
	if (strcmp(playerPtr->current_room->room_name,droom) == 0)
	{
		printf("You're already here.");
		return;
	}
	if (strcmp(playerPtr->current_room->room_name, "bedroom") == 0)
	{
		if (playerPtr->has_backpack == 0)
		{
			printf("I should [take] my backpack before I go.");
			return;
		}
	}
	for (int i = 0; ;i++)
	{
		if (strcmp(playerPtr->current_room->connected_rooms[i], to_room->room_name) == 0)
		{
			connected = 1;
			break;
		}
		if (strcmp(playerPtr->current_room->connected_rooms[i], "END") == 0)
		{
			break;
		}
	}
	if (!connected)
	{
		printf("I can't get to the %s from here.", to_room->room_name);
		return;
	}
	playerPtr->current_room = to_room;
	printf("\033[2J");
	printf("%s\n", playerPtr->current_room->entrance_msg);
	printf("Press enter to continue.");
}

void look(character* playerPtr)
{
	printf("\033[2J");
	printf("%s\n", playerPtr->current_room->look_msg);
}
void note(character* playerPtr)
{
	static int notes_read = 0;
	for (int i = 0; i < playerPtr->inventory_size; i++)
	{
		if (playerPtr->inventory[i] != NULL && strcmp(playerPtr->inventory[i], "note") == 0)
		{
			notes_read++;
			playerPtr->inventory[i] = NULL;
		}
	}
				
	if (notes_read == 0)
	{
		printf("Read what?");
		return;
	}

	printf("\033[2J");
	int note_reader = 1;
	do
	{
		switch (note_reader)
		{
			case 1:
				printf("Hello\n");
				break;
			case 2:
				printf("You're the greatest, you know that?\n");
				break;
			case 3:
				printf("I've been watching\n");
				break;
			case 4:
				printf("is that weird? I didn't mean for it to be weird.\n");
				break;
			case 5:
				printf("anyway. I want to meet you!\n");
				break;
			case 6:
				printf("I'm pretty sure you can't find anyone else to talk to you, anyway.\n");
				break;
			case 7:
				printf("Do you know where I am? You have to [goto] a very specific room from your bedroom\n");
				break;
			case 8:
				printf("You can find it. Try the first letter of all the notes I've left you. :) see you soon\n");
				break;
		}
		note_reader++;
	} while (note_reader <= notes_read);
}
#endif // FUNC_H
