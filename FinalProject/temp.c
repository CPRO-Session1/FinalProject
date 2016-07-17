//Test Version

//Quiz Show game in C for Final Project at Columbia HSP 2016

//Idea of how to set up the code: 

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


void help(){ //gives instructions of the game
	system("clear");
	printf("\n\n                      Instructions:");
	printf("\n ------------------------------------------------------");
	printf("\n ................... Ava's Quiz Show ....................");
	printf("\n >> You have to be able to answer 11 questions.");
	printf("\n >> All of the questions require fill-in answers.");
	printf("\n >> This game is NOT case sensative, so all answers have to");
	printf("\n    have the beginning of words be uppercase.");
	printf("\n >> If the question asks for a number, answer with a number");
	printf("\n >> The maximum number of points a you can get is 11.");

	printf("\n >> You will not be penalized for getting answers incorrect");

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
	char guess[25]; //the contestant's guess
	FILE *questions = fopen(filename, "r");
	FILE *answers = fopen(answersFile, "r"); 
	int i;
	int e;
	const int num_ques=10;
	int score;
	char choice; 
	int countr =0;
	char userinput[20];
	char playername[20];
	char loop='y';
	//while (loop == 'y');
	mainhome:
	system("clear"); //source: stackoverflow.com
	printf("\t\t\tC PROGRAM QUIZ GAME\n");
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



	//printf("\n\n\n Press Y  to start the game!\n");
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


	for (e=0; e < num_ques; e++) //loop to go through each question in the text file
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
				//continue;
			}
			else if (guess!=ans_arr)
			{
				printf("Your guess was incorrect.\n\n\n");
				//continue;
	                }
	                else 
			{
	                	printf("You ran out of questions.");
	                	//break;
	                }
		}
	}
		

	fclose(questions); 
	fclose(answers);
	//return 0;


	score:
	system("clear");
	score=countr;
	//printf("* DIAGNOSTIC -- countr is %d\n",countr);
	//printf("* DIAGNOSTIC -- score is %d\n",score);
	if(score>0 && score<=10){
		printf("\n\n\t\t************* CONGRATULATIONS **************");
		printf("\n\t You won %d points! \n",score);goto go;}

	else if(score==11){ //highest score possible
		printf("\n\n\n \t\t*********** Nice Job!! ***********");
		printf("\n\t\t\t\t You are the champion!!!!!!!!!");
		printf("\n\t\t\t  You won %d points! \n",score);
		printf("\t\t Thank You!!");
	}
	else{
		printf("\n\n\t******** You did not win any points ********");
		printf("\n\t\t  Thanks for playing!. \n");
		printf("\n\t\t Better luck next time! \n");goto
		go;
	}

		go:
		//puts("\n\n Press Y if you want to play again");
		//puts("Play again next time!\n");
	//printf("Do you want to play again? (y/n)"); //source: my Assignment 4 hangman.c
	//scanf("%c", &loop);
		//if (loop != 'y')
		//loop; 'n';

	return 0;
	if (toupper(getchar())=='Y')
		goto mainhome;
	/*else{
		edit_score(score,playername);
		goto mainhome;
	}*/
	}
//}
//}//this was put here after the cases were commented out.
//}
