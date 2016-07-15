/* Matthew Danielson
*  7/8/16
*  final.c
*  Implements the survival simulation discussed in the local README.txt
*/

// Header Files 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//Constants


// Prototypes
void intro();
void conclusion(int);
void rules();
void sleep(time_t seconds);
void GI(int, int, int, int, int, int, int);
int settings();
float randomgen();
float eventmod(int);
int combat(int, int, int);
/*
		Stats Reference
		
Group Supplies:
	[0] = Food
	[1] = Fuel
	[2] = Weapons
	[3] = Electronics
 	[4] = Construction

Individual Stats
	[0] = Scavenging
	[1] = Combat
	[2] = Construction
	[3] = Tinkering

Group Stats - In variance from default
	Same formatting as individual
 */


// Structs
typedef struct{
	char name[20];
	int skills[4];
}surv;

typedef struct{
	char name[20];
	int supplies[5];
	int skills[4];
	int size;
	int baselevel;
}group;




//Driver
int main(){
	srand(time(NULL));
	intro();
	rules();
	int gameloop = 1;
	// General Variables - Mass declaration
	int daycount;
	int difficulty; //Defaults to 2
	int userinput;//Main while loop covers 1 day of real time
	int customsettings;
	char name[20];
	float event;
	int special;
	char throwaway;
	int car = 1;
	int starvation = 0;
	//Before game stuff
	customsettings = settings();
	//Custom settings
	if(customsettings == 48){
		printf("\nFor details of specific settings, please read README.txt\n");
		while(1){
			printf("How many days after the apocalypse do you want to start?");
			scanf("%d", &daycount);
			getchar();
			if(daycount == 13)
				daycount = getchar();
			if(daycount >= 1 && daycount <= 999)
				break;
			printf("\nInvalid Input\n");
		}
		while(1){
			printf("What difficulty do you want to play on; 1, 2, or 3?");
			scanf("%d", &difficulty);
			scanf("%c", &throwaway);
			if(difficulty >= 1 && difficulty <= 3)
				break;
			printf("\nInvalid Input\n");
		}
	}
	else{
		daycount = 1;
		difficulty = 2;
	}
	//Party Creation
	group playergroup;
	printf("What is the name of your group?");
	fgets(name, sizeof(name), stdin);
	name[strlen(name)-1] = '\0';
	strcpy(playergroup.name, name);
	playergroup.size = 4;
	surv players[playergroup.size];
	for(int x = 0; x < playergroup.size; x++){
		printf("\nWhat is survivor #%d's name?", (x+1));
		fgets(name, sizeof(name), stdin);
		name[strlen(name)-1] = '\0';
		strcpy(players[x].name, name);
		while(1){
			printf("\nWhat is %s's speciality? 1 is scavenging, 2 is fighting, 3 is building, and 4 is tinkering: ", players[x].name);
			scanf("%d", &special);
			scanf("%c", &throwaway); //Gets rid of carriage return
			if(special >= 1 && special <= 4)
				break;
			printf("\nInvalid Input\n");
		}
		for(int y = 0; y < 4; y++)
			players[x].skills[y] = 0;
		if(special == 1)
			players[x].skills[0] += 2;
		if(special == 2)
			players[x].skills[1] += 2;
		if(special == 3)
			players[x].skills[2] += 2;
		if(special == 4)
			players[x].skills[3] += 2;
		}

	//Final setup - group stats
	playergroup.baselevel = 0;
	for(int z = 0; z< playergroup.size; z++)
			playergroup.skills[z] = 0;
	for(int x = 0; x < playergroup.size; x++){
		for(int y = 0; y < 4; y++){
			playergroup.skills[x] += players[y].skills[x];
		}
	}
	
	//Starting supplies
	for(int x = 0; x < 5; x++){
		playergroup.supplies[x] = (7-difficulty);
	}
	if(difficulty == 1)
		playergroup.supplies[0] +=5;
	if(difficulty == 3)
		playergroup.supplies[0] -= 2;

	while(gameloop){
		printf("\n\n\nIt's a new day....");
		sleep(3);
		printf("\n\n\n\n");
		GI(daycount, playergroup.supplies[0], playergroup.supplies[1], playergroup.supplies[2], playergroup.supplies[3], playergroup.supplies[4], car);
		for(int x = 0; x < 2; x++){//Two actions per day
			while(1){
				printf("What would you like to do?");
				scanf("%d", &userinput);
				scanf("%c", &throwaway);
				if(userinput == 13)
					userinput = getchar();

				if(userinput >=1 && userinput <=5){
					if((userinput == 1 && playergroup.supplies[4] == 0) || (userinput == 4 && playergroup.supplies[3] == 0)){
						printf("\nInvalid Input, no supplies left\n");
						continue;
					}	
					else
						break;

				}
				printf("\nInvalid input\n");
			
			}
			//Resolving actions
			//For every probability, action is resolved and a flavor statement is printed
		// Various outcomes are pretty self explanatory - printf statements essentially tell the user what has happened.
			printf("\n");
			if(userinput == 1){
				playergroup.supplies[4] --;
				event = randomgen();
				event += playergroup.skills[2];
				//Base foritfication
				if(event > 30 && event < 90){
					printf("You successfully upgraded the base against future attacks!");
					playergroup.baselevel ++;
				}
				if(event > 10 && event <= 30){
					printf("You failed to upgrade the base.");

				}
				if(event >= 90){
					printf("You managed to upgrade the base exceedingly well!");
					playergroup.baselevel += 2;
				}
				if(event <= 10){
					printf("In your efforts to upgrade the base, you managed to break an existing barricade...");
				}
			}
	
			if(userinput == 2){
				int car2;
				if(playergroup.supplies[1] > 0){
				while(1){
						printf("\nDo you want to take the car?(1 = yes, 0 = no)");
						scanf("%d", &car2);
						scanf("%c", &throwaway);
						if(car2 == 1 || car2 == 0)
							break;
						printf("\nInvalid Input\n");
					}
				}
				else
					car2 = 0;
				event = randomgen();
				event += playergroup.skills[0];
				if(car == 1){
					//Use of a car increases the loot that the player will find when looting, but uses one fuel
					event += 5;
					playergroup.supplies[1] --;
				}
				//Scavenging
				event /= eventmod(daycount);
				if(event > 90){
					printf("You managed to find plenty of supplies!");	
					// 5 resources in game only
					for(int x = 0; x < 5; x++)
						playergroup.supplies[x] ++;
				}
				if(event <= 90 && event > 85){
					printf("You found a lot of fuel, and some food");
					playergroup.supplies[0] ++;
					playergroup.supplies[1] += 2;
				}
				if(event <= 85 && event > 80){
					printf("You found two days worth of food.");
					playergroup.supplies[0] += 2;
				}
				if(event <= 80 && event > 70){
					printf("You found some food and electronic scrap.");
					playergroup.supplies[0] ++;
					playergroup.supplies[3] ++;
				}
				if(event <= 70 && event > 60){
					printf("You found some food and a weapon.");
					playergroup.supplies[0] ++;
					playergroup.supplies[2] ++;
				}
				if(event <= 60 && event > 50){
					printf("You broke two weapons opening a crate - which contained some supplies.");
					playergroup.supplies[0] ++;
					playergroup.supplies[3] ++;
					playergroup.supplies[2] -= 2;
					playergroup.supplies[4] ++;
				}
				if(event <= 50 && event > 40){
					if(car2 == 1){
						printf("You found a bunch of food, but the car broke down..");
						car = 0;
						playergroup.supplies[0] += 2;
					}
					else{
						printf("You found some fuel");
						playergroup.supplies[1] ++;
					}
				}
				if(event <= 40 && event > 30){
					printf("You broke a weapon fending off other survivors, and found nothing");
					playergroup.supplies[2] --;
				}
				if(event < 30 && event > 20){
					if(car2 == 1){
						printf("The car broke down and you lost your provisions");
						car = 0;
						playergroup.supplies[0] -= 2;
					}
					else{
						printf("You lost fuel and food...");
						playergroup.supplies[0] -= 2;
						playergroup.supplies[1] -= 2;
					}
				}
				if(event <= 20 && event > 15){
					printf("You lost a day's worth of food and two weapons..");
					playergroup.supplies[0] --;
					playergroup.supplies[2] -= 2;
				}
				if(event <= 15){
					printf("While looting, a bunch of your supplies were stolen..");
					for(int x = 0; x < 5; x++)
						playergroup.supplies[x] --;
				}

			}
			
			if(userinput == 3){
				event = randomgen();
				//Farm
				//No skill for farming, otherwise it is too strong
				//Only resource that cannot is not reduced over time
				if(event >= 55 && event <= 95){
					printf("You produced two days worth of food!");
					playergroup.supplies[0] += 2;
				}
				if(event >= 35 && event < 55 ){
					printf("You let today's food rot...oops...");
					playergroup.supplies[0] -=1;
				}
				if(event >95){
					printf("A plentiful harvest! You produced four days worth of food!");
					playergroup.supplies[0] += 4;
				}
				if(event < 35 && event >= 30){
					printf("You left out a bunch of food...two days worth rotted...");
					playergroup.supplies[0] -= 2;
				}
				if(event < 30 && event >= 20){
					printf("You managed to get enough food for today.");
					playergroup.supplies[0] ++;
				}
				if(event < 20 && event >= 10){
					printf("You found nothing...");
				}
				if(event < 10){
					printf("You mistook a hatchet for a scythe and tried to farm with it...ruining the hatchet and the food...");
					playergroup.supplies[2] --;
				}
			}
			if(userinput == 4){
				playergroup.supplies[3] --;
				event = randomgen();
				event += playergroup.skills[3];
				//Tinker
				if(car == 0){
					if(event >=50){
						printf("You repaired the car!");
						car = 1;
					}
					else
						printf("You failed to repair the car...");
				}
				else{
					if(event <= 25)
						printf("You failed to create anything...");
					if(event <= 70 && event >50){
						printf("You managed to create some construction supplies!");
						playergroup.supplies[4] ++;
					}
					if(event <= 50 && event > 25){
						printf("You managed to create a makeshift weapon!");
						playergroup.supplies[2] ++;
					}
					if(event >85 && event <= 95){
						printf("You found some valuable electronics amidst the debris! You recover two scrap.");
						playergroup.supplies[3] += 2;
					}
					if(event > 95){
						int randy = randomgen()/25;
						int randy2 = randomgen()/25;
						players[randy].skills[randy2] ++;
						printf("%s made an augmentation that makes him a permanantly more valuable team member!", players[randy].name);
					}
					if(event > 70 && event <= 85){
						if(playergroup.supplies[4] > 0){
							printf("By adding some planks, you managed to make two weapons!");
							playergroup.supplies[4] --;
							playergroup.supplies[2] += 2;
						}
						else{
							printf("You failed to make anything of value...");
						}
					}
				}

			}
			// Assault
			if(userinput == 5){
				// Here, the player rolls off against the computer, where the players gets buffs based on number of weapons possessed and combat skills, and the computer gets +1 buff for every 20 days of game time that have passed. The difference in their rolls determines  the severity of the outcome. The player can receive TREMENDOUS rewards, while facing half a party wipe, which is, essentially, a quick spiral into a game over. Again, SUPER risky
				int weaponcount;
				if(playergroup.supplies[2] >= playergroup.size)
					weaponcount = playergroup.size;
				else
					weaponcount = playergroup.supplies[2];
				int difference = combat(daycount, playergroup.skills[1], weaponcount);
				//Player wins
				if(difference > 0){
					if(difference < 5){
						printf("\nAfter a short skirmish, you make off with some supplies.\n");
						playergroup.supplies[0] ++;
						playergroup.supplies[2] ++;
					}
					else if(difference < 10){
						printf("\nYou defeat your enemy in a short skirmish.\n");
						playergroup.supplies[0] += 3;
						playergroup.supplies[2] ++;
					}
					else if(difference < 20){
						printf("\nYou win after a good battle, getting a sizable quantity of loot!\n");
						for(int x = 0; x < 5; x++)
							playergroup.supplies[x] ++;
						playergroup.supplies[0] += 2;
					}
					else if(difference < 30){
						printf("\nIn an impressive tour de force, you trounce the enemy, and take a lot of loot.\n");
						for(int x = 0; x < 5; x++)
							playergroup.supplies[x] += 2;
					}
					else if(difference >= 30){
						printf("\nYou pulverized your foes. Honestly it was pretty disgusting, but hey, you literally destroyed them and took everything they had...\n");
						for(int x = 0; x < 5; x++)
							playergroup.supplies[x] += 3;
					}
				}
				//Computer wins
				if(difference < 0){
					difference *= -1;
					if(difference < 5){
						printf("\nAfter a short conflict, you retreat, leaving some supplies behind.\n");
						playergroup.supplies[0] --;
						playergroup.supplies[2] --;
					}
					else if(difference < 10){
						int rand = randomgen()/25;
						printf("\nYou retreat after a short fight, in which %s got hurt.\n", players[rand].name);
						playergroup.supplies[0] --;
						for(int x = 0; x < 4; x++)
							players[rand].skills[x] = 0;
						
					}
					else if(difference < 20){
						int rand = randomgen()/25;
						int rand2 = randomgen()/25;
						printf("\nTwo of your men got injured in the fight, and some supplies were left behind...\n");
						for(int x = 0; x < 4; x++){
							players[rand].skills[x] = 0;
							players[rand2].skills[x] = 0;
						}
						for(int x = 0; x< 5; x++)
							playergroup.supplies[x] --;
					}
					else if(difference < 30){
						int rand = randomgen()/25;
						printf("\nIn the skirmish, %s died...You also lost a lot of supplies.\n", players[rand].name);
						playergroup.size --;
						for(int x = 0; x<4; x++)
							players[rand].skills[x] = 0;
						playergroup.supplies[2] -= 3;
					}
					else if(difference >= 30){
						int rand = randomgen()/25;
						int rand2 = randomgen()/25;
						printf("\nIn the fight, two of your men died...additionally, you left a lot of supplies behind...\n");
						playergroup.size -= 2;
						for(int x = 0; x < 4; x++){
							players[rand].skills[x] = 0;
							players[rand2].skills[x] = 0;
						}
						for(int x = 0; x < 5; x++)
							playergroup.supplies[x] --;
					}
				}

				//Assault
			}
			printf("\n");
			sleep(1);
		}
		//Daily Events- Raid, Fire, Stranger

		//Nightly raid - Lots of possiblities
		event = randomgen();	
		event *= eventmod(daycount);
		if(event > 90){
			printf("\nThere was a nightly raid...\n");
			sleep(1);
			event = randomgen();
			event += playergroup.baselevel;
			if(playergroup.supplies[2] >= playergroup.size)
				event += playergroup.size;
			else
				event += playergroup.supplies[2];
			if(event > 85){
				printf("\nYou managed to fend off the invaders, and take some of their weapons and dropped food.\n");
				playergroup.supplies[0] ++;
				playergroup.supplies[2] ++;
			}
			if(event <= 85 && event > 70)
				printf("\nThe attackers ran off after a short skirmish\n");
			if(event <= 70 && event > 50){
				printf("\nWhile fending off the attackers, two of your weapons broke.\n");
				playergroup.supplies[2] -= 2;
			}
			if(event <= 50 && event > 40){
				printf("\nThe attackers stole a weapon and damaged your car..\n");
				playergroup.supplies[2] --;
				car = 0;
			}
			if(event <= 40 && event > 20){
				printf("\nThe attackers stole a lot of your supplies..\n");
				for(int x = 0; x < 5; x++)
					playergroup.supplies[x] --;
			}
			if(event <= 20 && event > 10){
				printf("\nThe attackers sacked your base, stealing a lot of supplies and trashing your car..\n");
				for(int x = 0; x < 5; x++)
					playergroup.supplies[x] -= 2;
			}
			if(event <= 10){
				int randy = randomgen()/25;
				printf("\nThe attackers maimed %s...", players[randy].name);
				//4 skills only 
				for(int x = 0; x < 4; x++)
					players[randy].skills[x] = 0;
			}
		}	
		//Fire
		event = randomgen();
		if(event < 10){
			printf("\nThere has been a fire...\n");
			event = randomgen();
			if(event > 50){
				printf("\n1 of each of your supplies burned...\n");
				for(int x = 0; x < 5; x++)
					playergroup.supplies[x] --;
			}
			else{
				printf("\nThe garage was hit badly...the car and some construction supplies are not usable\n");
				car = 0;
				playergroup.supplies[4] -= 2;
			}

		}
		//Person showing up
		event = randomgen();
		if(event < 5){
			int decision;
			printf("\nA stranger has appeared at your doorstep...do you want to interact with him?(1 to interact, 0 to ignore");
			while(1){
				scanf("%d", &decision);
				scanf("%c", &throwaway);
				if(decision == 1 || decision == 0)
					break;
				printf("\nInvalid Input\n");
			}
			if(decision == 0)
				printf("\nThe stranger leaves without conflict.\n");
			if(decision == 1){
				event = randomgen();
				if(event > 90){
					int randy = randomgen()/25;
					int rand2 = randomgen()/25;
					printf("\nThe stranger teaches %s a random skill, and leaves. What good guy.\n", players[randy].name);
					players[randy].skills[rand2] += 2;
				}
				if(event <= 90 && event > 70){
					printf("\nThe stranger leaves a gift of food.\n");
					playergroup.supplies[0] += 3;
				}
				if(event <= 70 && event > 40){
					int randy = randomgen()/30;
					int rand2 = randomgen()/20;
					printf("\nThe stranger offers to trade %d food for %d electronic scraps. Do you accept?(1 to accept, 0 to decline)", randy, rand2);
					int decide;
					while(1){
						scanf("%d", &decide);
						scanf("%c", &throwaway);
						if(decide == 1 || decide == 0)
							break;
						printf("\nInvalid Input\n");
					}
					if(decide == 0)
						break;
					if(playergroup.supplies[0] < randy)
						printf("\nYou do not have the resources to make this deal...\n");
					if(decide == 1){
						playergroup.supplies[0] += randy;
						playergroup.supplies[3] -= rand2;
					}
				}
				if(event < 40){
					printf("\nThe stranger steals 1 of each of your supplies...except for food. He took 4 days worth of rations while you slept...Also, he killed a member of your team...");
					sleep(1);
					printf("What a guy\n");
					for(int x = 0; x < 5; x++)
						playergroup.supplies[x] --;
					playergroup.supplies[0] -= 3;
					playergroup.size --;

				}
			}
		}

		//Regular Events
		playergroup.supplies[0] --;
		daycount++;
		//Starvation check
		if(playergroup.supplies[0] <= 0)
			starvation ++;
		if(playergroup.supplies[0] > 0)
			starvation = 0;
		//No negative values
		for(int x = 0; x < 5; x++){
			if(playergroup.supplies[x] < 0)
				playergroup.supplies[x] = 0;
		}
		//Loose conditions
		if(starvation == 5)
			gameloop = 0;
		if(playergroup.size <= 0)
			gameloop = 0;
	}
	conclusion(daycount);	
}

//Combat for assault - the MOST dangerous and lucrative action in the game 

int combat(int daycount, int skillcount, int weaponcount){
	int playerroll = randomgen() + skillcount + weaponcount;
	int comproll = randomgen() + (int)(daycount/20);
	int difference = playerroll - comproll;
	return difference;
}


float eventmod(int daycount){
	int mod = (daycount/20);
	float toreturn = 1+(mod/100);
	return toreturn;

}

float randomgen(){//Random numbers between 0 and 100
	float randomnum= (float) (((float)(rand())/RAND_MAX)*100);
	return randomnum;
}

int settings(){
	printf("Would you like to play with custom settings? If so, please enter 0.\n");
	int setting;
	setting = getchar();
	getchar();
	return setting;

}

//Prints out the graphical interface that present the player's supplies
void GI(int date, int food, int fuel, int weapons, int elec, int cons, int car){
	printf("Day %d\n\n", date);
	if(car == 0)
		printf("The car is broken...\n\n");
	else
		printf("The car is working\n\n");
	printf("Food:%5d days\n", food);
	printf("Fuel:%5d liters\n", fuel);
	printf("Weapons:%5d assorted weapons\n", weapons);
	printf("Electronic Scrap:%5d decigrams\n", elec);
	printf("Construction Supplies:%5d kilograms\n", cons);
	sleep(1);
	printf("\n----------------------\nActions:\n");
	sleep(1);
	printf("1 - Foritfy the base\n");
	printf("2 - Scavenge\n");
	printf("3 - Farm\n");
	printf("4 - Tinker\n");
	printf("5 - Assault\n");
}	



// Text-based functions
void intro(){
	printf("\tWelcome to the Apocalypse...\n");
	sleep(1);
	printf("Nuclear war has led to the fall of our former lives\n");
	sleep(2);
	printf("We are now presented with a new civilization\n");
	sleep(3);
	printf("One in which you must survive.\n");
	sleep(4);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
}

void rules(){
	printf("Rules:\n\n");
	sleep(1);
	printf("Each elapsed turn is one day\n");
	sleep(2);
	printf("Survive with your group; each day you have choose how you want to proceed\n");
	sleep(3);
	printf("In a moment, you may choose to survive in the classic wasteland, or one of your own creation\n");
	sleep(3);
	printf("Good luck\n");
	sleep(2);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void conclusion(int day){
	printf("\n\n\nYou have fallen...\n");
	sleep(2);
	printf("You lasted until day %d", day);
	sleep(3);
	printf("\nThank you for playing\n");
	sleep(2);
	exit(0);
}


