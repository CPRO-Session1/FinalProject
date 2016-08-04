#include <stdio.h>


int main () {


int exit1, choice1, choice2, choice3, choice4, choice5, choice6, choice7, choice8;
char name[50];
printf ("Enter your name, adventurer.\n");
scanf ("%s", name);
printf ("Hello %s.\n", name); 
printf ("You are stranded on an island alone. You have a limited supply of food and resources.\n");
printf ("Your goal is to travel to different locations within the island and find supplies that will\nhelp you build a boat and get back home.\n");
printf ("Your first location is the Beach.\n1. Go to the Beach.\n2. Exit this game.\n");
scanf ("%d", &exit1);
if (exit1 == 1) {
	printf ("You decided to travel to the Beach. You found a key and a chest. You open the chest and find a pile of wood. Unfortunately, it is guarded by a snake.\nWhat would you like to do?\n 1. Kill the Snake. \n 2. Run Away.\n");
}
else if (exit1 == 2) {
        printf ("You are no real adventurer. GAME OVER.\n");
        }	
scanf ("%d", &choice1);
	if (choice1 == 1) {
	printf ("You decided to kill the snake. Unfortunately, you died.\nGAME OVER.\n");
	}
	else if (choice1 == 2) {
	printf ("Smart move %s, you'll find another way to get wood!\n", name);
}

printf ("\n");
printf ("After wandering for a couple hours on the island, you come along an abandoned warehouse. You hear something inside.\n");
printf ("1. Go inside.\n2. Run.\n");
scanf ("%d", &choice2);
if (choice2 == 1) {
	printf ("Despite your fear of the dark, you decide to go inside the abandoned mansion. Coincidentally, you find a pile of wood. Congratulations %s!\n", name);
	printf ("\n");
	}
else if (choice2 == 2) {
	printf ("Only LOSERS run away.\nGAME OVER\n");

	}

printf ("While returning to the beach to put away your newly found wood, you hear something mysterious. Fortunately, you find a knife on the ground and keep it close to your body.\nA couple of minutes later, you see a tribe of monkeys guarding something.\nAs you approach the tribe, two monkeys jump and attack you. Is it worth fighting them to see what they are guarding?\n");
printf ("1. Yes\n2. No.\n");
scanf ("%d", &choice3);
if (choice3 == 1) {
	printf ("You are one crazy adventurer. You fight off the monkeys and find out that they were guarding a sail. Good job %s!\n", name);
}
else if (choice3 == 1) {
	printf ("If you ever get the chance to  meet a tribe of monkeys, you better take it %s!\n GAME OVER!\n", name);
}

printf ("Your food is running short. You don't have much time left. All you have is a sail and some wood. You're going to have to hurry up %s!\n", name);
printf ("What would you like to do?\n1. Give up and exit the game!\n2. Cry yourself to death.\n3. Be the hero you always were and keep on going!\n");
scanf ("%d", &choice4);
for (choice4 == 1; choice4 <= 3; choice4++) {
	if (choice4 == 1 | choice4 ==2) {
	printf ("You're no warrior %s. Get out of here!\n GAME OVER!\n", name);
	}
	else if  (choice4 == 3) {
	printf ("You truly are an adventurer %s! As a result of your extreme courage, a random flying engine appears infront of you. You have all the components to create your boat!\n", name);
	}	
	printf ("Press 1 to go back to the beach.\n");
	scanf ("%d", &choice5);
	if (choice5 == 1) {
	printf ("You have arrived at the beach. Time for the construction of the boat!\n");
	}	
	else if (choice5 != 1) {
	printf ("Not a valid answer; however, I'll let you get away with it this time %s!\n", name);
	break;
	}

}
	printf ("\n");
	printf ("You're going to need a hammer to complete this job.\nTravel to the nearest cave to find one.");
	printf ("Which cave would you like to go to?\n1. The cave of DOOM!\n2. The Cave of Tranquility!\n3. The Cave of the Worker!");
	scanf ("%d", &choice6);
	for (choice6 == 1; choice6 <= 3; choice6++) {
		if (choice6 == 1 | choice6 == 2) {
			printf ("The answer was right infront of your eyes; yet, you somehow missed it %s!\n GAME OVER!\n", name);
			}	
		else if (choice6 == 3) {
			printf ("You chose to go to The Cave of the Worker! Wise choice %s!\n", name);
		}
}
	printf ("As you travel to the cave, four human beings jump on you. Surprised and confused, you pass out for over 8 hours!\n");
	printf ("They take you into the 'abandoned warehouse' in which you previously were\n");
	printf ("You see a Nokia phone on the floor. This might be your last chance at survival. What do you do?\n");
	printf ("1. Take the phone\n2. Don't take the phone.\n3. I don't believe Nokias are phones, so I'll just sit and wait for a better way out\n");
	scanf ("%d", &choice7);
		if (choice7 == 1) {
			printf ("That would be a smart decision, but you can't seem to remember anyone's phone number.\n GAME OVER!\n");
		}
		else if (choice7 == 2) {
			printf ("At least give it a shot, what else are you going to do %s?!", name);
			}
		else if (choice7 == 3) {
			printf ("Surprisingly, you're right.\n As a result of your wise and well-thought out decision, I grant you, as a spectator of your journey, the hammer for which you had been looking.\n Get back to the beach quickly so you can finally get back home!");
			printf ("\n");
			printf ("Press 1 to go back to the beach %s!", name);
			scanf ("%d", &choice8);
			if (choice8 == 1) {
			printf ("After 3 hours of walking, you finally made it to the Beach.\n You construct your boat using your newly found hammer.\n Although it took you a while to build the boat, you manage to do so with ease and get back home with only a couple of scratches and a hint of malaria.\n CONGRATULATIONS %s, you WON THE GAME!\n", name);
			}
			else if (choice8 != 1) {
				printf ("Invalid answer.\n GAME OVER!");
		
			

						}
					}
return 0;
}
