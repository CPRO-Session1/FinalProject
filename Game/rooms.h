#ifndef ROOMS_H
#define ROOMS_H
#include <stdio.h>
#include "func.h"
#include <string.h>

/* SET ROOMS -----------------------------------------------------------------*/
		/* SET START --------------------------------*/
room start = {"start", {"bedroom", "END"}}; 
room * startPtr = &start;
strcpy(start.description , "C Project. [goto] the bedroom to start.");
		/* SET START --------------------------------*/

		/* SET BEDROOM --------------------------------*/
room bedroom = {"bedroom", {"start", "yard", "END"}, {"note", "key", "backpack"},{},{},{},3};
room * bedroomPtr = &bedroom;
strcpy(bedroom.entrance_msg, "I should [look] around.");
strcpy(bedroom.description, "My bedroom. Nothing special. ");
strcpy(bedroom.look_msg, "It's already late.\nI should [goto] the yard soon.\n");
	/* SET BEDROOM --------------------------------*/
		/*SET YARD----------------------------------*/
room yard = {"yard", {"bedroom", "park", "END"},{"note"},{},{},{},1};
room * yardPtr = &yard;
strcpy(yard.description, "I haven't mowed the lawn in a while. ");
strcpy(yard.look_msg, "There's nobody here.\nWait\nI think I see someone in the park.\nI could try to [yell] or go see who it is.");
		/*SET YARD----------------------------------*/

	/*SET PARK-------------------------------------------------*/
room park = {"park", {"QUIT", "END"}, {},{},{},{},4};
strcpy(park.description, "this is park. hi");

room park_ran = park;
strcpy(park_ran.description, "this is park1. usuk");
room * parkPtr = &park;
	/*SET PARK-------------------------------------------------*/

room quit = {"QUIT"};
room *quitPtr = &quit;

room * roomPtr_list[5] = {startPtr, bedroomPtr, yardPtr, parkPtr, quitPtr};
char * room_list_strings[6] = {"start", "bedroom", "yard", "park", "QUIT", "END"};
	/* SET ROOMS -----------------------------------------------------------------*/
#endif // ROOMS_H
