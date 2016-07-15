/*Lloyd Page*/
/*Nation sim with optimized sorts and text based commands*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>//included to handle invalid input
typedef struct nation
{
	float militaryStrength;
	float stability;
	float expenses;
	float revenue;
	char* govType;
}nation;
int start(int);
int lines(int,FILE*);
void saveFile(char**,int);
void init(char**,FILE*,int);
void Run(char**,int,nation);
void govType(char**);
int main()
{
	int choice=start(choice);
	if(choice==3)
		return 0;
	FILE* in;	
	char line[BUFSIZ]="default.txt";
	int x=0;
	if(choice==2)
	{
		printf("Enter your save file name\n");
		if(fgets(line,sizeof(line),stdin)==NULL)
			exit(1);
		line[strlen(line)-1]='\0';
	}
	x=access(line,R_OK);
	if(x!=0)
		strcpy(line,"default.txt");
	in=fopen(line,"r");
	rewind(in);
	char c=fgetc(in);
	int count=0;
	while(c!='$')
	{
		count++;
		c=fgetc(in);
	}
	count=lines(count,in);	
	char** changes;
	changes=malloc(count*sizeof(char*));
	init(changes,in,count);
	nation n;
	n.militaryStrength=atoi(*(changes));
	n.stability=atoi(*(changes+1));
	n.expenses=atoi(*(changes+2));
	n.revenue=atoi(*(changes+3));
	n.govType=*(changes+4);
	Run(changes,count,n);
	return 0;
}
void Run(char**changes,int count,nation n)
{
	for(int i=0;i<count;i++)
		printf("%s",*(changes+i));
	int choice;
	while(1)
	{
		int N=3;
		char *line=malloc(N);
		printf("1.Edit government type\n2.Edit economic policies\n3.Edit social policies\n4.Edit military\n5.sort government file\n6.save\n7.quit\n");
		fgets(line, N,stdin);
		size_t last=strlen(line);
		while(line[last-1]!='\n')
		{
			N*=2;
			line=realloc(line,N);
			fgets(line+last,N/2,stdin);
			last=strlen(line);
		}
		if((sscanf(line,"%d",&choice))&&choice<10&&choice>0)
			break;
	}//end of menu selection
	switch(choice)
	{
		case 1:
			govType(changes);
			break;	
		case 2:
//Not implemented	Epolicies(changes);
			break;
		case 3:
//Not implemented	Spolicies(changes);
			break;
		case 4:
//Not implemented	military(changes);
			break;
		case 5:
//Not implemented	sort(changes);
			break;
		case 6:
			saveFile(changes,count);
			break;
		default:
			exit(0);
	}
	Run(changes,count,n);
}
void govType(char**changes)
{
	int choice;
	while(1)
	{
		int N=3;
		char *line=malloc(N);
		printf("1.Democracy\n2.Autocracy\n3.Anarchy\n");
		fgets(line, N,stdin);
		size_t last=strlen(line);
		while(line[last-1]!='\n')
		{
			N*=2;
			line=realloc(line,N);
			fgets(line+last,N/2,stdin);
			last=strlen(line);
		}
		if((sscanf(line,"%d",&choice))&&choice<4&&choice>0)
		{
			free(line);
			break;
		}
		printf("Enter valid input\n");
	}
	switch(choice)
	{
		case 1:
			*(changes+4)="Democracy";
			break;
		case 2:
			*(changes+4)="Autocracy";
			break;
		case 3:
			*(changes+4)="Anarchy";
			break;
	}
}
int start(int choice)//start menu
{
	while(1)
	{
		int N=3;
		char *line=malloc(N);
		printf("1.New Game\n2.Load save\n3.Quit\n");
		fgets(line, N,stdin);
		size_t last=strlen(line);
		while(line[last-1]!='\n')
		{
			N*=2;
			line=realloc(line,N);
			fgets(line+last,N/2,stdin);
			last=strlen(line);
		}
		if((sscanf(line,"%d",&choice))&&choice<4&&choice>0)
		{
			free(line);
			return choice;
		}
		printf("Enter valid input\n");
	}
}
void saveFile(char**changes,int len)
{
	int N=3;
	char *line=malloc(N);
	printf("Enter your save file name\n");
	fgets(line, N,stdin);
	size_t last=strlen(line);
	while(line[last-1]!='\n')
	{
		N*=2;
		line=realloc(line,N);
		fgets(line+last,N/2,stdin);
		last=strlen(line);
	}//grabs name of the writing file
	line[strlen(line)-1]='\0';
	FILE*out=fopen(line,"w");
	for(int i=0;i<len;i++)
	{
		fprintf(out,"%s",*(changes+i));
	}
	fclose(out);
}//creation of save file
int lines(int count,FILE*in)//gets the number of lines within the file
{
	rewind(in);
	int len=0;
	for(int i=0;i<count;i++)
		if(fgetc(in)=='\n')
			len++;
	return len;
}
void init(char**change,FILE*in,int size)
{
	rewind(in);
	for(int i=0;i<size;i++)
	{
		int N=3;
		char *line=malloc(N);
		fgets(line, N,in);
		size_t last=strlen(line);
		while(line[last-1]!='\n')
		{
			N*=2;
			line=realloc(line,N);
			fgets(line+last,N/2,in);
			last=strlen(line);
		}
		*(change+i)=malloc(strlen(line));
		*(change+i)=line;
	}//stores each line from in into string array
	fclose(in);
}
