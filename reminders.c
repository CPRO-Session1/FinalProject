//Bettina Benitez
#include <stdio.h>
#include <string.h>

typedef struct {
	char title[50][500];
	char day[50][10];
	char time[50][50];
	int priority[50];
} reminders;

void getRetrieve(reminders x, int *ptrNum);

void getWelcome (char* ptrNew, int* ptrNum) {
	printf("Welcome to Weekly Reminders. In this program, you will be able to input any reminder into the database and retrieve it any time you want.\n\nFor each reminder, you can label it and give it a title, the day of the week it's due for, the time it's due for, and the level of urgency from 1-3 (1 being the lowest and 3 being the highest priority)\n\nBegin a reminder? (y/n): ");
	scanf("%c", &*ptrNew);
	if (*ptrNew == 'y') {
		*ptrNum;
		(*ptrNum)++;
	}
	else if (*ptrNew == 'n')
		printf("Goodbye!");
	else
		printf("%c is not a valid response\n", *ptrNew);
}

void getInfo (reminders x, int* ptrNum) {
	printf("\nReminder: %d", *ptrNum);
	printf("\nEnter your reminder a title (500 character max):\n");
	while (getchar () != '\n');
	fgets(x.title[*ptrNum], sizeof(x.title[*ptrNum]), stdin);
	printf("Enter the day this reminder is due: \n");
	scanf("%s", x.day[*ptrNum]);
	printf("Enter the time of the reminder: \n");
	scanf("%s", x.time[*ptrNum]);
	printf("Enter the level of priority (1-3): \n");
	scanf("%d", &x.priority[*ptrNum]);
	printf("\nReminder Recap:\n");
	printf("%s", x.title[*ptrNum]);
	printf("Day:%s\nTime:%s\nPriority Level:%d\n", x.day[*ptrNum], x.time[*ptrNum], x.priority[*ptrNum]);
	char answer;
	while(getchar () != '\n');
	while (answer != 'y') {
		printf("\nAre you sure about your reminder? (y/n): ");
		scanf("%c", &answer);
		if (answer == 'y')
			printf("\nYour reminder has been saved!\n");
		else if (answer == 'n')
			getInfo(x, ptrNum);
		else
			printf("Invalid option\n");
	}
}

void getOptions (reminders x, int* ptrNum) {
	int check = 0;
	char ptrOpt;
	printf("\nWhat would you like to do?\na) make a new reminder b) retrieve a reminder c) end program: ");
	while (check == 0) {
		scanf("%c", &ptrOpt);
		if (ptrOpt == 'a') {
			*ptrNum;
			(*ptrNum)++;
			getInfo(x, ptrNum);
			printf("What would you like to do?: ");
			check = 0;
		}
		if (ptrOpt == 'b') {
			printf("\nWhat information would you like to retreieve? Choose from the following:\n1) Title c)end program: ");
			int opt;
			char title[100];
			scanf("%d", &opt);
			if (opt == 1) {
				printf("Enter the title?\n");
				while (getchar() != '\n');
				fgets(title, sizeof(title), stdin);
				printf("title is %s\n", title);
				char *pos;
				if ((pos = strchr(title, '\n')) != NULL)
					*pos = '\0';
				printf("title is %s\n", title);
				for (int i = 1; i <= *ptrNum;  i++) {
					printf("reminder title: %s\n", x.title[i]);
					if (strcmp(x.title[i], title) == 0) 
							printf("Title:%sDay:%s\nTime:%s\nPriority Level:%d\n", x.title[i], x.day[i], x.time[i], x.priority[i]);
				else
					printf("Not valid\n");
				printf("What would you like to do?: \n");
				}
			check = 0;
			}
		}
		if (ptrOpt == 'c') {
			printf("\nGoodbye!\n");
			check = 1;
		}
	}
}
int main () {
	reminders x;
	char new;
	char *ptrNew = &new;
	char aa = 'y';
	int docNum = 0;
	int *ptrNum = &docNum;
	getWelcome(ptrNew, ptrNum);
	if (new == aa) {
		getInfo(x, ptrNum);
	}
	getOptions(x, ptrNum);
	return 0;
}
