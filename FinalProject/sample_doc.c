//This is for checking the code of the question-answer section in quiz_game code

#include <stdio.h>
#include <string.h>

int main (void){
	char filename[] = "questions.txt"; //opens the questions
	char answersFile[]= "answer.txt"; //opens the answers
	char ques_arr[1000]; //questions array
	char ans_arr[100]; //answers array
	char guess[25]; //the contestant's guess
	FILE *questions = fopen(filename, "r");
	FILE *answers = fopen(answersFile, "r"); 
	int i;
	int e;
	const int num_ques=5;
	for (e=0; e < num_ques; e++){
	
		printf("Type in your answer to the following question:\n");
		
		if(fgets(ques_arr, sizeof(ques_arr), questions)!= NULL){ //read 1 line from file
			printf("%s\n", ques_arr);  
		}

    //source: http://stackoverflow.com/questions/8328464/compare-user-input-with-text-file-in-c
		if (fgets(ans_arr, sizeof(ans_arr), answers) == NULL){
			fprintf(stderr,"Error while reading file\n");
			return -1;
		}
	
		for (i=0; i < 1; i++){    //Loop for questions asking
			//printf("%d\n",i);
			//fprintf(stderr,"the answer: %s\n", ans_arr);
			//printf("Please guess the word: \n");
			fgets(guess, sizeof(guess), stdin);
			
			fprintf(stderr,"you answered %s\n",guess);
			if (strcmp(ans_arr, guess) == 0){
				printf("Your guess was correct\n\n");
				//continue;
			}
			else if (guess!=ans_arr){
				printf("Your guess was incorrect.\n\n\n");
				//continue;
	                }
	                else {
	                	printf("You ran out of questions");
	                	//break;
	                }
		}
	}
		

	fclose(questions); 
	fclose(answers);
	return 0;
}

	
