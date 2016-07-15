#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Creates a structure for the person*/
typedef struct persona
{
	int distance;
	int engine;
	int gas;
	int durability;
} person;

/*Shows the distance the police move each turn*/
int copDistance(int distance)
{
	int r = (rand() % 3) +1;
	distance -= r;
	return distance;
}

/*Fixes the user's engine*/
int fixEngine(int engine)
{
	engine = 6;
	printf("Your engine is fixed!\n");
	return engine;
}

/*Moves the user quickly*/
int goFast(int distance)
{
	distance += (rand() % 3) + 4;
	return distance;
}

/*Moves the user slowly*/
int goSlow(int distance)
{
	distance += (rand() % 2) + 2;
	return distance;

}

/*Refills the user's gas*/
int refillGas(int gas)
{
	gas = 20;
	printf("Your gas tank is full!\n");
	return gas;
}

int fixCar(int durability)
{
	durability = 2;
	printf("Your car is fixed!\n");
	return durability;
}

int main()
{

	int moving;
	/*starts the random number generator*/
	srand(time(0));
	/*Sets the scene for the game*/
	printf("You are on the run from the police. Can you escape? Choose your actions wisely because you can be caught!!\n");
	/*Calls for the user input and initializes the hiding places*/
	char input, hidingPlace[4][100] = {"Alley", "Store", "Concert", "Supermarket"};
	/*Initializes the while loop parameter*/
	int x = 0;
	/*Initializes the structure*/
	person user;
	user.distance = 10;
	user.engine = 6;
	user.gas = 20;
	user.durability = 2;
	/*Initializes the opportunity for car crash*/
	int crash = 0, crashchecker = 0;
	/*Initializes the hiding place possibility*/
	int hiding[2] = {0,0};
	/*Initializes error checkers*/
	int hWorks = 0, error = 0, s = 0;
	static int i = 0;
	while (x == 0) //Start of while loop
	{
		s = 0;
		/*Prompts the user for input*/
		printf("What would you like to do?\n");
		printf("Write q to quit, e to fix your engine, g to refill gas, f to go fast, i for information, d to fully fix your car to its full durability and s to go slow\n");
		/*Gives user possibility for hiding place*/
		hiding[1] = rand() % 10;
		/*Checks to see if the user found a hiding spot*/
		if (hiding[1] == 8 && i > 0 && error == 0)
		{
			/*Decides the hiding place*/
			hiding[2] = rand() % 4;
			printf("You have found a hiding spot. It is in the %s. Put in h to hide.\n", *(hidingPlace + hiding[2]));
		}
		/*Scans for user input*/
		scanf("%c", &input);
		/*Checks user input*/
		if (input == '\n')
		{
			input = getchar();
		}
		/*Checks if user input is valid for hiding*/
		if ((input == 'h' || input == 'H') && hiding[1] == 8)
		{
			hWorks++;
			/*Decides if the user has hid from the cops*/
			hiding[2] = rand() % 6;
			if (hiding[2] == 3)
			{
				printf("You hid from the cops and escaped the police, so you win!!\n");
				x++;
				break;
			}
			else
			{
				printf("You did not escape the police, so you need to keep moving!\n");
				user.distance = copDistance(user.distance);
			}

		}
		error = 0;
		/*Evaluates each user input*/
		switch (input)
		{
			case 'Q':
			case 'q':
				printf("You have chosen to quit, are you sure? Write y for yes or n for no!\n");
				/*Evaluates user input to see if they actually want to quit*/
				while (s == 0)
				{
					scanf("%c", &input);
					if (input == '\n')
					{
						scanf("%c", &input);
					}
					if (input == 'y' || input == 'Y')
					{
						x++;
						s++;
						printf("Have a nice day! \n");
					}
					else if (input == 'n' || input == 'N')
					{
						s++;
						printf("Why would you lie to me like that?\n");
					}
					else 
					{
						printf("That is not a valid input \n");
					}
				}
				break;
			case 'E':
			case 'e':
				user.engine = fixEngine(user.engine);
				user.distance = copDistance(user.distance);
				error ++;
				break;
			case 'G':
			case 'g':
				user.gas = refillGas(user.gas);
				user.distance = copDistance(user.distance);
				error++;
				break;
			case 'F':
			case 'f':
				moving = user.distance;
				user.distance = goFast(user.distance);
				/*Calculates how much the user has moved*/
				moving = user.distance - moving;
				printf("You moved %d miles! \n", moving);
				user.distance = copDistance(user.distance);
				/*Calculates how much gas the user has lost*/
				user.gas -= (rand() % 2) + 3;
				user.engine--;
				break;
			case 'S':
			case 's':
				moving = user.distance;
				user.distance = goSlow(user.distance);
				/*Calculates how much the user has moved*/
				moving = user.distance - moving;
				printf("You moved %d miles! \n", moving);
				user.distance = copDistance(user.distance);
				/*Calculates how much gas the user has lost*/
				user.gas -= (rand() % 2) + 1;
				user.engine--;
				break;
			case 'I':
			case 'i':
				/*Tells the users all of the information*/
				printf("You are %d miles away from the police, you have %d more moves before you need to fix your engine, you have %d more gallons of gas left, and your car can survive %d more crashes! \n", user.distance, (user.engine - 1), user.gas, (user.durability - 1));
				error++;
				break;
			case 'D':
			case 'd':
				user.durability = fixCar(user.durability);
				user.distance = copDistance(user.distance);
				break;
			case 'H':
			case 'h':
				/*Checks if the user input is valid for h*/
				if (hWorks != 0)
				{
					break;
				}
				/*Returns errors if it is incorrect placement*/
			default:
				printf("That is not a valid input\n");
				error++;
		}
		/*Checks if user crashed*/
		crash = rand() % 12;
		if (crash == 11 && (input == 'f' || input == 'F' || input == 'S' || input == 's'))
		{
			if (user.durability == 2)
			{
				printf("You have crashed, and if you crash again you will lose!\n");
				user.durability--;
			}
			else if (user.durability == 1)
			{
				printf("You have crashed and your car broke. You lose!!\n");
				x++;
			}

		}
		/*Checks end-of-game scenarios*/
		if (x == 1)
		{
			break;
		}
		if (user.distance < 8 && user.distance >= 5)
		{
			printf("The police are calling out \"We are coming, you should pull over!\"");
			printf("\n");
		}
		else if (user.distance >= 35)
		{
			printf("You have outran the police!!\n");
			x++;
			break;
		}
		else if (user.distance < 5)
		{
			printf("The police have caught you. You lose!\n");
			x++;
			break;
		}
		if (user.gas <= 0)
		{
			printf("You lose because you ran out of gas!!\n");
			x++;
			break;
		}
		if(user.engine == 1)
		{
			printf("Your engine needs fixing.\n");
		}
		else if (user.engine < 1)
		{
			printf("You lose because you needed to fix your engine.\n");
			x++;
			break;
		}
		if (user.gas <= 4 && user.gas > 0)
		{
			printf("Your gas level is very low\n");
		}
		i++;
		hWorks = 0;
		printf("\n");
	}
}
