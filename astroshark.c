/*Sean Kee*/
/*Astroshark v0.0.1*/

#include <stdio.h>
#include <SDL2/SDL.h>

void initializeAstroshark(int *initReturn) {
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) !=0) { 																/*Initalizes SDL while testing if it was successful*/
		printf("\n\n***ERROR: Unable to initalize SDL: %s\nEND ERROR***", SDL_GetError());
		*initReturn = 1;
	}
	
	char windowTitle[18] = {"Astroshark  v0.0.1"}; 																	/*Title of the window*/
	SDL_Window *gameWindow; 																						/*Declares the gameWindow(pointer) with datatype SDL_Window*/
	gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0); 		/*Creates window at the location of gameWindow pointer*/
	
	if (gameWindow == NULL) { 																						/*Tests to see if window creation was successful or not */
		printf("\n\n***ERROR: Could not create window: %s\nEND ERROR***", SDL_GetError());
		*initReturn = 1;
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(gameWindow); 																					/*Destroys the window that gameWindow is pointing to*/
	SDL_Quit(); 																									/*Cleans up and quits out of SDL*/

	*initReturn = 0;
}

int main(void) {
	int initReturn; 																								/*Variable for testing if initialization was successful*/
	initializeAstroshark(&initReturn); 																				/*Initalizes Astroshark while referencing the debug variable*/
	if (initReturn == 1)
		return 1;
	else
		return 0;
}