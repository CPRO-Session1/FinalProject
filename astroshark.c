/*Sean Kee*/
/*Astroshark v0.0.3*/

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void createShip(struct SDL_Window **gameWindow, struct SDL_Renderer **renderer, int *w, int *h, struct SDL_Texture **spriteTexture) {  	/*Function to create ship, takes in points because those values have to be used in the game(Double pointers are for pointers to struct pointers)*/
	SDL_Surface *tempSurface = IMG_Load("resources/playerShip_spritesheet_320x480.png");												/*Creates a temporary surface and loads the spritesheet*/
	*spriteTexture = SDL_CreateTextureFromSurface(*renderer, tempSurface);																/*Sets the texture to the spritesheet on the tempSurface*/
	SDL_FreeSurface(tempSurface);																										/*Frees the space allocated to the tempSurface*/
	SDL_QueryTexture(*spriteTexture, NULL, NULL, w, h);																					/*Sets the width and height of the dstrect to the sprite's texture, essentially binding the texture to the dstrect*/
}

int initializeAstroshark(int *debug) {																				/*Function for initalizing Astroshark*/
	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) !=0) { 																/*Initalizes SDL while testing if it was successful*/
		printf("\n\n***ERROR: Unable to initalize SDL: %s\nEND ERROR***\n", SDL_GetError());
		*debug = 1;
		return 1;
	}
	
	char windowTitle[18] = {"Astroshark  v0.0.3"}; 																	/*Title of the window*/
	SDL_Window *gameWindow; 																						/*Declares the gameWindow(pointer) with datatype SDL_Window*/
	gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0); 		/*Createshttp://stackoverflow.com/questions/21007329/what-is-a-sdl-renderer window at the location of gameWindow pointer*/
	
	if (gameWindow == NULL) { 																						/*Tests to see if window creation was successful or not */
		printf("\n\n***ERROR: Could not create window: %s\nEND ERROR***\n", SDL_GetError());
		*debug = 1;
		return 1;
	}

	Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;										/*Creates Renderer flags*/
	SDL_Renderer *renderer = SDL_CreateRenderer(gameWindow, -1, render_flags);												/*Creates Renderer*/
	if(renderer == NULL) {
		printf("\n\n***ERROR: Failed to create renderer: %s\nEND ERROR***\n", SDL_GetError());
		*debug = 1;
		return 1;
	}

	SDL_Rect playerShip_dstrect;																					/*Creates ship's destination rectangle, a.k.a. the ship "object"*/
	SDL_Rect playerShip_srcrect = {0, 0, 320, 480};																	/*TEMPCreates Source rectangle, to highlight the area in which the correct sprite on the spritesheet is located*/
	SDL_Texture *playerShipTexture;																					/*Creates the Ship's texture*/
	createShip(&gameWindow, &renderer, &playerShip_dstrect.w, &playerShip_dstrect.h, &playerShipTexture);			/*Sends the addresses the necessary structs and data to createShip()*/

	playerShip_dstrect.w -= 1600;																					/*Resizes the width of the rectangle to the size of a single sprite*/
	playerShip_dstrect.w /= 10;																						/*Scales down the ship*/
	playerShip_dstrect.h /= 10;

	playerShip_dstrect.x = 0;																						/*TEMPSets location to 0, 0, the top left corner*/
	playerShip_dstrect.y = 0;

	int close_requested = 0;


	int playerShip_moveForward = 0;
	int playerShip_moveLeftStrafe = 0;
	int playerShip_moveBackward = 0;
	int playerShip_moveRightStrafe = 0;

	int playerShip_xChange = 0;
	int playerShip_yChange = 0;

	int playerShip_actionShoot = 0;
	while (!close_requested) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					close_requested = 1;
					break;
				case SDL_KEYDOWN:
					switch(event.key.keysym.scancode) {
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							playerShip_moveForward = 1;
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							playerShip_moveLeftStrafe = 1;
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							playerShip_moveBackward = 1;
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							playerShip_moveRightStrafe = 1;
							break;
						case SDL_SCANCODE_SPACE:
							playerShip_actionShoot = 1;
							break;
					}
					break;
				case SDL_KEYUP:
					switch(event.key.keysym.scancode) {
						case SDL_SCANCODE_W:
						case SDL_SCANCODE_UP:
							playerShip_moveForward = 0;
							break;
						case SDL_SCANCODE_A:
						case SDL_SCANCODE_LEFT:
							playerShip_moveLeftStrafe = 0;
							break;
						case SDL_SCANCODE_S:
						case SDL_SCANCODE_DOWN:
							playerShip_moveBackward = 0;
							break;
						case SDL_SCANCODE_D:
						case SDL_SCANCODE_RIGHT:
							playerShip_moveRightStrafe = 0;
							break;
						case SDL_SCANCODE_SPACE:
							playerShip_actionShoot;
							break;
					}
					break;

			}
		}
		if (playerShip_moveForward == 1) {
			playerShip_dstrect.y -= 10;
			playerShip_srcrect.x = 640;
		}
		if (playerShip_moveBackward == 1)
			playerShip_dstrect.y += 10;
		if (playerShip_moveLeftStrafe == 1)
			playerShip_dstrect.x -= 5;
		if (playerShip_moveRightStrafe == 1)
			playerShip_dstrect.x += 5;

		if (playerShip_moveForward == 0) {
			playerShip_srcrect.x = 0;
			playerShip_yChange = 0;
		}
		if (playerShip_moveBackward == 0)
			playerShip_yChange = 0;
		if (playerShip_moveLeftStrafe == 0)
			playerShip_yChange = 0;
		if (playerShip_moveRightStrafe == 0)
			playerShip_yChange = 0;

		
//		playerShip_dstrect.x = 30*(playerShip_xChange);
//		playerShip_dstrect.y = 30*(playerShip_yChange);
		
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, playerShipTexture, &playerShip_srcrect, &playerShip_dstrect);
		SDL_RenderPresent(renderer);


		SDL_Delay(1000/30);
		
	}









	SDL_Delay(3000);

	SDL_DestroyTexture(playerShipTexture);																			/*Destroys Texture*/
	SDL_DestroyRenderer(renderer);																					/*Destroys Renderer*/
	SDL_DestroyWindow(gameWindow); 																					/*Destroys the window that gameWindow is pointing to*/
	SDL_Quit(); 																									/*Cleans up and quits out of SDL*/

	*debug = 0;
}

int main(void) {
	int debug; 																										/*Variable for testing if initialization was successful*/
	initializeAstroshark(&debug); 																					/*Initalizes Astroshark while referencing the debug variable*/
	if (debug == 1)
		return 1;
	else
		return 0;
}
