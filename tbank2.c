//Clarke Littlejohn
//I thought of a why to use loops as i was going to use recursive but it was causing 
//things to be slower and amny bugs. Did not any thing useful for
#include<stdio.h>
#include<string.h>
#include <unistd.h>
#include<sys/stat.h>
#include<stdlib.h>

void cS()
{
	int i=0;
	for(;i<5;i++){
		printf("\n");
	}
}
	
typedef struct{

	float bal;
	char fName[100];
	char lName[100];
	char Username[12];
	char password[100];
}bankUser;

int signup(bankUser);
bankUser signin(bankUser);
void menu(int,bankUser);
void deposit(bankUser);
void withdraw(bankUser);
void transfer();

char * concat(char *one, char *two){
	 	char a[(sizeof(one)+sizeof(two)-4)];
	 	int i=0;
	  	while(*one!='\0'){
		    		a[i]=*one;
		     		one++;
		      		i++;
		       	}
	    	while(*two!='\0'){
		     		a[i]=*two;
		      		two++;
		       		i++;
		        	}
	     	a[i]='\0';
	      	one=a;
	       	return one;
	        }
int init();

void update();

int main(){
	int i =0;
	for(;i<45;i++){
		printf("\n");
	}
		init();
		bankUser init;
		menu(0,init);


	return 0;}

int init(){
				FILE* setup = fopen("users.txt","r");
				if(setup==NULL){
					setup=fopen("users.txt","w");
					fclose(setup);
					mkdir("./BANK",0700);
				}
				else
					fclose(setup);
		return 0;
}

bankUser signin(bankUser user){
	int i=1;
	char input[100];
	char unCheck[11];
	char opnFldr[100];
	printf("\nEnter your username: ");
	fgets(input,sizeof(input),stdin);
	input[strlen(input)-1]='\0';	
	
	strcpy(opnFldr,"./BANK/");
	strcpy(opnFldr,concat(opnFldr,input));
	strcpy(opnFldr,concat(opnFldr,"/account.txt"));

	
	FILE* infile = fopen("users.txt","r");
		while(!feof(infile)){
			fscanf(infile,"%s",unCheck);
			if(strcmp(unCheck,input)==0){
				i=0;
				fclose(infile);
				FILE* infile2 = fopen(opnFldr,"r");
				fscanf(infile2,"%s",input);
				strcpy(user.fName,input);
				fscanf(infile2,"%s",input);
				strcpy(user.lName,input);
				fscanf(infile2,"%s",input);
				strcpy(user.password, getpass("Enter your password. "));
				while(strcmp(input,user.password)!=0)
				{
					strcpy(user.password, getpass("Invalid Password. Reenter your password or type quit to quit: "));
					if(strcmp(user.password,"quit")==0){
						strcpy(user.fName,"back");
						return user;
					}
				}
				fclose(infile2);
			return user;	
			}
		}
		if (i==1){
			printf("Username not found.");
			strcpy(user.fName,"back");
		}
	return user;
}

void deposit(bankUser user){
		cS();
}
			

void withdraw(bankUser user){
		cS();
}

void history(){
		cS();
}

int signup(bankUser user){

		cS();
			
			char input[100];
			char name[100];
			
			char folderS[] = {"./BANK/"};
			char unCheck[12];
			
			char newline = '\n';
			FILE * infile= fopen("users.txt","r");

			printf("\nIf you didnt mean to sign up for an account type back.\nEnter a username that is no longer than ten characters: ");

			fgets(input,sizeof(input),stdin);
			input[strlen(input)-1]='\0';	

			while(!(feof(infile))){

					fscanf(infile,"%s",unCheck);
					if(strcmp("back",input)==0)
						break;
					
					if(strlen(input)>10){
						printf("\nYour username is too long.");
						printf("\nIf you didnt mean to sign up for an account type back.");
						printf("\nEnter a username that is no longer than ten characters: ");
						fgets(input,sizeof(input),stdin);
						input[strlen(input)-1]='\0';	
						continue;
					}
					if(strcmp(input,unCheck)==0){
						printf("\nThat username is taken.");
						printf("\nIf you didnt mean to sign up for an account type back.");
						printf("\nEnter a username that is no longer than ten characters: ");
						rewind(infile);
						fgets(input,sizeof(input),stdin);
						input[strlen(input)-1]='\0';	
						continue;
					}
			}
			fclose(infile);
				
			if(strcmp("back",input)==0)
				return 10;
			strcpy(user.Username,input);
			char * test="./BANK/";
			char * temp=concat(test,input);
			char * temp2= concat(temp,"/account.txt");

}

void menu(int i, bankUser user){
	char input[100];
 	cS();
		printf("\n\n\tOnline Banking Simulator\n");


		printf("\nType signin to signin.\nType signup to signup.\n ");


			fgets(input,sizeof(input),stdin);
			input[strlen(input)-1]='\0';	
			if(strcmp(input,"signin")==0)
				signin(user);
			else if(strcmp(input,"signup")==0)
				signup(user);

	
}
