#include "func.h"



void print_room_summary(character *playerPtr);
void get_args(char**, char**, char*);
void take(character*,char*,room*,int);
void moveto(character*, char*, room**, char**);
void look(character*);
void note(character*);

int main()
{
	int running = 1;

	/* SET ROOMS -----------------------------------------------------------------*/
		/* SET START --------------------------------*/
	room start = {"start", {"bedroom", "END"}}; 
	room * startPtr = &start;
	strcpy(start.description , "C Project. [goto] the bedroom to start.");
		/* SET START --------------------------------*/

		/* SET BEDROOM --------------------------------*/
	room bedroom = {"bedroom", {"start", "yard", "END"}, {"note", "key", "backpack"},{},{},{},3};
	room * bedroomPtr = &bedroom;
	strcpy(bedroom.entrance_msg, "I really have a \nheadache, among other things.\nI should [look] around.");
	strcpy(bedroom.description, "My bedroom. Nothing special. ");
	strcpy(bedroom.look_msg, "It's already late.\nI should [goto] the yard soon.\nWhere is everyone?\n");
		/* SET BEDROOM --------------------------------*/

		/*SET YARD----------------------------------*/
	room yard = {"yard", {"bedroom", "park", "END"},{"note"},{},{},{},1};
	room * yardPtr = &yard;
	strcpy(yard.look_msg, "There's nobody here.\nWait\nI think I see someone\nin the park.\nI could try to [yell] or go see who it is.");
		/*SET YARD----------------------------------*/


	room * room_list[4] = {startPtr, bedroomPtr, yardPtr};
	char * room_list_strings[4] = {"start", "bedroom", "yard", "END"};
	/* SET ROOMS -----------------------------------------------------------------*/

	/* SET PLAYER */
	character player = {NULL,0,6,{NULL,NULL,NULL,NULL,NULL,NULL}};
	character * playerPtr = &player;
	player.current_room = startPtr;
	/* SET PLAYER */

	/* SETUP INTERFACE */
	printf("\033[2J");
	print_room_summary(playerPtr);
	printf("\n\n"); //just for this one line so that everything lines up in the beginning
	
	int guy_ran = 0;
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
		free(command);
		/* GET INPUT*/

		printf("\033[2J");
		print_room_summary(playerPtr);

		/* EXECUTE COMMANDS -------------------------------------------------------*/
		if (strcmp(arg1, "goto") == 0)
		{
			moveto(playerPtr, arg2, room_list, room_list_strings);
		}
		else if (strcmp(arg1, "take") == 0)
		{
			take(playerPtr, arg2, playerPtr->current_room, playerPtr->inventory_size);
		}
		else if (strcmp(arg1, "look") == 0)
		{
			look(playerPtr);
		}
		else if (strcmp(arg1, "read") == 0 && strcmp(arg2, "note") == 0)
		{
			note(playerPtr);
		}
		else if (strcmp(arg1, "yell") == 0)
		{
			if (strcmp(playerPtr->current_room->room_name, "yard") == 0 && guy_ran == 0)
			{
				printf("\033[2J");
				printf("The man in the park ran away.");
				guy_ran = 1;
			}
			else printf("In the command line, nobody can hear you scream.");
		}
		else if (strcmp(arg1, "\n") == 0);
		else (printf("I don't know how to do that."));
		/* COMMANDS -------------------------------------------------------*/

		free(*arg1Ptr);
		free(*arg2Ptr);
		printf("\n\n");
	}
	return 0;
}
