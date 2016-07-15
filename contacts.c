// Julia Tan
// Final Project July 13, 2016

#include <stdio.h>
#include <string.h>

typedef struct contact{
	char name[100];
	int telnum;
	char rating[4];
	char address[100];
}newCon;

typedef struct category{
	char cname[100];
	int contactCount;
	newCon contact[50]; // Contacts are created under categories
}newCat;

void userSelect(int* a);
void categories(int choice);
void newContact(int categoryNum, newCat* category);

void userSelect(int* a){ // Process what the user wants to do
	scanf("%d", a);
		if (*a == 1){ // Create a new contact
			categories(1);
		}else if (*a == 2){ // View categories
			categories(2);
		}else if (*a == 3){ // View contacs
			categories(3);
		}else if (*a == 4){ // Edit details
			categories(4);
		}else if (*a == 5){ // Exit
			
		}else{ // Invalid input
			printf("\nInvalid selection. Please try again:\n");
			userSelect(a);
		}
}

void newContact(int categoryNum, newCat* category){ // Adds a new contact
	int *conCountPtr = &(category[categoryNum].contactCount); // Counts number of contacts within chosen category
	char enter; // Checks for \n symbol
	int phone; // evaluates scanf

	// Create a new contact
	printf("New Contact\n");

	printf("Enter full name: ");
	scanf(" %[^\n]%*c", category[categoryNum].contact[*conCountPtr].name); // reads everything, even space characters, until it hits \n

	do{ // gets phone number and makes sure it is only made of integers
		printf("Enter phone number: ");
		phone = scanf("%d%c", &category[categoryNum].contact[*conCountPtr].telnum, &enter);
		if (phone != 2 || enter != '\n'){ // checks if the only character in input is the \n symbol (this would be true for integer inputs
			printf("Invalid number, try again.\n");
			while (getchar() != '\n') // clears input buffer
			;
		}
	}while (phone != 2 || enter != '\n'); // while the input is not purely an integer value...

	printf("Enter rating: ");
	scanf(" %s", category[categoryNum].contact[*conCountPtr].rating);

	while (getchar() != '\n');
	printf("Enter address: ");
	scanf(" %[^\n]%*c", category[categoryNum].contact[*conCountPtr].address);
	
	printf("Contact successfully added.\n\n");
	(*conCountPtr)++; // Increments the number of contacts within the chosen category
}

void categories(int choice){ // Does category-related work
	static int catCount = 0; // counts number of existing categories
	static newCat category[10]; // creates an array of categories
	newCat *catPtr = category; // pointer to array of categories for functions
	static int userIn = 0; // user input for what category they want to put their contacts in
	int i = 0; // index for category array
	int x = 0; // index for contacts array inside the contacts array
	int *conCount = &category[i].contactCount; // pointer to number of contacts in array
	int phone;
	char enter;
	int editChoice; // User's input for choosing what detail of contact to edit

	if (choice == 1){ // Select a category to put your contact in
		printf("\nSelect a category to put your new contact in:\n");
		printf("(0) Create a new category\n");
		categories(2);
		scanf("%d", &userIn); // Create new category or choose existing
		while (userIn == 0){ // While user has chosen to create a new category
			catCount++; // Increases count of categories
			printf("\nEnter name of new category: ");
			scanf(" %[^\n]%*c", category[catCount].cname); // Names new category
			category[catCount].contactCount = 0; // Sets number of contacts to 0
			printf("Category successfully created.\n\n");
		
			printf("\nSelect a category to put your new contact in:");
			printf("\n(0) Create a new category\n");
			categories(2);
			scanf("%d", &userIn);
		}
		if (userIn <= catCount){ // checks if user input is one of the choices listed
			newContact(userIn, catPtr); // arg1 is number of categories, arg2 is pointer to category array
		}else{
			printf("\n\nInvalid selection. Please try again: \n\n");
			categories(1);
		}
	} else if (choice == 2){ // Print categories with contacts underneath
		for (i = 1; i <= catCount; i++){ // For each category
			printf("\n(%d) %s\n", i, category[i].cname);
			for (x = 0; x < category[i].contactCount; x++){ // For each contact under a single category
				printf("- (%d) %s\n", x, category[i].contact[x].name);
			}
		}
	} else if (choice == 3){ // Prints categories and contacts
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
	}else if (choice == 4){ // Edits contact Details		
		int editChoice = 0; // accepts input from user to edit contact details through a menu;
		categories(2);
		printf("Select category: ");
		scanf("%d", &i);
		printf("Select contact: ");
		scanf("%d", &x);

		printf("\nWhat would you like to edit? (1)Name (2)Number (3)Rating (4)Address\n");
		scanf("%d", &editChoice);

		if (editChoice == 1){ //name
			printf("Enter new name: ");
			scanf(" %[^\n]%*c", category[i].contact[x].name);
		}else if (editChoice == 2){ // tel number
			do{ // gets phone number and makes sure it is only made of integers;
				printf("Enter phone number: "); // makes sure input is not invalid
					phone = scanf("%d%c", &category[i].contact[x].telnum, &enter);
					if (phone != 2 || enter != '\n'){
					printf("Invalid number, try again.\n");
		                        while (getchar() != '\n')
	                      		;
					}
			}while (phone != 2 || enter != '\n');
		}else if (editChoice == 3){ // rating
			printf("Enter new rating: ");
			scanf("%s", category[i].contact[x].rating);
		}else if (editChoice == 4){ // address
			printf("Enter new address: ");
			scanf(" %[^\n]%*c", category[i].contact[x].address);
		}

		printf("Updated details successfully.\n");
	}
}

int main(){
	int select = 0; // user's input to questions
	int *ptrS = &select; // pointer to user's input (for other functions)
	printf("Welcome!\n");
	while (select != 5){
		printf("\nWhat would you like to do? (1)Create a new contact (2)View categories (3)View specific contacts (4)Edit details (5)Exit\n");
		userSelect(ptrS);
	}
	return 0;
}
