/* Yael Kelmer. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int number;
	char fill;
	char shape;
} card; /*this is the struct that formats a card */

/*this function generates the deck of cards for SET and puts them in an array */
void generateDeck (card arrayCards[]) {
	int counter = 0;
	int number;
	int fill;
	int shape;
	char fillArray[] = {'e', 's', 'f'};
	char shapeArray[] = {'t', 's', 'c'};
	for (number = 0; number < 3; number++) {
		for (fill = 0; fill < 3; fill++) {
			for (shape = 0; shape < 3; shape++) {
				card a = {number, fillArray[fill], shapeArray[shape]};
				arrayCards[counter] = a;
				counter++;
			}
		}
	}
}

/*this function shuffles the deck of cards so that the player is not playing the same game if he or she chooses to play more than once */
void shuffleCards (card arrayCards[]) {
	int i;
	int rand1;
	int rand2;
	card placeHolder;
	srand(time(NULL));
	for (i = 0; i < 100; i++) {
		rand1 = rand() % 27;
		rand2 = rand() % 27;
		placeHolder = arrayCards[rand1];
		arrayCards[rand1] = arrayCards[rand2];
		arrayCards[rand2] = placeHolder;
	}
}

/*this function displays a card */
void displayCard (card a) {
	printf ("{%d, %c, %c} ", a.number, a.fill, a.shape);
}

/*this function prints the cards on the board such that there are only three in a row */
void cardsOnBoard (card arrayCards[], int display) {
	int i;
	int counter = 0;
	for (i = 0; i < display; i++) {
		printf ("%d: ", i);
		displayCard(arrayCards[i]);
		counter++;
		if (counter == 3) {
			printf ("\n");
			counter = 0;
		}
	}
}

/*this function checks if the three cards that the user selected do in fact make a set */
int checkSet (card a, card b, card c) {
	int check = 0;

	if (a.number != b.number && a.number != c.number && b.number != c.number) {
		check++;
	}
	else if (a.number == b.number && a.number == c.number) {
		check++;
	}
	else {
		return 0;
	}

	
	if (a.fill != b.fill && a.fill != c.fill && b.fill != c.fill) {
		check++;
	}
	else if (a.fill == b.fill && a.fill == c.fill) {
		check++;
	}
	else {
		return 0;
	}


	if (a.shape != b.shape && a.shape != c.shape && b.shape != c.shape) {
		check++;
	}
	else if (a.shape == b.shape && a.shape == c.shape) {
		check++;
	}
	else {
		return 0;
	}

	return check;
}

int main ()
{
	card arrayCards[27]; 
	int display = 9;
	int available = 27; 
	int amountOfSets = 0;
	generateDeck (arrayCards);
	shuffleCards(arrayCards);

	printf ("Welcome to SET! This is how the game works: There will be 9 cards displayed on your screen. Each card has 3 characteristics: a number(1, 2, 3), a fill(e (empty), f (full), s (striped) ), and a shape(c (circle), s (square), t (triangle) ). These cards can be combined to form a SET. What is a SET you may ask? A SET is three cards, where each characteristic, when looked at individually, is either all the same OR all different. For example, a SET, would be three cards who have all different numbers, all different fills, and all the same shape. Your goal is to find as many SETs as you can! When you spot a set type in the location of each card (the location is the number next to the description of the card). Type the first number then press enter, type the second number then press enter, and lastly type the third number then press enter. If you think there are no SETs on the board, you can request more cards. If you are readytype 'g' and press enter. Good luck!\n"); 
	char ready;
	scanf (" %c", &ready);
	if (ready == 'g' || 'G') {
		while (1)
			printf ("These are the cards on the board:\n"); 
			cardsOnBoard(arrayCards, display);
			/*this conditional statement asks the user if they want more cards as long as there are still more cards available. if the user says yes, more cards are added. */
			if (display < available) {
				printf ("\n");
				printf ("Do you want more cards (Y/N): ");
				char moreCards;
				scanf (" %c", &moreCards);
				if (moreCards == 'Y' || moreCards == 'y') {
					display += 3;
					if (display >= available) {
						display = available;
					}
					printf ("These are the cards on the board:\n");
					cardsOnBoard(arrayCards, display);
				}
				else if (moreCards == 'N' || moreCards == 'n') {
				}
				else {
					printf ("\nThat is not a yes or no answer, so I am assuming that is a no.\n");
				}
			}
			printf ("\n");
			printf("Which three cards do you think make a set?\n\n"); 
			int a;
			int b; 
			int c;
			scanf ("%d %d %d", &a, &b, &c);
			if (a >= 0 && a < display && 
		    	b >= 0 && b < display && 
		    	c >= 0 && c < display &&
		    	a != b && a != c && b != c) {
				int check;
				check = checkSet (arrayCards[a],
						  arrayCards[b], 
						  arrayCards[c]);
				if (check) {
					amountOfSets++;
					printf ("\nThat's a SET! Nice job!\n\n");
					arrayCards[a] = arrayCards[available - 1];
					available--;
					if (available < display) {
						display--;
					}
					arrayCards[b] = arrayCards[available - 1];
					available--;
					if (available < display) {
						display--;
					}
					arrayCards[c] = arrayCards[available - 1];
					available--;
					if (available < display) {
						display--;
					}
				}
				else {
					printf ("\nThat's not a SET. Try again!\n\n");
				}
			}
			else {
				printf("\nThat is invalid. Try again!\n\n");
			}
			if (available - display == 0) {
				printf ("Do you want to stop the game? Y/N?\n");
				char x;
				scanf (" %c", &x);
				if (x == 'Y' || x == 'y') {
					printf ("You found %d SETs! Congratulations! Thanks for playing!\n", amountOfSets);
					exit(1);
				}
			}
		}
	
	}

