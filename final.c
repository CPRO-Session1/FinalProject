#include <stdio.h>
#include <stdlib.h>

void main() {

printf("\n");
printf("\n");

printf("Hello User. You don't know me, but I know you.\n");
printf("I want to play a game.\n");
printf("You are trapped in a dugeon, and you have to escape by making decisions.\n");  
printf("Every move you make is crucial to your life.\n"); 
printf("Know that I'm not lying. Better hurry up.\n");
printf("Live or die, make your choice.\n");
printf("\n");
printf("Enter 1 whenever you think choice 1 is the one you want to go with and do the same for other choices\n");

//introduction of the game//

struct user {

	char user [20];
	char grade [3];
} user_failed, user_succeed;
//a structure that will be used later on to give players their grade//

char goodEnd[] = "Safe and Sound";
char badEnd[] = "Endless Nightmare";
char gameOver[] = "GAME OVER";
char invalidMove[] = "That's not a valid move";
//a few characters that serve different purposes//

int choice1;
int choice2;
int choice3;
int choice4;
int choice5;
int again;
int i;
//a few variables that will be used to receive player's choice//

do { //a do while loop that will terminate the game when requested//

printf("\n");
printf("\n");

printf("You woke up in a small room with the wall painted red. the door is not locked. It seems like you are experiencing a memory loss. You can't recall anything asaide from a voice you heard from a doll with a creepy mask. You are not sure if you cam trust it. What should you do?\n");
printf("1. exit the room.\n");
printf("2. stay in the room.\n");
scanf("%d", &choice1);

//a user will read the text and be given two options where he or she has to enter an integer. The integer will be scanned through scanf and output a following text based on the input integer//

if(choice1 == 1) {
	printf("You left the room and found yourself ended up in a hallway. You have to decide which direction you want to explore. What will your choice be?\n");
	printf("1. left\n");
	printf("2. right\n");
	scanf("%d", &choice2);
	
	if(choice2 == 1) {
		printf("You walked towards the left side of the hallway. Unfortunately, you ran into a creature ten times your size. It seems like he doesn't appreciate outsiders like you.\n");
		printf("%s\n", gameOver);
	}	

	else if(choice2 == 2) {
		printf("You ended up in front of the stairs, you can choose to either go up or down. Also, on your way to the stairs, you found a key. So, would you like to go up or down?\n");
		printf("1. up\n");
		printf("2. down\n");
		scanf("%d", &choice3);
		
		if(choice3 == 1) {
			printf("You walked up the stairs and took a quick glance at the floor you just arrived. You noticed that there are three doors all shut on this floor. The one on the left has a painting of devil on it, while the one on the right has a painting of angel, and the middle one, a painting of a monkey. So, what will your choice be? The angel? The devil? Or... The monkey?\n");
			printf("1. angel\n");
			printf("2. devil\n");
			printf("3. monkey\n");
			scanf("%d", &choice4);

			if(choice4 == 1) {
				printf("God: Where did your humanity go...\n");
				printf("%s\n", gameOver);
			}

			else if(choice4 == 2) {
				printf("Satan: You belong with me!\n");
				printf("%s\n", gameOver);
			}

			else if(choice4 == 3) {
				printf("Thank to Darwin, you made it to the ground! You are now right in front of the gate that separates you from the outside world. Suddenly, you heard the creepy voice again:\n");
				printf("Congragulations, User. I'm really glad that you made it this far. Now, all you have to do is answer one simple question and then I will set you free.\n");
				printf("Do you hate me?\n");
				printf("1. Yes\n");
				printf("2. No\n");
				printf("3. Obviously\n");
				scanf("%d", &choice5);
			
				if(choice5 == 1 | choice5 == 3) {
					printf("Sure\n");
					printf("The gate slowly opened and you finally made it out of the dungeon. In front of you, stood a giant maze and you heard a mechanic sound: \n");
					printf("Welcome to stage 2\n");
					printf("BAD END: %s\n", badEnd); //char badEnd is used here//
				}

				else if(choice5 == 2) {
					printf("Awwwwwwwwwwwwwwwwwww\n");
					printf("The gate slowly opened and you finally made it out of the dungeon. In front of you, is the park that you walk around every afternoon. Right after you step on to the ground, the entrance closed and disappeared as if it never existed. You are safe now.\n");						  
					printf("GOOD END: %s\n", goodEnd); //char goodEnd is used here//
					struct user user_succeed; //struct user is applied here to print out the username and grade//
					strcpy(user_succeed. user, "User");
					strcpy(user_succeed. grade, "A+");
					printf("name: %s\n", user_succeed. user );
					printf("grade: %s\n", user_succeed. grade );
				}

				else {
					printf("%s\n", invalidMove); //else is used to ensure if the player input a variable other than 1 and 2, it will notify them that the input is invalid along with char invalidMove//
				}
	
 			}
			
			else {
				printf("%s\n", invalidMove);
			}
			
		}
		
		else if(choice3 == 2) {
			printf("You decided to go further down and that's definitely not a wise choice you made. No one has seen you ever since...\n");
			printf("%s\n", gameOver); //char gameOver will be the output of a false move that leads to the end of game//
		}
		
		else {
			printf("%s\n", invalidMove);
		}

	}

	else {
		printf("%s\n", invalidMove);
	}
	
}

else if(choice1 == 2) {
	printf("After a while, the light suddenly went out. You are terrified. You heard the sound of something moving towards you, faster and faster. And...\n");
	printf("%s\n", gameOver);
}

else {
	printf("%s\n", invalidMove);
}

if(choice5 != 2) { //struct is implemented here again along with a condition that choice5 != 5, when choice5 == 5, another struct: struct user user_succeed will be the output rather than this one//
struct user user_failed;
strcpy(user_failed. user, "User");
strcpy(user_failed. grade, "F");
printf( "user: %s\n", user_failed. user );
printf( "grade: %s\n", user_failed. grade );
} 

printf("\n");
printf("Do you wish to try again?\n"); 
printf("1. Yea\n");
printf("2. Nope\n");
scanf("%d", &again);
	while(again == 2) {
		printf("\n");
		for(i = 0; i < 10; i++) {
			printf("Promise me you will come back later qwq!!!\n");
			printf("Have a nice day qwq!!!\n"); }
		break;	
	}

	while(again != 1 && again != 2) {
		printf("%s\n", invalidMove);
		printf("Enter  ./a.out  to restart the game qwq!!!\n");
		break;	
	}

} 

while(again == 1); //gives the option of cotinue/terminate the game//			
		
return;

}

	
