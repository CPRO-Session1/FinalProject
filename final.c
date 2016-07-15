//Emma ladouceur
//Create your own adventure game trying to get to class
//Finished
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //for the random


typedef struct player { // this is the initial player structure for the beginning where you'll input your name and age.

	char name[100];

} player; //Just for the player name input

int riddle(){//Here i use a loop and the user has to answer a riddle in order to move forward with their commute. I have two arrays one with the answer and one with there guess. While their answer is incorrect it keeps running, but once they get it right it breaks!
	const char *riddles[3]; //The array of riddles
	riddles[0] = "What number do you get when you multiply all of the numbers on a phone keypad?\n\n";
	riddles[1] = "If two hours ago it was as long after one o'clock in the afternoon as it was before one o'clock in the morning, what time would it be now (just answer an integer)\n\n";
	riddles[2]= "If it takes 5 machines 5 minutes to make 5 widgets, how many minuteswill it take for 100 machines to make 100 widgets? (answer withan integer)\n\n";


	int answers[3] = {0,9,5};        //The answer options. Each lines up with with a specific riddle in its spot
	int guess; //What the user puts in
	srand(time(NULL));
	int n = rand() % 2 + 1;         //This generates a  random number so that when you run through the game again you don't get the same riddle. There is an array of three riddles. And the answers that match them.


	printf("\n\n\nUh oh.... looks like you've run into a street magician and before you keep going you have to answer his riddle... once you answer it you can keep going with your commute. Answer quickly because you're alreay running late!\n\n");


	printf("Here's the riddle %s\n", riddles[n]);


	do{
		printf("Enter your answer here: ");
		scanf("%d", &guess);

	}while(guess != answers[n]);

	printf("Correct! You can now continue your commute\n");

}

//For scope reaseason my last choice go first so that my second choices and first choices of the user can call on those choices, The way this works is the 3rd choice is first and then the second and finally the first. ONLY the first choice is called in the main because each subsequent choice calls on the next choice based on the user's decision of 1 or 2. Here we go. 

//THE LAST DECISION
int final(int finish){ // As I said before the last choice is first because funtions lower down call on it. This function is called in choice2a and 2b twice to finish the game.

	printf("Congratulations! You made it to Columbia with 10 minutes to spare \n\n");


	}	
//CHOICE NUMBER 2 IF THE USER CHOOSES 1
int choice2a(int b){//Okay, so here is what happens if after the first choice the user chooses 1, This functon then runs with the next set of choices. This is called in the function choice1

	int last;
	if (b ==1){
	riddle();
	printf("\n\nNot again!! Your train broke down and now you 5 minutes late. Do you want to 1 take a cab the rest of the way or 2 walk the last 15 blocks.\n1 or 2? \n");
		scanf("%d", &last);
		final(last);
		}
	else if(b==2){

		final(last);

		}	
}

//CHOICE NUMBER 2 IF THE USER CHOICE 2
int choice2b(int c){ // Here is what happens if the user chooses 2 in the first choice. This again provides 2 choices called in choice 1, one of which finishes the game and the other of which asks for 2 choices and then finishes the game.  

	int last;

	if(c==1){

		printf("Awwwww sorry! You're train broke down and you didn't make it to class today. CHSP called your family and you've been suspended for a day. Try again!");

	}	

	else if(c==2){
		riddle();
		printf("\n\nNo! Not again! Your train is not working! Would you like to 1 take a cab the last 15 blocks or 2 walk? \n1 or 2?\n");
	
	scanf("%d", &last);
	final(last);
		}

}
int choice1(int a){ // This is the first choice, so from here it leads to choice 2A and 2B, if you image branches of a tree, this is the first split
	int b, c;

		if(a == 1){
			printf("Oh no! You got on the train up to 42nd street but then it broke down! Now you have two options, 1 walk to time square and take the 1 train to Columbia or 2 get on the M4 bus!\nDo you want option 1 or 2? \n");
		scanf("%d", &b);	
		choice2a(b);
		}

		else if(a==2){
			printf("Uh oh... Looks like your taxi broke down... Now you have the choice to 1 get in an Uber or 2 get on the 1 train to Columbia! Do you want option 1 or 2? \n");
		 scanf("%d", &c); 
		choice2b(c);
		}
}


int main(){ // This is the main function. Not much happens here because each function actually sets off the others like a domino effect. ONLY choice1 is called here as well as the first instruction. This function also gathers the data about the user.
	int a, age;
	char name;
	player p1={name};
	printf("What is your first name? \n");
	scanf("%s", &p1.name);


	printf("Welcome %s to the choice your own adventure. It's your job to get to class as fast as possible. When prompted, press 1 or 2 to answer. Good Luck!\n\n", p1.name);
//CHOICE NUMBER1
	printf("\nYou're at bowling green and it's 9:00-only 1 hour until class. You have the choice of train or cab. For train press 1 and for cab press 2: \n");
	scanf("%d", &a);

	choice1(a); //This is where the program is called and all of the functions work off of it from here
	return 0;
}
