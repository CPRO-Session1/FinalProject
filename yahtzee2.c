#include <stdio.h> //imports packages to make random numbers and get basic packages
#include <time.h>

//the rolling dice function
int rollDice(char scorecard[][38],int dice [],int topScore, int bottomScore){
	int categoryList[13];//creates the list of categories to check whether the category has been chosen before
	int i,p,q,t,s,z;//creates variables
	int num=1;
	for (i=0;i<13;i++){//runs the loop 13 times to simulate all the roles
		printf("Your Dice are: \n");
		for (p=0;p<5;p++){
			printf("%d ",dice[p]);}
		printf("\n");//prints the dice
		for (q=0;q<2;q++){//runs a loop twice to simulate the two rolls of the dice
			while (num==1){
				int die;
				printf("Enter the number of the die that you want to reroll or hit 6 to roll: ");
				scanf("%d",&die);
				if (die==6)//breaks the loop when the user inputs a 6
				break;
				else if (die > 6)
				printf("That number is too big, pick a different number: \n");
				else
				dice[die-1]=rand()%6+1;}//rerolls the dice that the user choses to reroll
			printf("Your new Dice: \n");
			for (t=0;t<5;t++)
				printf("%d ",dice[t]);//reprints the dice
			printf("\n");}	
		for (s=0;s<27;s++){//prints the scorecard
		if (s%2==1)
		printf("%s\n",scorecard[s]);
		if (s%2==0)
		printf("%s",scorecard[s]);
		}
		printScoreCard(scorecard,dice,categoryList,topScore,bottomScore);
		for (z=0;z<5;z++){//refreshes the dice
			dice[z]=rand()%6+1;}
}
	return 0;
}



int threeOfaKind(int dice[]){
        int i,j,c;//checks for a three of a kind
        for (i=1;i<7;i++){
                c=0;
                for (j=0;j<5;j++){//runs through the dice and checks for like terms. If there are like terms,it adds it to a counter and checks if the counter equals 3
                        if (dice[j]==i){
                        c++;
                        if (c==3){
                        return 1; 
                        }}}}
	return 0;
}      
	

int fourOfaKind(int dice[]){
        int i,j,c;
        for (i=1;i<7;i++){
                c=0;
                for (j=0;j<5;j++){//runs through the dice and checks for like terms and updates a counter, and if it equals for then it works
                        if (dice[j]==i){
                        c++;
                        if (c==4){
                        return 1; 
                        }}}}
return 0;
}      


int yahtzee(int dice[]){
        int i,j,c;
        for (i=1;i<7;i++){
                c=0;
                for (j=0;j<5;j++){//same as above, except for 5 of a kind instead of four or three
                        if (dice[j]==i){
                        c++;
                        if (c==5){
                        return 1; 
                        }}}}
return 0;
}      

int fullHouse(int dice[]){
        int i,j,c1,k,l,c2;
        for (i=1;i<7;i++){
                c1=0;
                for (j=0;j<5;j++){
                        if (dice[j]==i){
                        c1++;
                        if (c1==3){//first part checks if there are exactly three of a certain type of term in the dice
                                for (k=1;k<7;k++){
                                        c2=0;
                                        for (l=0;l<5;l++){
                                                if (dice[j]==i){//second loops checks if there are exactly two of another type of die
                                                        c2++;}
                                        if (c2>1&&c2<3)//if both are true, it returns one
                                        return 1;}}}}}}
        return 0;
}

						
int largeStraight(int dice[]){
        int a,b,c,d,e;//loops through to check if there is a 1,2,3,4,5 in the string, or a 2,3,4,5,6 and returns 1 or zero
        for (a=0;a<5;a++){
                if (dice[a]==1){
                        for (b=0;b<5;b++){
                                if (dice[b]==2){
                                        for (c=0;c<5;c++){
                                                if (dice[c]==3){
                                                        for (d=0;d<5;d++){
                                                                if (dice[d]==4){
                                                                        for (e=0;e<5;e++){
                                                                                if (dice[e]==5){
                                                                                return 1;
                                                                                }}}}}}}}}}
         for (a=0;a<5;a++){
                if (dice[a]==2){
                        for (b=0;b<5;b++){
                                if (dice[b]==3){
                                        for (c=0;c<5;c++){
                                                if (dice[c]==4){
                                                        for (d=0;d<5;d++){
                                                                if (dice[d]==5){
                                                                        for (e=0;e<5;e++){
                                                                                if (dice[e]==6){
                                                                                return 1;
                                                                                }}}}}}}}}}

        return 0;}
int smallStraight(int dice[]){
        int a,b,c,d;//loops for a 1,2,3,4, 2,3,4,5 3,4,5,6 in the string and returns 1 if they are there
        for (a=0;a<5;a++){
                if (dice[a]==1){
                        for (b=0;b<5;b++){
                                if (dice[b]==2){
                                        for (c=0;c<5;c++){
                                                if (dice[c]==3){
                                                        for (d=0;d<5;d++){
                                                                if (dice[d]==4){
                                                                        return 1;}}}}}}}}
         for (a=0;a<5;a++){
                if (dice[a]==2){  
                        for (b=0;b<5;b++){
                                if (dice[b]==3){
                                        for (c=0;c<5;c++){
                                                if (dice[c]==4){
                                                        for (d=0;d<5;d++){
                                                                if (dice[d]==5){
                                                                        return 1; }}}}}}}}
        for (a=0;a<5;a++){
                if (dice[a]==3){
                        for (b=0;b<5;b++){
                                if (dice[b]==4){ 
                                        for (c=0;c<5;c++){
                                                if (dice[c]==5){
                                                        for (d=0;d<5;d++){
                                                                if (dice[d]==6){
                                                                        return 1;}}}}}}}}
        return 0;}

int enterScore(int cat,int dice[],int bottomScore,int topScore){//stores the scores
	int i;
	int c=0;
	if (cat==1){//checks the category that the user chose to enter
		for (i=0;i<5;i++){
			if (dice[i]==1){
			c++;}}//updates the variable to reflect how many ones are in the dice
		topScore+=c;//updates the score to reflect the newly added score
		return topScore;}		
	else if (cat==2){
                for (i=0;i<5;i++){
                        if (dice[i]==2){
                        c++;}}
		c=c*2;
                topScore+=c;
               return topScore;}
	else if (cat==3){
                for (i=0;i<5;i++){
                        if (dice[i]==3){
                        c++;}}
		c=c*3;//the rest do all the same, except they multiply the counter by the number to reflect the value you need to add
                topScore+=c;
                return topScore;}
	else if (cat==4){
                for (i=0;i<5;i++){
                        if (dice[i]==4){
                        c++;}}
                c=c*4;
                topScore+=c;
                return topScore;}
	else if (cat==5){
                for (i=0;i<5;i++){
                        if (dice[i]==5){
                        c++;}}
                c=c*5;
                topScore+=c;
                return topScore;}
	else if (cat==6){
                for (i=0;i<5;i++){
                        if (dice[i]==6){
                        c++;}}
                c=c*6;
                topScore+=c;
                return topScore;}
	else if (cat==7){
		if (threeOfaKind(dice)==1){
			for (i=0;i<5;i++){
				c=c+dice[i];}//add up the total of the dice to add to the scorecard variable
			bottomScore+=c;
			return bottomScore;}}
	else if (cat==8){
                if (fourOfaKind(dice)==1){
                        for (i=0;i<5;i++){
                                c=c+dice[i];}
                        bottomScore+=c;
                        return bottomScore;}}
	else if (cat==9){
		if (fullHouse(dice)==1){
			bottomScore+=25;//adds 25, or 30, or 40, or 50 depending on the the category
			return bottomScore;}}
	else if (cat==10){
		if (smallStraight(dice)==1){
			bottomScore+=30;
			return bottomScore;}}
	else if (cat==11){
		if (largeStraight(dice)==1){
			bottomScore+=40;
			return bottomScore;}}
	else if (cat==12){
		if (yahtzee(dice)==1){
			bottomScore+=50;
			return bottomScore;}}
	else if (cat==13){
		for (i=0;i<5;i++){
			c+=dice[i];}
		bottomScore+=c;
		return bottomScore;}	
}

int printScoreCard(char scorecard[][38],int dice[],int categoryList[],int topScore,int bottomScore){
	int cat,i,s;
	int c=0;
	printf("enter the category you want to fill: ");
	scanf("%d",&cat);//takes the category the user enters
	while (cat>13){
		printf("That number is too big. pick again: \n");
		scanf("%d\n",&cat);}//tells the user to repick the category if they pick an invalid one
	if (cat==1)
	{	
	if (categoryList[0]==1){
			printf("That one is already filled. Pick again: ");
			scanf("%d\n",&cat);}//tells you to repick if you picked an already chosen value
		else{
			categoryList[0]=1;//updates the category list
			printf("in ones category\n");
			enterScore(cat,dice,bottomScore,topScore);//calls the score entering function
			for (i=0;i<5;i++){
                        if (dice[i]==1)
                        c+=1;}
			sprintf(scorecard[1],"%d",c);//converts the score of the dice in that category into a string and updates the string value with the new string
			for (s=0;s<27;s++){//reprints the updated array
                	if (s%2==1)//the rest all do the same
                	printf("%s\n",scorecard[s]);
               		if (s%2==0)
                	printf("%s",scorecard[s]);}
	}}
	else if(cat==2)
        {
        if(categoryList[1]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[1]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        if (dice[i]==2)
                        c+=1;}
			c=c*2;
                        sprintf(scorecard[3],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else if(cat==3)
        {
        if(categoryList[2]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[2]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        if (dice[i]==3)
                        c+=1;}
                        c=c*3;
                        sprintf(scorecard[5],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else if(cat==4)
        {
        if(categoryList[3]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[3]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        if (dice[i]==4)
                        c+=1;}
                        c=c*4;
                        sprintf(scorecard[7],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else if(cat==5)
        {
        if(categoryList[4]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[4]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        if (dice[i]==5)
                        c+=1;}
                        c=c*5;
                        sprintf(scorecard[9],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else if(cat==6)
        {
        if(categoryList[5]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[5]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        if (dice[i]==6)
                        c+=1;}
                        c=c*6;
                        sprintf(scorecard[11],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else if(cat==7)
        {
	if (threeOfaKind(dice)==1){
        if(categoryList[6]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[6]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        c+=dice[i];}
                        sprintf(scorecard[13],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
 			sprintf(scorecard[13],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==8)
        {
	if (fourOfaKind(dice)==1){
        if(categoryList[7]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[7]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        for (i=0;i<5;i++){
                        c+=dice[i];}
                        sprintf(scorecard[15],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
			sprintf(scorecard[15],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==9)
        {
	if (fullHouse(dice)==1){
        if(categoryList[8]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[8]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        sprintf(scorecard[17],"%d",25);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
			sprintf(scorecard[17],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==10)
        {
	if (smallStraight(dice)==1){
        if(categoryList[9]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[9]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        sprintf(scorecard[19],"%d",30);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
			sprintf(scorecard[19],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==11)
        {
	if (largeStraight(dice)==1){
        if(categoryList[10]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[10]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        sprintf(scorecard[21],"%d",40);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
			sprintf(scorecard[21],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==12)
        {
	if (yahtzee(dice)==1){
        if(categoryList[11]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[11]=1;
                        enterScore(cat,dice,bottomScore,topScore);
                        sprintf(scorecard[23],"%d",50);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}
	else{
			sprintf(scorecard[23],"%d",0);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}}}
	else if(cat==13)
        {
        if(categoryList[12]==1){
                        printf("That one is already filled. Pick again: ");
                        scanf("%d\n",&cat);}
                else{
                        categoryList[12]=1;
                        enterScore(cat,dice,bottomScore,topScore);
			for (i=0;i<5;i++)
			c+=dice[i];
                        sprintf(scorecard[25],"%d",c);
                        for (s=0;s<27;s++){
                        if (s%2==1)
                        printf("%s\n",scorecard[s]);
                        if (s%2==0)
                        printf("%s",scorecard[s]);}
        }}



}
int main(){
	int topScore;
	int bottomScore;
	int totalScore;//creates the total score variable that will eventually print the sum of the top and bottom sections.
	char scorecard[26][38] = {"1)Ones: ", "0", "2)Twos: ", "0","3)Threes: ","0","4)Fours: ","0","5)Fives: ","0","6)Sixes: ","0","7)Three of a Kind (Sum of the dice): ","0","8)Four of a kind (Sum of the dice): ","0", "9)Full House (25): ","0","10)Small straight (30): ","0","11) Large Straight (40): ","0", "12) Yahtzee (50): ","0","13) Chance: ","0"};//creates a two dimensional array that serves as the scorecard, with the first dimension being the number of terms, and the second being the number of max characters
	srand(time(NULL));//creates the time that initializes the random generator
	int board[] = {rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1,rand()%6+1};//creates the board
	rollDice(scorecard,board, topScore, bottomScore);//calls the rolldice function
	if (topScore>63){//if the top score is greater than 63, it adds the top and bottom together and adds 35 extra and prints it, otherwise it prints just the total score without the 35 point bonus
		totalScore=topScore+35+bottomScore;
		printf("Your total score is: ");
		printf("%d",totalScore);}
	else{
		totalScore=topScore+bottomScore;
		printf("Your total score is: ");
                printf("%d\n",totalScore);}
	return 0;	
}
