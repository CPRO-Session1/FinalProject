#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WORD
{
	char name[20];
	int count;
};

int countWordFrequency(struct WORD word[5000])
{
	int i,j,last;
	int present=0;
	int wordnum=0;
	char c;
	char tempword[20];
	char filename[30];
	FILE *fp;

	//type in the name of the document and open it
	puts("Type in the name of the file:");
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL)
	{
		printf("We can't open the file.\n");
		exit(0);
	}

	while(!feof(fp))
	{
		c=getc(fp);
		last=present;
		if((c!=' ')&&(!feof(fp))&&(c!='\n')&&(c!='\r'))
		{
			present=1;
			if(last==0)
			{
				i=0;
				tempword[i]=c;
				i++;
			}else{
				tempword[i]=c;
				i++;
			}
		}else{
			present=0;
			if(last==1)
			{
				tempword[i]='\0';
				for(j=0;j<wordnum;j++)
					if(strcmp(word[j].name,tempword)==0)
					{
						word[j].count++;
						break;
					}
				if(j==wordnum)
				{
					wordnum++;
					strcpy(word[j].name,tempword);
					word[j].count=1;
				}
			}
		}
	}    //end of while
	fclose(fp);
	return(wordnum);
}    //end of countWordFrequency()

void saveWord(struct WORD word[5000],int wordnum){
	int i;
	char filename[30];
	FILE*fp;

	//type in a name for the file,and open it in the pattern of writing
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL){
		printf("We can't open the file.\n");
		exit(0);
	}

	//write the data into the file
	fprintf(fp,"The number of words are %d\n",wordnum);
	for(i=0;i<wordnum;i++)
		fprintf(fp,"%s,%d\n",word[i].name,word[i].count);
	fclose(fp);
}


void sortWord(struct WORD word[5000],int wordnum){
	int i,j,max,temp;
	char tempname[20];

	for(i=0;i<wordnum-1;i++){
		max=i;
		for(j=i+1;j<wordnum;j++)
			if(word[max].count<word[j].count)
				max=j;
		if(max!=j){
			strcpy(tempname,word[max].name);
			strcpy(word[max].name,word[i].name);
			strcpy(word[i].name,tempname);
			temp=word[max].count;
			word[max].count=word[i].count;
			word[i].count=temp;
		}
	}
}


void main(){
	int wordnum;
	struct WORD word[5000];

	int countWordFrequency(struct WORD word[]);
	void saveWord(struct WORD word[],int wordnum);
	void sortWord(struct WORD word[5000],int wordnum);

	wordnum=countWordFrequency(word);
	puts("Input the unsorted file names for writing:");
	saveWord(word,wordnum);

	sortWord(word,wordnum);
	puts("Input the dorted file names for writing:");
	saveWord(word,wordnum);
}
