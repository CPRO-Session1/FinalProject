#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "func.h"



void get_args(char* arg1 , char * arg2, char* command) // The input sanitizer, it will return the first arg as the first word, the second as all words after
{
	int i = 0, j = 0;
	for(;i <= (int) strlen(command); i++) //Iterate through commands
	{
		arg1[i] = command[i]; //Copy first word to char
		if (command[i] == '\n' || command[i] == ' ')//When you reach a space or newline, replace with end char
		{
			arg1[i] = '\0';
			i++;
			break;
		}
	}
	for(; command[i] != '\0'; j++, i++) // repeat for second arg
	{
		arg2[j] = command[i];
		if (command[i] == '\n')
		{
			arg2[j] = '\0';
			break;
		}
	}
}

void print_room_summary(character *playerPtr) // This prints the "HUD" for the player: inventory, items in the room
{
	int saw = 0, is_last = 0;
	printf("|%s|\n", playerPtr->current_room->room_name);
	printf("%s\n\n", playerPtr->current_room->description);
	
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

	if (!playerPtr->has_backpack) 
	{
		printf("\n\n");
		return;
	}
	printf("I have: ");
	for (int i = 0;i < playerPtr->inventory_size; i++) 
	{
		if (playerPtr->inventory[i] == NULL) continue;
		printf("|%s| ", playerPtr->inventory[i]);
	}
	printf("\n\n");
}
void take(character * playerPtr, char * item, room * roomPtr, int room_items_size) // Transfers an item in the room to inventory. Didn't know where else to put the backpack interaction
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
					printf("I can hold things now.\nThere's a note still here! I can [read note].\n\n\n\n");
					printf("Press enter to continue.\n");
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
void moveto(character*playerPtr, char *droom, room * rooms[]) //Moves character to a connected room. Converts strings to rooms first. Also where I put the interactions with rooms
{
	int connected = 0, found = 0;
	room *to_room;
	for (int i = 0;;i++)
	{
		if (strcmp(rooms[i]->room_name, "END") == 0)
			break;
		if (strcmp(droom, rooms[i]->room_name) == 0)
		{
			to_room = rooms[i];
			found = 1;
		}
	}
	for (int i = 0;;i++)
	{
		if (found && strcmp(playerPtr->current_room->connected_rooms[i], to_room->room_name) == 0)
		{
			connected = 1;
			break;
		}
		if (strcmp(playerPtr->current_room->connected_rooms[i], "END") == 0) //If we've reached end of list
		{

			if (i-1 == 0) //If there's only one connected room
			{
				moveto(playerPtr, playerPtr->current_room->connected_rooms[0], rooms);//move there instead
				return; //cancel original moveto
			}
			break;
		}
	}

	if (!found) //no rooms found	
	{
		if (strlen(droom) != 0) //if they wanted to move somewhere
			printf("I don't know where that is.");

		return;
	}

	if (strcmp(playerPtr->current_room->room_name,droom) == 0) //already in room
	{
		printf("You're already here.");
		return;
	}
	if (!connected) //room not connected
	{
		printf("I can't get to the %s from here.", to_room->room_name);
		return;
	}
	if (strcmp(playerPtr->current_room->room_name, "bedroom") == 0 && playerPtr->has_backpack == 0) //hard coded
	{
		printf("I should [take] my backpack before I go.");
		return;
	}
	if (strcmp(to_room->room_name, "kitchen") == 0) //hard coded
	{
		for (int i = 0; i < playerPtr->inventory_size; i++)
		{
			if (playerPtr->inventory[i] != NULL && strcmp(playerPtr->inventory[i], "dog poo") == 0)
				playerPtr->has_poo = 1;
		}
		if (!playerPtr->has_poo)
		{
			printf("I don't feel like going to the kitchen without something to cook.");
			return;
		}
	}
	if (strcmp(to_room->room_name, "shack") == 0) //hard coded again
	{
		int has_rkey = 0;
		for (int i = 0; i < playerPtr->inventory_size; i++)
		{
			if (playerPtr->inventory[i] != NULL && strcmp(playerPtr->inventory[i], "rusty key") == 0)
				has_rkey = 1;
		}
		if (!has_rkey)
		{
			printf("I can't get into the shack without a key.");
			return;
		}
	}
	playerPtr->current_room = to_room;
	printf("\033[2J");
	printf("%s\n\n\n\n", playerPtr->current_room->entrance_msg);
	printf("Press enter to continue.\n");
}

void look(character* playerPtr) // Prints look statement. This function was not needed honestly
{
	printf("\033[2J");
	printf("%s\n\n\n\n", playerPtr->current_room->look_msg);
	printf("Press enter to continue.\n");
}
void note(character* playerPtr) // The note system. I could've just iterated but I already had the switch statements set up
{
	for (int i = 0; i < playerPtr->inventory_size; i++)
	{
		if (playerPtr->inventory[i] != NULL && strcmp(playerPtr->inventory[i], "note") == 0)
		{
			playerPtr->notes_read++;
			playerPtr->inventory[i] = NULL;
		}
	}
				
	if (playerPtr->notes_read == 0)
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

				printf("    MAP:                     |"); printf("               MY SICK RAP:\n");
				break;
			case 2:
				printf("BEDROOM   -> YARD<-          |"); printf("but for me to rap like a computer must be in my genes\n");
				break;
			case 3:
				printf("   |     /     |   \\         |"); printf("I got a laptop in my back pocket\n");
				printf("KITCHEN<-    PARK   ->SHACK  |"); printf("my pen'll go off when I half cock it\n");
				break;
			case 4:
				printf("                        |    |"); printf("got a fat knot from that rap profit\n");
				break;
			case 5:
				printf("                        |    |"); printf("made a living and a killing off it\n");
				break;
			case 6:
				printf("                    RAP HERE |"); printf("                            --\"Gap Rod\"");
			  
				break;
		}
		note_reader++;
	} while (note_reader <= playerPtr->notes_read);
	printf("\n\n\nPress enter to continue\n");
}
