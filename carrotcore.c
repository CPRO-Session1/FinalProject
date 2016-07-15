/*Rumeet Goradia - CarrotCore Educational Service*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curses.h>




char *splitString(char*ptrS, char c) { //Used for splitting first and last names read from file
	while(*ptrS !=c) {
		ptrS++;
	}
	return ptrS;
}

void clrscr(){//Simulates screen clearing by creating a bunch of new lines
	int i6;
	for (i6=0;i6<45;i6++)
	{
		printf("\n");
	}
}
void help (){ //Prints main menu
	printf("\n[1] CHECK ROSTER\n[2] ENTER GRADE\n[3] STUDENT DATA\n[4] TEACHER DATA\n[5] LOG OUT\n\n");
}

void subjects (){ //Prints subjects menu
	printf("\n[1] MATH\n[2] ENGLISH\n[3] SCIENCE\n[4] HISTORY\n[5] SPANISH\n\n");
}

void assigntype(){ //Prints types of assignments
	printf("\n[1] TEST/PROJECT\n[2] QUIZ\n[3] CLASSWORK\n[4] HOMEWORK\n\n");
}

typedef struct {
	float *gradesEng;
	float avgEng;
	float *gradesMath;
	float avgMath;
	float *gradesSci;
	float avgSci;
	float *gradesHist;
	float avgHist;
	float *gradesSpan;
	float avgSpan;
} grades;
typedef struct {
	char *fname;
	char *lname;
	char *address;
	char *birthday;
	grades grad;
} student;

typedef struct{
	char *fname;
	char *lname;
	char *birthday;
	char *grade;
	char *email;
	char *title;
} teacher;

void roster (char *arr[], char *arr2[], char *bdays[], char *adds[], int lim){
	int j1, j2;
	int greatnesf;
	char **lnamef;
	char **fnamef;
	char **bdayf;
	char **addref;
	for(j1=0; j1<lim; j1++)//Alphebtizes by last name
	{
		greatnesf=0;
		for (j2=0; j2<lim; j2++)
		{
			strcmp(arr[j1], arr[j2]);
			if (strcmp(arr[j1], arr[j2])>0)
			{
				greatnesf++;
			}
		}
		lnamef[greatnesf]=arr[j1];
		fnamef[greatnesf]=arr2[j1];
		bdayf[greatnesf]=bdays[j1];
		addref[greatnesf]=adds[j1];
		strcat(lnamef[greatnesf], ", ");
		strcat(lnamef[greatnesf], fnamef[greatnesf]);

	}

	printf("                         Name:                         Address:                         Date of Birth:\n");//Prints "Last Name, First Name           Address           DOB" for all students
	int j3;
	for (j3=0;j3<lim;j3++)
	{
		printf("%30s %33s %39s\n", lnamef[j3],  addref[j3], bdayf[j3]);
	}
	return;
}

				

int main()
{	
	clrscr();
	printf("Welcome to CarrotCore!\n");
	printf("Pikachu School District, Dummer County, Wyoming\n\n");
	printf("Registered users for Leroy Jenkins Elementary:\n");
	char *teachk = "sienna.spencer@pikachu.k12.wy.us";
	char *teach1 = "joel.chapman@pikachu.k12.wy.us";
	char *teach2 = "niamh.parker@pikachu.k12.wy.us";
	char *teach3 = "hannah.lyons@pikachu.k12.wy.us";
	char *teach4 = "christopher.law@pikachu.k12.wy.us";
	char *teach5 = "mitchell.davis@pikachu.k12.wy.us";
	printf("Sienna Spencer (Kindergarten) <%s>\n", teachk);
	printf("Joel Chapman (First Grade) <%s>\n", teach1);
	printf("Niamh Parker (Second Grade) <%s>\n", teach2);
	printf("Hannah Lyons (Third Grade) <%s>\n", teach3);
	printf("Christopher Law (Fourth Grade) <%s>\n", teach4);
	printf("Mitchell Davis (Fifth Grade) <%s>\n\n", teach5);
	char *user=(char*) malloc(35);
	char *pass=(char*) malloc(sizeof(char)*100);
	int i1;
	do {
		printf("Username: ");
		printf("%u\n",sizeof(user));
		fgets(user, sizeof(user), stdin);
	printf("%s\n", user);
		user[strlen(user)-1]='\0';
		for (i1=0; i1<35; i1++)
		{
			user[i1]=tolower(user[i1]);
		}//function "tolower" used to make all input lowercase
	printf("%s\n", user);
		printf("Password: ");
		fgets(pass, sizeof(pass),stdin);
		pass[strlen(pass)-1]='\0';
		if(strcmp(user, teachk)!=0 && strcmp(user, teach1)!=0 && strcmp(user, teach2)!=0 && strcmp(user, teach3)!=0 && strcmp(user, teach4)!=0 && strcmp(user, teach5)!=0)
		{
			printf("Invalid username. Please login with a certified Pikachu School District email.\n");
		
		}
	} while(strcmp(user, teachk)!=0 && strcmp(user, teach1)!=0 && strcmp(user, teach2)!=0 && strcmp(user, teach3)!=0 && strcmp(user, teach4)!=0 && strcmp(user, teach5)!=0);
	FILE *class;
	teacher teach;
	switch (user[0])//first letter of username input decides teacher profile and class roster
	{
		case 's':
			class=fopen("kindergarten2.txt", "r");
			teach.fname="Sienna";
			teach.lname="Spencer";
			teach.birthday="5/31/1985";
			teach.grade="Kindergarten";
			teach.email=teachk;
			teach.title="Mrs.";
			break;
		case 'j':
			class=fopen("firstgrade2.txt", "r");
			teach.fname="Joel";
			teach.lname="Chapman";
			teach.birthday="1/28/1975";
			teach.grade="First Grade";
			teach.email=teach1;
			teach.title="Mr.";
			break;
		case 'n':
			class=fopen("secondgrade2.txt", "r");
			teach.fname="Niamh";
			teach.lname="Parker";
			teach.birthday="10/10/1961";
			teach.grade="Second Grade";
			teach.email=teach2;
			teach.title="Mrs.";
			break;
		case 'h':
			class=fopen("thirdgrade2.txt", "r");
			teach.fname="Hannah";
			teach.lname="Lyons";
			teach.birthday="12/14/1955";
			teach.grade="Third Grade";
			teach.email=teach3;
			teach.title="Mrs.";
			break;
		case 'c':
			class=fopen("fourthgrade2.txt", "r");
			teach.fname="Christopher";
			teach.lname="Law";
			teach.birthday="3/2/1969";
			teach.grade="Fourth Grade";
			teach.email=teach4;
			teach.title="Mr.";
			break;
		case 'm':
			class=fopen("fifthgrade2.txt", "r");
			teach.fname="Mitchell";
			teach.lname="Davis";
			teach.birthday="12/22/1977";
			teach.grade="Fifth Grade";
			teach.email=teach5;
			teach.title="Mr.";
			break;
	}
	

	int num;
	fscanf(class,"%d", &num);//first line of each file is number of students
	student stud[num];
	int i;
	fgetc(class);
	char *wholeName=(char*)malloc(sizeof(char)*100);
	char *address=(char*)malloc(sizeof(char)*100);
	char *birthday=(char*)malloc(sizeof(char)*12);
	int lnamelength=0, fnamelength=0, bdaylength=0, addlength=0;
	for (i=0; i<num; i++)//initializes data to structure array
	{
		fgets(wholeName, 100, class);
		wholeName[strlen(wholeName)-1]='\0';
		stud[i].fname=wholeName;
		stud[i].lname=splitString(wholeName, ' ');
		fnamelength+=strlen(stud[i].fname);
		*stud[i].lname='\0';
		stud[i].lname++;
		lnamelength+=strlen(stud[i].lname);
		fgets(address, 100, class);
		address[strlen(address)-1]='\0';
		stud[i].address=address;
		addlength+=strlen(stud[i].address);
		fgets(birthday, 12, class);
		birthday[strlen(birthday)-1]='\0';
		stud[i].birthday=birthday;
		bdaylength+=strlen(stud[i].birthday);
		
	}
		clrscr();
	printf("Welcome, %s %s!\n", teach.title, teach.lname);
	int choice;
	do{//main menu
		printf("Please select an option below. (Enter the numeric value.)\n");
		help();
		if (scanf("%d", &choice)==0){
				clrscr();
				printf("Invalid input. Please input a number.\n");
				while(getchar()!='\n');
				}		
	}while(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5);
	//the following pointers to pointers are needed for roster
	char **lname=(char**)malloc(lnamelength);
	char **fname=(char**)malloc(fnamelength);
	char **bdays=(char**)malloc(bdaylength);
	char **addresses=(char**)malloc(addlength);
	int i5;
	for (i5=0;i5<num;i5++)
	{
		lname[i5]=stud[i5].lname;
		fname[i5]=stud[i5].fname;
		bdays[i5]=stud[i5].birthday;
		addresses[i5]=stud[i5].address;
	}
	int subcho;
	int asscho;
	float weight;
	int i7, i8;
	
	int denom, correct;
	int *assignments=(int*)malloc(400);
	switch (choice)
	{
		case 1:
			roster (lname, fname, bdays, addresses, num);
			break;
		case 2: 
			do{//choose subject, choose assignment type, input grades for each student based on correct/total questions
				printf("What subject are you inputting grades for?\n");
				subjects();
				if (scanf("%d", &subcho)==0){
					clrscr();
					printf("Invalid input. Please input a number.\n");
					while(getchar()!='\n');
				}
			}while(subcho!=1&&subcho!=2&&subcho!=3&&subcho!=4&&subcho!=5);
			do{
				printf("What type of assignment is this grade for?\n");
				assigntype();
				if(scanf("%d", &asscho)==0){
					clrscr();
					printf("Invalid input. Please input a number.\n");
					while(getchar()!='\n');
				}
			}while(asscho!=1&&asscho!=2&&asscho!=3&&asscho!=4);
					
			do{
				printf("How many questions did the assignment have?\n");
				if (scanf("%d", &denom)==0){
					clrscr();
					printf("Invalid input.Please input a number.\n");
					while(getchar()!='\n');
				}
			}while(denom!=0);
			
			switch (asscho)
			{
				case 1: weight=0.4;
					break;
				case 2: weight=0.3;
					break;
				case 3: weight=0.2;
					break;
				case 4: weight=0.1;
					break;
			}
			*assignments=asscho;
			assignments++;

			switch (subcho)
			{
				case 1:
					for (i7=0;i7<num;i7++)
					{
						printf("How many did %s get right?", stud[i7].fname);
						scanf("%d", &correct);
						*stud[i7].grad.gradesMath=100*weight*(correct/denom);
						stud[i7].grad.gradesMath++;
					}
					break;
				case 2:
					for (i7=0;i7<num;i7++)
					{
						printf("How many did %s get right?", stud[i7].fname);
						scanf("%d", &correct);
						*stud[i7].grad.gradesEng=100*weight*(correct/denom);
						stud[i7].grad.gradesEng++;
					}
					break;
				case 3:
					for (i7=0;i7<num;i7++)
					{
						printf("How many did %s get right?", stud[i7].fname);
						scanf("%d", &correct);
						*stud[i7].grad.gradesSci=100*weight*(correct/denom);
						stud[i7].grad.gradesSci++;
					}
					break;
				case 4:
					for (i7=0;i7<num;i7++)
					{
						printf("How many did %s get right?", stud[i7].fname);
						scanf("%d", &correct);
						*stud[i7].grad.gradesHist=100*weight*(correct/denom);
						stud[i7].grad.gradesEng++;
					}
					break;
				case 5:
					for (i7=0;i7<num;i7++)
					{
						printf("How many did %s get right?", stud[i7].fname);
						scanf("%d", &correct);
						*stud[i7].grad.gradesSpan=100*weight*(correct/denom);
						stud[i7].grad.gradesSpan++;
					}
					break;			
			}
	}
	free(lname);
	free(user);
	free(pass);
	free(fname);
	free(bdays);
	free(addresses);
	free(wholeName);
	free(address);
	free(birthday);
	fclose(class);


	return 0;
}
