#include "func.h"
#include <stdio.h>
#include <string.h>

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
			if (room.items[i] != NULL) 
			{
				printf("a %s, ", room.items[i]);
				saw = 1;
			}
			else if (i == size-1 && room.items[size-1] != NULL) 
			{
				printf("and a %s.\n", room.items[size-1]);
				saw = 1;
			}
		}
		if (!saw) printf("nothing.\n\n");
	}
}

void do_command(char* command)
{
	char * commandPtr = command;
	char * command_list[8] = {"look", "open", "goto", "take", "help", "yell", "put", "drop"};
	char arg1[sizeof(command)];
	char arg2[sizeof(command)];

	for(int i = 0; *commandPtr != ' ' && i <= (int) sizeof(command); i++)
	{
		arg1[i] = *commandPtr;
		commandPtr++;
	}
	for(int i = 0; *commandPtr != '\0'; i++)
	{
		commandPtr++;
		arg2[i] = *commandPtr;
	}
	arg2[strlen(arg2)] = '\0';

	printf("ARGS: %s|%s|\n", arg1, arg2);
	while (getchar() != '\n');


	for (int i = 0; i < (int) (sizeof(command_list)/sizeof(command_list[0])); i++)
	{
		if (strcmp(arg1, command_list[i]) == 0)
		{
			printf("Found a command! %s\n", command_list[i]);	
		}
	}

}
int main()
{
	int running = 1;
	character player;

	/* SET START --------------------------------*/
	room start; 
	strcpy(start.description , "Game Name. [goto] the bedroom to start.");
	/* SET START --------------------------------*/

	/* SET BEDROOM --------------------------------*/
	room bedroom = {"Bedroom", {"pencil", "towel", "backpack"}};
	strcpy(bedroom.entrance_msg, "You wake up.");
	/* SET BEDROOM --------------------------------*/

	player.current_room = start;

	while (running)
	{
		print_room_summary(player.current_room);
		char command[100];
		scanf("%[^\n]", command);
		do_command(command);

	}
	return 0;
}
