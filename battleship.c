#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*battleship game
  @author Aly Milich
  */

int main(){

	int lives=5, xchoice, ychoice,  score, boardsize, ships = 4, compxarr[4], compyarr[4];

	printf("Welcome to Battleship.\n");
	printf("Please input the size of your board (i.e. enter 4 for a 4x4 board)\n");

	scanf("%d", &boardsize);

	//create board
	char board[boardsize][boardsize];

	int i, j;

	//print board, googled how to do this and found a solution on Stack Overflow
	for(i =0; i<boardsize; i++){
		for(j=0; j<boardsize; j++){
			board[i][j] = '.';
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	printf("You will have 5 chances to find the 4 battleships on your opponent's board. You will lose a life for each incorrect guess and gain a point for each correct guess.\n");

	srand(time(NULL));

	//generate 4 random ships and store the coordinates in an array
	for(i =0; i<4; i++){
		int compx = rand()%boardsize +1;
		compxarr[i] = compx;
		int compy = rand()%boardsize +1;
		compyarr[i] = compy;
	}

	while(lives>0 && ships >0){

		//update board before next turn
		for(i=0; i<boardsize; i++){
			for(j=0; j<boardsize; j++){
				printf("%c", board[i][j]);
			}
			printf("\n");
		}

		printf("Take a guess!\n");
		printf("Input the row you would like to guess.\n");
		scanf("%d", &xchoice);

		printf("Input the column you would like to guess.\n");
		scanf("%d", &ychoice);

		//check if the input is valid, if not ask user to change guess
		if(xchoice > boardsize || ychoice > boardsize){
			printf("Those coordinates are invalid. Please choose values less than or equal to %d\n", boardsize);
			printf("Input the row you would like to guess.\n");
			scanf("%d", &xchoice);
		
			printf("Input the column you would like to guess.\n");
			scanf("%d", &ychoice);
		}

		//check if user hit a ship (if guess is in compx or compy arrays. I tried to do this with a loop and it ended up looping the entire thing and causing lives to decrease by 4 with each guess so i just wrote out the possibilities
		if(xchoice-1 == compxarr[0]|| xchoice-1 == compxarr[1]||xchoice-1 == compxarr[2]||xchoice-1 == compxarr[3] && ychoice-1 == compyarr[0] ||  ychoice-1 == compyarr[1] ||  ychoice-1 == compyarr[2] ||  ychoice-1 == compyarr[3]){
			printf("You hit a ship!\n");
			ships--;
			score++;
			printf("There are %d ships left to find.\n", ships);
			printf("Score: %d\n", score);
			board[xchoice-1][ychoice-1] = 'S';
		}
		else{
			printf("You missed.\n");
			lives--;
			printf("You have %d lives left.\n", lives);
			board[xchoice-1][ychoice-1] = 'X';
		}	

		//user wins if they sink all of the ships
		if(ships == 0){
			for(i=0; i<boardsize; i++){
				for(j=0; j<boardsize; j++){
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
			printf("You won!\n");
		}
	}

	//user loses if they miss 5 times
	if(lives ==0)
		printf("You didn't find all of the battleships. You lose.\n");

	return 0;
} //end main
