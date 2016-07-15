#include "func.c"

int main()
{
	/* SET ROOMS -----------------------------------------------------------------*/
	/* SET START --------------------------------*/
	room start = {"start", {"bedroom","QUIT", "END"},{},{},{},{},0}; 
	room * startPtr = &start;
	strcpy(start.description , "Rapper Quest.\n[goto] the bedroom to start.\ntype QUIT to exit at any time.");
	strcpy(start.look_msg, "Get out of here already");
	/* SET START --------------------------------*/

	/* SET BEDROOM --------------------------------*/
	room bedroom = {"bedroom", {"yard", "kitchen", "QUIT", "END"}, {"note", "homework assignment", "backpack"},{},{},{},3};
	room * bedroomPtr = &bedroom;
	strcpy(bedroom.entrance_msg, "I walk to my bedroom and sit on the bed.\nI should [look] around.");
	strcpy(bedroom.description, "My bedroom. Nothing special. My bed is still undone.");
	strcpy(bedroom.look_msg, "Someone tore up all my notes!\nI should go look for them.\nI should [take] my stuff first.");
	/* SET BEDROOM --------------------------------*/
	/*SET YARD----------------------------------*/
	room yard = {"yard", {"bedroom", "park", "kitchen", "shack", "QUIT", "END"},{"note","garden gnome"},{},{},{},2};
	room * yardPtr = &yard;
	strcpy(yard.entrance_msg, "I walk outside.");
	strcpy(yard.description, "I haven't mowed the lawn in a while. ");
	strcpy(yard.look_msg, "There's nobody here.\nWait, I think I see someone in the park.\nI could try to [yell] or go see who it is.");
			/*SET YARD----------------------------------*/

	/*SET PARK - there are two versions of park, one with the man and one scared away. Going to park will make you lose.*/
	room park = {"park", {"QUIT", "END"}, {},{},{},{},1};
	strcpy(park.entrance_msg, "I walk to the park. I try to say hello to the man here.");
	strcpy(park.description, "There's a man here. Frightened,\nhe pulls out a knife and stabs me."); 
	strcpy(park.look_msg, "Oh. He's still stabbing me.\nI'm gonna die pretty soon.");

	room park_ran = {"park", {"yard", "treehouse", "QUIT", "END"}, {"note", "dog poo"}, {},{},{}, 2};
	strcpy(park_ran.entrance_msg, "I walk to the park.");
	strcpy(park_ran.description, "The park looks nice today.\nThe birds are chirping,\nsun is shining.");
	strcpy(park_ran.look_msg, "Who didn't clean up?");
	room * parkPtr = &park;
	/*SET PARK-------------------------------------------------*/

	/*SET KITCHEN -- dog poo is required to go to the kitchen. */ 
	room kitchen = {"kitchen", {"bedroom", "yard", "QUIT", "END"}, {NULL, NULL }, {},{},{}, 2};
	strcpy(kitchen.entrance_msg, "I go to my kitchen.");
	strcpy(kitchen.description, "It's so gross in here.\nI should learn to cook sometime soon.");
	strcpy(kitchen.look_msg, "I can probably use the oven to [cook] something.\nIt smells like dog poo in here.");
	room * kitchenPtr = &kitchen;
	/*SET KITCHEN -- dog poo is required to go to the kitchen. */ 

	/*SET SHACK - end of the game once you "rap" in the shack with all notes. */
	room shack = {"shack", {"yard", "QUIT", "END"}, {"note"}, {}, {}, {}, 2};
	strcpy(shack.entrance_msg, "I unlock the shack.\nI have never been in here before, actually.\nKinda sad.");
	strcpy(shack.description, "I can feel the shack's magic energies.\nEither that, or the fumes are getting me high.");
	strcpy(shack.look_msg, "Hmm...");
	room * shackPtr = &shack;

	/*SET QUIT- going to this room is equivalent to losing the game.*/
	room quit = {"QUIT", {},{"participation trophy", "cookie", "cake"},{},{},{},3};
	strcpy(quit.entrance_msg, "Game over!");
	strcpy(quit.description, "This is the room just for losers. Unless you won. Then..good for you.");
	strcpy(quit.look_msg, "Stop looking around. Just leave.");
	room *quitPtr = &quit;
	/*SET QUIT*/
	
	/* room END for the end of the room list just so I don't have to pass a room list size every time */
	room end = {"END"};
	room * endPtr = &end;

	room * roomPtr_list[8] = {startPtr, bedroomPtr, yardPtr, parkPtr, kitchenPtr, shackPtr, quitPtr, endPtr};
	/* SET ROOMS -----------------------------------------------------------------*/

	/* SET PLAYER */
	character player = {NULL,0,6,{"note",NULL,NULL,NULL,NULL,NULL},0,0};
	character * playerPtr = &player;
	player.current_room = startPtr;
	/* SET PLAYER */

	/* SETUP INTERFACE */
	printf("\033[2J");
	print_room_summary(playerPtr);
	printf("\n"); //just for this one line so that everything lines up in the beginning
	
	//GAME LOOP -------------------------------------------------------------------------
	int running = 1;
	while (running)
	{

		/* GET INPUT */
		int n = 3;
		char * command =  malloc(n*sizeof(char));
		printf(">> ");
		fgets(command, n, stdin); //Take command
		size_t last = strlen(command);
		while (command[last-1] != '\n') //stolen from powerpoint
		{
			n *= 2;
			command = realloc(command, n);
			fgets(command+last, n/2, stdin);
			last = strlen(command);
		}
		char *arg1 = (char*) malloc(strlen(command)*sizeof(char)); //Dynamically allocate args to size of command
		char *arg2 = (char*) malloc(strlen(command)*sizeof(char));

		if (strlen(command))
			get_args(arg1, arg2, command);
		free(command);
				/* GET INPUT*/

		printf("\033[2J");
		print_room_summary(playerPtr);

		/* EXECUTE COMMANDS -------------------------------------------------------*/
		if (strcmp(arg1, "goto") == 0)
		{
			moveto(playerPtr, arg2, roomPtr_list);
		}
		else if (strcmp(arg1, "take") == 0)
		{
			take(playerPtr, arg2, playerPtr->current_room, playerPtr->inventory_size);
		}
		else if (strcmp(arg1, "look") == 0 || strcmp(arg1, "think") == 0)
		{
			look(playerPtr);
		}
		else if (strcmp(arg1, "read") == 0 && strcmp(arg2, "note") == 0)
		{
			note(playerPtr);
		}
		else if (strcmp(arg1, "yell") == 0)
		{
			if (playerPtr->current_room == yardPtr && parkPtr != &park_ran)
			{
				printf("\033[2J");
				printf("The man in the park ran away.\n\n\n\nPress enter to continue.\n");
				strcpy(yardPtr->look_msg, "There's nobody around.\nIs it Tuesday today?");
				parkPtr = &park_ran;
				roomPtr_list[3] = &park_ran;
			}
			else if (playerPtr->current_room == &park)
				printf("I try to yell for help, but there's a bug that distracts me.");
			else printf("In the command line, nobody can hear you scream.");
		}
		else if (strcmp(arg1, "cook") == 0 && strcmp(arg2, "dog poo") == 0)
		{
			printf("\033[2J");
			for (int i = 0; i < playerPtr->inventory_size; i++)
			{
				if (playerPtr->inventory[i] != NULL && strcmp(playerPtr->inventory[i], "dog poo") == 0)
				{
					printf("This is so gross...\nOh, something's stuck in here!\nIt's a note.\nAnd a key!\n\n\nPress enter to continue.\n");
					playerPtr->inventory[i] = NULL;
					kitchenPtr->items[0] = "note";
					kitchenPtr->items[1] = "rusty key";
					break;
				}
				else if (i < playerPtr->inventory_size-1);
				else 
				{
					printf("\033[2J");
					print_room_summary(playerPtr);
					printf("I don't have any dog poo left to cook :(\n");
				}
			}
		}
		else if (strcmp(arg1, "rap") == 0)
		{
			if (playerPtr->notes_read < 5)
				printf("I don't know any lyrics!");
			else if (playerPtr->current_room != shackPtr)
				printf("My rhythm isn't that good. Plus the acoustics in the %s aren't too great.", playerPtr->current_room->room_name);
			else 
			{
				running = 0;
				printf("The shack's energies pour into me as I give the greatest rap ever delivered.\nTo myself.\nIn a shack.\n");			}
		}
		else if (strcmp(arg1, "") == 0);
		else if (strcmp(arg2, "QUIT") == 0 || strcmp(arg1, "QUIT") ==  0 )
			running = 0;
		else (printf("I don't know how to do that."));
		/* COMMANDS -------------------------------------------------------*/
		free(arg1);
		free(arg2);
		
		if (playerPtr->current_room == quitPtr)
			running = 0;
		printf("\n");

	}
	return 0;
}
