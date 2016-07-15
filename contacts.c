// Julia Tan
// Final Project July 13, 2016

#include <stdio.h>
#include <string.h>

typedef struct contact{ // Make a new contact
	char name[100];
	int telnum;
	char rating[4];
	char address[100];
}newCon;

typedef struct category{
	char cname[100];
	int contactCount;
	newCon contact[50];
}newCat;

void userSelect(int* a);
void categories(int choice1);
void newContact(int categoryNum, newCat* category);

void userSelect(int* a){ // Process what the user wants to do
	scanf("%d", a);
	int selected = 0;
		if (*a == 1){ // Create a new contact
			categories(1);
		}else if (*a == 2){ // View categories
			categories(2);
		}else if (*a == 3){ // View contacs
			categories(3);
		}else if (*a == 4){ // Edit details
			categories(4);
		}else if (*a == 5){ // Exit
			
		}else{
			printf("Invalid selection. Please try again:\n");
			userSelect(a);
		}
}

void newContact(int categoryNum, newCat* category){ // Add a new contact
	int *conCountPtr = &(category[categoryNum].contactCount); // Counts number of contacts within chosen category
	char enter; // Checks for \n symbol
	int phone; // evaluates scanf
	// Create a new contact
	printf("New Contact\n");
	printf("Enter full name: ");
	scanf(" %[^\n]%*c", category[categoryNum].contact[*conCountPtr].name);

	do{ // gets phone number and makes sure it is only made of integers
		printf("Enter phone number: ");
		phone = scanf("%d%c", &category[categoryNum].contact[*conCountPtr].telnum, &enter);
		if (phone != 2 || enter != '\n'){
			printf("Invalid number, try again.\n");
			while (getchar() != '\n')
			;
		}
	}while (phone != 2 || enter != '\n');

	printf("Enter rating: ");
	scanf(" %s", category[categoryNum].contact[*conCountPtr].rating);
	
	printf("Enter address: ");
	scanf(" %[^\n]%*c", category[categoryNum].contact[*conCountPtr].address);
	
	printf("Contact successfully added.\n\n");
	(*conCountPtr)++;
}

void categories(int choice1){
	static int catCount = 0; // counts number of existing categories
	static newCat category[10]; // creates an array of categories
	newCat *catPtr = category; // pointer to array of categories for functions
	static int userIn = 0; // user input for what category they want to put their contacts in
	int i = 0; // index for category array
	int x = 0; // index for contacts array inside the contacts array
	int *conCount = &category[i].contactCount; // pointer to number of contacts in array
	int cat = 0;
	int cont = 0;
	int phone;
	char enter;


	if (choice1 == 1){ // Select a category to put your contact in
		printf("\nSelect a category to put your new contact in:\n");
		printf("(0) Create a new category\n");
		categories(2);
		scanf("%d", &userIn); // Create new category or choose existing

		while (userIn < 1){

			if (userIn == 0){ // Creating a new category
				catCount++; // Increases count of categories
				printf("\nEnter name of new category: ");
				scanf(" %[^\n]%*c", category[catCount].cname); // Renames new category
				category[catCount].contactCount = 0;
				printf("Category successfully created.\n\n");
			}
			printf("\nSelect a category to put your new contact in:");
			printf("(0) Create a new category\n");
			categories(2);
			scanf("%d", &userIn);
		}
		newContact(userIn, catPtr); // arg1 is number of categories, arg2 is pointer to category array
	} else if (choice1 == 2){ // Print categories with contacts underneath
		for (i = 1; i <= catCount; i++){
			printf("\n(%d) %s\n", i, category[i].cname);
			for (x = 0; x < category[i].contactCount; x++){
				printf("- %d. %s\n", x, category[i].contact[x].name);
			}
		}
	} else if (choice1 == 3){ // Prints categories and contacts
		categories(2);
		printf("\nSelect category: ");
		scanf("%d", &i);
		printf("Select contact: ");
		scanf("%d", &x);

		for (x = 0; x < category[i].contactCount; x++){
	 		printf("Name:  %s\n", category[i].contact[x].name);
			printf("Phone Number: %d\n", category[i].contact[x].telnum);
			printf("Rating: %s\n", category[i].contact[x].rating);
			printf("Address: %s\n", category[i].contact[x].address);
		}
	}else if (choice1 == 4){ // Edits contact Details		
		int editChoice = 0;

		categories(2);
		printf("Select category: ");
		scanf("%d", &i);
		printf("Select contact: ");
		scanf("%d", &x);

		printf("Current Details\n");
		categories(5);

		printf("\nWhat would you like to edit? (1)Name (2)Number (3)Rating (4)Address\n");
		scanf("%d", &editChoice);

		if (editChoice == 1){ //name
			printf("Enter new name: ");
			scanf(" %[^\n]%*c", category[i].contact[x].name);
		}else if (editChoice == 2){ // number
			do{ // gets phone number and makes sure it is only made of integers;
				printf("Enter phone number: ");
					phone = scanf("%d%c", &category[i].contact[x].telnum, &enter);
					if (phone != 2 || enter != '\n'){
					printf("Invalid number, try again.\n");
		                        while (getchar() != '\n')
	                      		;
					}
			}while (phone != 2 || enter != '\n');
		}else if (editChoice == 3){ // rating
			scanf("%s", category[i].contact[x].rating);
		}else if (editChoice == 4){ // address
			scanf("%[^\n]%*c", category[i].contact[x].address);
		}

		printf("Updated details successfully.\n");
	}
}

int main(){
	int select = 0;
	int *ptrS = &select;
	printf("Welcome!\n");
	while (select != 5){
		printf("\nWhat would you like to do? (1)Create a new contact (2)View categories (3)View specific contacts (4)Edit details (5)Exit\n");
		userSelect(ptrS);
	}
	return 0;
}
