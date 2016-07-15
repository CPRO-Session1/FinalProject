#include <stdio.h>
#include <string.h>

typedef struct {
	    char lName[12];	//Struct containing employee records incl. name, job code, description, who they report to, and their salaries
	    char fName[25];
	      int jCode;
	   char jTitle[30];
	char reportsTo[25];
          double salary;
        
    } empProfile;

typedef struct {
	char note[125];  //Struct containing employee notes

    } empNotes;

enum charcheck
	{
	match 			//Used an enum to set 0 to 'match' so the conditionals using strcmp make more intuitive sense
	};

//


int intro( ) {

  int i, j, k = 5;

    char message01[] = "Welcome to ROBCO Industries (TM) Termlink\n\n\n\n";
    char message02[] = "Password Required: _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ";
    char linemessage01[] = "__________________________________________________________\n";
    char help[] = "h";
    char password[] = "H5A6E9B7";
    char successmessage01[] = "\nAccess to ROBCO Industries (TM) Termlink granted.\n\n";
    char successMessage02[] = "Welcome, USER\n\n";
    char failureMessage01[] = "\nAccess to ROBCO Industries (TM) Termlink denied.\n\n";
    char abort[] = "abort";
    char helpgrid[] = "  1 2 3 4 5 6 7 8 9"; 				
    char introFin[20];
    char entry[20];

    		printf("\n\n  1 2 3 4 5 6 7 8 9\nA X X X X X 2 X X X\nB X X X X X X 4 X X\nC X X X X X X X X X\nD X X X X X X X X X\nE X X X X X X X X 3\nF X X X X X X X X X\nG X X X X X X X X X\nH X X X X 1 X X X X\nI X X X X X X X X X\n");							//this is the grid puzzle that shows the password to get into the terminal


	        for(i=0;i<200;i++){
                printf("\n");			//print 200 new lines to clear screen
       		}

       		 printf("%75s\n", linemessage01);
     		 printf("%68s\n", message01);
      		 printf("\n");
       		 printf("%75s\n", message02);
       		 printf("%75s\n\n\n\n", linemessage01); //print the menu
	
		 printf("Password: ");
	

		 while(strcmp(password, entry) != match){

			

	 		 for(k=5;k>=0;k--)    
			  {
	    		  scanf("%s", entry);
			         
				while(k == 1) {	
					printf("\n\nEmployees: Please look uUP@UP@UP@UP@UP@UP@UP@@@ your personal password in the directory located within the main office.\n\n"); 
					break; 												//If you enter 4 incorrect guesses, this message is printed, hinting to look up
				}

			 if(strcmp(password, entry) != match) {
            		    printf("Please try again... %d tries remaining...\n", k);}

			      else if(strcmp(password, entry) == match) {
			      printf("%75s\n", successmessage01);
                              printf("%75s\n", successMessage02);
                              printf("\nEnter any key to continue. To abort, enter 'abort'\n");
			    
			        scanf("%s", introFin);
			        while(strcmp(abort, introFin) == match){
				
				  return 0; }
				
			    return 1;
                            }
			  }
		  printf("%75s\n", failureMessage01);
		  return 0;
	  	}
             
     
}

//


int menu() {

	empProfile emp1={"Smith", "John", 36748, "Senior Project Manager", "N/A", 90000};
	empProfile emp2={"Windas", "Peter", 73625, "Secretary", "John Smith", 35000};
	empProfile emp3={"Gershengorn", "Caleb", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp4={"Yu", "Justin", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp5={"Delaney", "Kurt", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp6={"Fieri", "Guy", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp7={"EEE", "@@", 33223, "Asnngggg^^^^^^^^", "JJJJJJJJJ", 4};
	empProfile emp8={")))))deepr", "go", 11111, "A", "John Smith", 999999};                                    						//members of employee profile struct

	empNotes emp1N={"NULL"};
	empNotes emp2N={"Windas, Peter 3/24/1989: >>Performance generally meets expectations--Pay is quite high compared to his peers in level V"};		//members of employee notes struct
	empNotes emp3N={"Gershengorn, Caleb 5/14/1989: >>May be overqualified for new position. May receive an increase at this time."};
	empNotes emp4N={"Yu, Justin 4/3/1991: @@@@@@@@@@@@@@@@@@@@@@$$$$"};
	empNotes emp5N={"Delaney, KuU|U|U|U|U|deeper@go~````dddeeper&&&&go~``````dddeeper&&&&&&&"};
	empNotes emp6N={"Fieri, Guy 3/5/1990: 999999993((((((((((((((((((((((((((((ecord may need to be reviewed^^^^^^^^^^^^^^^^^"};
	empNotes emp7N={"EEE,EEEiiii@@@@reconsider in 6 mont###################"};
	empNotes emp8N={":::::"};

	char message01[] = "Welcome to ROBCO Industries (TM) Termlink            \n";
	char menuLine1[] = ">> 1. View employee profiles                                      \n";
	char menuLine2[] = ">> 2. View employee progress notes                                \n";
	char menuLine3[] = ">> 3. View PROJECT SAFEHOUSE experiment history                   \n";
	char menuLine4[] = ">> 4. Access system administrator menu (Admin Password Required)  \n";
	char menuLine5[] = "    ((Enter '0' at any time to re-print these options))           ";
	char lineLine1[] = "------------------------------------------------------------------\n";
	char lineLine2[] = "----------------------------------------------------------------------------------------------------------\n";
	
	int option, i, option1 = 1, clearScreen = 300;
	char ch;

	for(i=0;i<28;i++){
		printf("\n");
		}

	printf("%75s\n%75s\n%75s%75s\n%75s%75s%75s%75s\n%75s\n\n%75s", lineLine1, message01, lineLine1, lineLine1, menuLine1, menuLine2, menuLine3, menuLine4, menuLine5, lineLine1); //prints the strings that make up the menu


	
	for(i=0;i<20;i++){
		printf("\n");
		}


	option = 2;

	while(option > 1 || option < 5) { //while loop for menu user input
		printf(">>");
		scanf("%d", &option);
	switch(option){

		case 0 : //case 0 reprints the menu

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

				printf("%75s\n%75s\n%75s%75s\n%75s%75s%75s%75s%75s\n%75s", lineLine1, message01, lineLine1, lineLine1, menuLine1, menuLine2, menuLine3, menuLine4, menuLine5, lineLine1);

		break;

	
		case 1 : //profiles
	

				
				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

			

			printf("Surname:       Name:      Job Code:       Description:             Reports to:            Salary (annual):");        
			printf("\n%s\n", lineLine2);
			printf("%s          %s       %d           %s   %s                    %lf\n", emp1.lName, emp1.fName, emp1.jCode, emp1.jTitle, emp1.reportsTo, emp1.salary);
			printf("%s         %s      %d           %s                %s             %lf\n", emp2.lName, emp2.fName, emp2.jCode, emp2.jTitle, emp2.reportsTo, emp2.salary);
			printf("%s    %s      %d           %s       %s             %lf\n", emp3.lName, emp3.fName, emp3.jCode, emp3.jTitle, emp3.reportsTo, emp3.salary);
			printf("%s             %s     %d           %s       %s             %lf\n", emp4.lName, emp4.fName, emp4.jCode, emp4.jTitle, emp4.reportsTo, emp4.salary);
			printf("%s        %s       %d           %s       %s             %lf\n", emp5.lName, emp5.fName, emp5.jCode, emp5.jTitle, emp5.reportsTo, emp5.salary);
			printf("%s          %s        %d           %s       %s             %lf\n", emp6.lName, emp6.fName, emp6.jCode, emp6.jTitle, emp6.reportsTo, emp6.salary);
			printf("%s            %s         %d           %s         %s              %lf\n", emp7.lName, emp7.fName, emp7.jCode, emp7.jTitle, emp7.reportsTo, emp7.salary);
			printf("%s     %s         %d           %s                        %s             %lf\n", emp8.lName, emp8.fName, emp8.jCode, emp8.jTitle, emp8.reportsTo, emp8.salary);






			  //jTitle and reportsTo won't print
			 break;
	
		case 2 : //notes

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

				printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", emp1N.note, emp2N.note, emp3N.note, emp4N.note, emp5N.note, emp6N.note, emp7N.note, emp8N.note);


			break;

		case 3 : //vault experiment history

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}


			 printf("PROJECT SAFEHOUSE: Testing the limits of the human body/mind so as to ensure American survival should the destruction of nuclear warfare require .\n\n");
			 printf("Vault 92: Populated largely by renowned musicians, this vault was a test bed for a white noise-based system for implanting combat-oriented posthypnotic suggestions.\n");
			 printf("Vault 42: No light bulbs of more than 40 watts were provided. Result of experiment unkown.\n");
			 printf("Vault 106: Psychoactive drugs were released into the air filtration system 10 days after the door was sealed. Result of experiment unknown.\n");
			 printf("Vault 108: Housed a cloning lab and all (surviving) residents were clones of one man named Gary.\n");
			 printf("Vault 43: Populated by twenty men, ten women, and one panther. ROBCO Employees are forbidden to speak about Vault 43.\n");
			 printf("Vault -000: [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[.\n");
			 printf("Vault 75: Excluding vault staff, all residents were under the age of 18 at the time of vault activation; parents were quietly separated from their children and later executed by vault security. The experiment went well for several generations, but the archives were destroyed and most if not all of the progress made was lost.\n");
			 printf("Vault 27: This vault would be overcrowded deliberately. 2000 people would be assigned to enter, double the total sustainable amount.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault 33: Populated by one man and a crate full of puppets. The Lone Inhabitant of the Vault went insane from lack of human contact and eventually Abandoned the vault after 'murdering' one of the puppets.");
		  	 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");

 
			 break;

		case 4 : //access admin menu

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}


			 if(ADMINACCESS() == 0) {
				 printf("Access denied\n");
				 }
				 else if(ADMINACCESS() == 1) {
					printf("Access granted\n");
					}
	//	case 5 :
		}

	}

}

int ADMINACCESS() {

   srand(time(NULL));
	
	int i, n, j, k, l, digGuess, guess1, guess2, guess3, guess4, numCorrect = 0;

	int arr1[4];
	int arr2[4];
	int arrTest[4] = {1, 2, 3, 4};
	
	for (i=0;i<4;i++)  {
	int num = rand()%9+0;
	arr2[i]=num;
	}



	printf("Please enter your administrative PIN number: _ _ _ _\n");

	for(n=0;n<15;n++) {

		while(numCorrect < 5) {

		for(k=0;k<4;k++) {
			
			l = k + 1;

			printf("\nEnter Digit %d:\n>>", l);
			scanf("%d", &digGuess);
			printf("\n");
			arr1[k] = digGuess; 
		}

		printf("\n\n");

		for(j=0;j<4;j++) {


			if(arr1[j] == arr2[j]) { 
				numCorrect++;
			}
			
		}

			printf("%d/4 correct", numCorrect);

			if (numCorrect == 4) 
			{
				printf("\n");
			
				return 1;
			}
		}

		return 1;

	}

return 0;

}

int adminMenu() { //NOT YET IMPLEMENTED: The admin menu is a replica of the original menu, with added administrative options and hints for the next puzzle hidden throughout the glitched text garbage

	empProfile emp1={"Smith", "John", 36748, "Senior Project Manager", "N/A", 90000};
	empProfile emp2={"Windas", "Peter", 73625, "Secretary", "John Smith", 35000};
	empProfile emp3={"Gershengorn", "Caleb", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp4={"Yu", "Justin", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp5={"Delaney", "Kurt", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp6={"Fieri", "Guy", 10293, "Associate Engineer", "John Smith", 40000};
	empProfile emp7={"EEE", "@@", 33223, "Asnngggg^^^^^^^^", "JJJJJJJJJ", 4};
	empProfile emp8={")))))deepr", "go", 11111, "A", "John Smith", 999999};                                    						//members of employee profile struct

	empNotes emp1N={"NULL"};
	empNotes emp2N={"Windas, Peter 3/24/1989: >>Performance generally meets expectations--Pay is quite high compared to his peers in level V"};		//members of employee notes struct
	empNotes emp3N={"Gershengorn, Caleb 5/14/1989: >>May be overqualified for new position. May receive an increase at this time."};
	empNotes emp4N={"Yu, Justin 4/3/1991: @@@@@@@@@@@@@@@@@@@@@@$$$$"};
	empNotes emp5N={"Delaney, KuU|U|U|U|U|deeper@go~````dddeeper&&&&go~``````dddeeper&&&&&&&"};
	empNotes emp6N={"Fieri, Guy 3/5/1990: 999999993((((((((((((((((((((((((((((ecord may need to be reviewed^^^^^^^^^^^^^^^^^"};
	empNotes emp7N={"EEE,EEEiiii@@@@reconsider in 6 mont###################"};
	empNotes emp8N={":::::"};

	char message01[] = "Welcome to ROBCO Industries (TM) Termlink            \n";
	char menuLine1[] = ">> 1. View employee profiles                                      \n";
	char menuLine2[] = ">> 2. View employee progress notes                                \n";
	char menuLine3[] = ">> 3. View PROJECT SAFEHOUSE experiment history                   \n";
	char adminLine1[] = ">> 5. Facility tempurature control				       \n";
	char adminLine2[] = ">> 6. Facility atmospheric pressure control		       \n";
	char adminLine3[] = ">> 7. Facility entrance/exit vault control			       \n";
	char menuLine5[] = "    ((Enter '0' at any time to re-print these options))           ";
	char lineLine1[] = "------------------------------------------------------------------\n";
	char lineLine2[] = "----------------------------------------------------------------------------------------------------------\n";
	
	int option, i, option1 = 1, clearScreen = 300;
	char ch;

	for(i=0;i<28;i++){
		printf("\n");
		}

	printf("%75s\n%75s\n%75s%75s\n%75s%75s%75s%75s%75s%75s%75s\n%75s\n", lineLine1, message01, lineLine1, lineLine1, menuLine1, menuLine2, menuLine3, adminLine1, adminLine2, adminLine3,  menuLine5, lineLine1); 
	//prints the strings that make up the menu


	
	for(i=0;i<20;i++){
		printf("\n");
		}


	option = 2;

	while(option > 1 || option < 5) { //while loop for menu user input
		printf(">>");
		scanf("%d", &option);
	switch(option){

		case 0 : //case 0 reprints the menu

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

	printf("%75s\n%75s\n%75s%75s\n%75s%75s%75s%75s%75s%75s%75s\n%75s\n", lineLine1, message01, lineLine1, lineLine1, menuLine1, menuLine2, menuLine3, adminLine1, adminLine2, adminLine3,  menuLine5, lineLine1); 

		break;

	
		case 1 : //profiles
	

				
				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

			

			printf("Surname:       Name:      Job Code:       Description:             Reports to:            Salary (annual):");        
			printf("\n%s\n", lineLine2);
			printf("%s          %s       %d           %s   %s                    %lf\n", emp1.lName, emp1.fName, emp1.jCode, emp1.jTitle, emp1.reportsTo, emp1.salary);
			printf("%s         %s      %d           %s                %s             %lf\n", emp2.lName, emp2.fName, emp2.jCode, emp2.jTitle, emp2.reportsTo, emp2.salary);
			printf("%s    %s      %d           %s       %s             %lf\n", emp3.lName, emp3.fName, emp3.jCode, emp3.jTitle, emp3.reportsTo, emp3.salary);
			printf("%s             %s     %d           %s       %s             %lf\n", emp4.lName, emp4.fName, emp4.jCode, emp4.jTitle, emp4.reportsTo, emp4.salary);
			printf("%s        %s       %d           %s       %s             %lf\n", emp5.lName, emp5.fName, emp5.jCode, emp5.jTitle, emp5.reportsTo, emp5.salary);
			printf("%s          %s        %d           %s       %s             %lf\n", emp6.lName, emp6.fName, emp6.jCode, emp6.jTitle, emp6.reportsTo, emp6.salary);
			printf("%s            %s         %d           %s         %s              %lf\n", emp7.lName, emp7.fName, emp7.jCode, emp7.jTitle, emp7.reportsTo, emp7.salary);
			printf("%s     %s         %d           %s                        %s             %lf\n", emp8.lName, emp8.fName, emp8.jCode, emp8.jTitle, emp8.reportsTo, emp8.salary);






			  //jTitle and reportsTo won't print
			 break;
	
		case 2 : //notes

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}

				printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", emp1N.note, emp2N.note, emp3N.note, emp4N.note, emp5N.note, emp6N.note, emp7N.note, emp8N.note);


			break;

		case 3 : //vault experiment history

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}


			 printf("PROJECT SAFEHOUSE: Testing the limits of the human body/mind so as to ensure American survival should the destruction of nuclear warfare require .\n\n");
			 printf("Vault 92: Populated largely by renowned musicians, this vault was a test bed for a white noise-based system for implanting combat-oriented posthypnotic suggestions.\n");
			 printf("Vault 42: No light bulbs of more than 40 watts were provided. Result of experiment unkown.\n");
			 printf("Vault 106: Psychoactive drugs were released into the air filtration system 10 days after the door was sealed. Result of experiment unknown.\n");
			 printf("Vault 108: Housed a cloning lab and all (surviving) residents were clones of one man named Gary.\n");
			 printf("Vault 43: Populated by twenty men, ten women, and one panther. ROBCO Employees are forbidden to speak about Vault 43.\n");
			 printf("Vault -000: [[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[.\n");
			 printf("Vault 75: Excluding vault staff, all residents were under the age of 18 at the time of vault activation; parents were quietly separated from their children and later executed by vault security. The experiment went well for several generations, but the archives were destroyed and most if not all of the progress made was lost.\n");
			 printf("Vault 27: This vault would be overcrowded deliberately. 2000 people would be assigned to enter, double the total sustainable amount.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault 33: Populated by one man and a crate full of puppets. The Lone Inhabitant of the Vault went insane from lack of human contact and eventually Abandoned the vault after 'murdering' one of the puppets.");
		  	 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");
			 printf("Vault -000: [[[[[[[[[[[[{[[[@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@{{{{{{{{{{{{{{{{{[[[{[[[[{{{{[{{{[{[{{{{{{[{{[{[{[[[[[[[{.\n");

 
			 break;

		case 4 : //access admin menu

				for(i=0;i<clearScreen;i++){
				printf("\n");
				}


			 if(ADMINACCESS() == 0) {
				 printf("Access denied\n");
				 }
				 else if(ADMINACCESS() == 1) {
					printf("Access granted\n");
					}
	
				 
	//	case 5 : // loop that simulates tempurature control interface

	//	case 6 : // loop that simulates pressure control interface

	//	case 7 : // loop that simulates vault door control. the controls are corrupted and the user must find another way to control them

	
	}



	}

}




int fileSystem() { //simulated filesystem I am going to implement


	/*	char buf[256];
	
	FILE *fp;

	fp = fopen("dir.txt", "w+");

	fprintf(fp, "bin\nboot\ncdrom\ndev\netc\nhome\nlib\n");
	fclose(fp);
	
	fp = fopen("dir.txt", "r");

		while (fgets (buf, sizeof(buf), stdin)) {
		        printf("line: %s", buf);
			}

		      if (ferror(stdin)) {
			          fprintf(stderr,"Oops, error reading stdin\n");
				      abort();
				        }
		        return 0; */
	}


int main() {

//fileSystem();

int decision; 

decision = intro();

if(decision == 1){
	menu();
}
else if(decision == 0) {
printf("Goodbye\n\n");
return 0;
}

}
