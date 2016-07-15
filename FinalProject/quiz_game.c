//Ava N.'s

//REAL VERSION -- Ava's Quiz Show 
//Columbia HSP FInal Project
//Intro to Programming in C
//Due: July 15, 2016

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void help(){ //gives instructions of the game
	system("clear");
	printf("\n\n                      Instructions:");
	printf("\n ------------------------------------------------------");
	printf("\n ................... Ava's Quiz Show ....................");
	printf("\n >> You have to be able to answer 16 questions correctly.");
	printf("\n >> All of the questions require fill-in answers.");
	printf("\n >> This game is case-sensitive, so all answers have to");
	printf("\n    have the first letter of each word uppercase.");
	printf("\n >> If the question asks for a number, answer with a number.");
	printf("\n >> The maximum number of points a you can get is 11.");

	printf("\n >> You will not be penalized for incorrect answers.");

	printf("\n\n\t**************Good Luck*******************\n\n");
	printf("\n\n\t Press 'enter' to continue to the main menu\n");
}



//start of the game show
int main(void){

	system("clear");
	char filename[] = "questions.txt"; //opens the questions
	char answersFile[]= "answer.txt"; //opens the answers
	char ques_arr[1000]; //questions array
	char ans_arr[100]; //answers array
	char guess[100]; //the contestant's guess
	FILE *questions = fopen(filename, "r");
	FILE *answers = fopen(answersFile, "r"); 
	int i; //variable for loop that checks contestants answers
	int e; //variable for going through the questions.txt file
	const int num_ques=15; //includes number of questions
	char choice;  //main menu variable
	int countr = 0; //score

	mainhome:
	system("clear"); //source: http://stackoverflow.com/questions/15102976/how-to-clear-screen-from-simple-c-program
	//printf("\t\t\tC PROGRAM QUIZ GAME\n");
	printf("\n\t\t________________________________________");

	printf("\n\t\t\t *       WELCOME         *");
	printf("\n\t\t\t *         to            *");
	printf("\n\t\t\t *    AVA'S GAME SHOW    *");  
	printf("\n\t\t      ____*_*_*_*_*_*_*_*_*_*_*_*____");
	printf("\n\t\t________________________________________");
	printf("\n\t\t\t  BECOME THE CHAMPION!!!    ") ;
	printf("\n\t\t________________________________________");
	printf("\n\t\t________________________________________");
	printf("\n\t\t > Press S to start the game");
	printf("\n\t\t > press H for help            ");
	printf("\n\t\t > press Q to quit             ");
	printf("\n\t\t________________________________________\n\n");


	printf("\n\n\t\tAnswers must all begin with an uppercase letter\n\n\n");
//MAIN MENU SELECTION OPTIONS
	choice=toupper(getchar());
	printf("you entered %c\n",choice);

	if (toupper(getchar())=='S')
		goto home;
	else if (choice=='H'){
		printf("you typed in H");
		help();
		getchar();
		goto mainhome;
	}
	else if (choice=='Q'){
		printf("you typed in Q");
		exit(1);

	}


	home:
//HAVING QUESTIONS PRINT ONE AT A TIME
	for (e=0; e < num_ques; e++) //loop to go through each question in text file
	{
		//printf("\nQuestion:");
		printf("\n***Type in your answer to the following question:\n\n");
		
		if(fgets(ques_arr, sizeof(ques_arr), questions)!= NULL)
		{
			printf("%s\n", ques_arr);  
		}

//source: http://stackoverflow.com/questions/8328464/compare-user-input-with-text-file-in-c

		if (fgets(ans_arr, sizeof(ans_arr), answers) == NULL)
		{
			fprintf(stderr,"Error while reading file\n");
			return -1;
		}


	
		for (i=0; i < 1; i++)
		{ 
			// printf("%d\n",i);
			//fprintf(stderr,"DIAGNOSTIC -- the answer: %s\n", ans_arr);
			//printf("DIAGNOSTIC -- GUESS variable is:%s\n", guess);
			fgets(guess, sizeof(guess), stdin);
			
			//fprintf(stderr,"you answered %s\n",guess);

			if (strcmp(ans_arr, guess) == 0)
			{
				printf("Your guess was correct\n\n");
				countr++;
			}
			else if (guess!=ans_arr)
			{
				printf("Your guess was incorrect.\n\n\n");
	                }
	                else 
			{
	                	printf("You ran out of questions.");
	                }
		}
	}
		

	fclose(questions); 
	fclose(answers);

//SHOWING THE CONTESTANT THEIR SCORE - HOW MANY QUESTIONS THEY GOT CORRECT
	score:
	system("clear");
	//score=countr;
	//printf("* DIAGNOSTIC -- countr is %d\n",countr);
	//printf("* DIAGNOSTIC -- score is %d\n",score);
	if(countr>0 && countr<=10){
		printf("\n\n\t\t************* CONGRATULATIONS **************");
		printf("\n\t You won %d points! \n", countr);
	}

	else if(countr==11){ //highest score possible
		printf("\n\n\n \t\t*********** Nice Job!! ***********");
		printf("\n\t\t\t\t You are the champion!!!!!!!!!");
		printf("\n\t\t\t  You won %d points! \n",countr);
		printf("\t\t Thank You!!");
	}
	else{
		printf("\n\n\t******** You did not win any points ********");
		printf("\n\t\t  Thanks for playing!. \n");
		printf("\n\t\t Better luck next time! \n");
	}

		

	return 0;

	
	}
