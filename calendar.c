//fix character input
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct {
	int hour; //user input hour for event
	int min; //user input minute
	char name[100]; //name of event
}event;
//where to print menu
bool check (const event *e){
	return e==NULL;
} //check if event is NULL
event *UIEvent(){
	event *e = (event*) malloc(sizeof(event));
	e->hour=0;
	e->min=0;
	strcpy(e->name,"");
	return e;
} //defining event
//add selection (range)
int range1(const int minimum, const int maximum){
	int input=0;
	int test=0;
	char temp[15];
labelh:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
	       printf("Incorrect input, please try again: ");
	       goto labelh;
       }
       return input;
}
int range2(const int minimum, const int maximum){
	int input=0;
	int test=0;
	char temp[15];
labelm:scanf("%2d",&input);
       if(input>=minimum||input<=maximum){
       }else{
	       printf("Incorrect input, please try again: ");
	       goto labelm;
       }
       return input;
}
event *NewEvent(event *e){
	if(check(e)){
		e=UIEvent();
	}
	system("setterm -bold on");
	printf("\n \n  New  Event  Selected  \n \n");
	system("setterm -bold off");
	printf("Enter hour (0-23): ");
	e->hour=range1(0,23);
	printf("Enter minute (0-59): ");
	e->min=range2(0,59);
	puts("\n     EVENT NAME     \n");
	printf("Please include event name or description: ");
	fgets(e->name,100,stdin);
	fgets(e->name,100,stdin);
	puts(" ----------------------------------");
	system("setterm -bold on");
	puts(" \nEvent Added.");
	system("setterm -bold off");
	return e;
} //initializing event
void AddEvent(event list[],const event e, const int x){
	if(check(&e)){
		return;
	}
	list[x].hour=e.hour;
	list[x].min=e.min;
	strcpy(list[x].name,e.name);
}//adding events to a list
//sorting the order of time of the events in a day
void sort (event list[],const int size){
	int x,y,storeh2,storem2;//store h for hour, m for min, 1 and 2, depend on arr
	char name2[100];
	for (x=1;x<size;x++){
		for(y=x;y>0&&(list[y-1].hour>list[y].hour)||
				(list[y-1].hour==list[y].hour)&&(list[y-1].min>list[y].min);y--){
			storeh2=list[y-1].hour;
			storem2=list[y-1].min;
			strcpy(name2,list[y-1].name);
			//event 2 ^
			list[y-1].hour=list[y].hour;
			list[y-1].min=list[y].min;
			strcpy(list[y-1].name,list[y].name);
			//switch the two around using the temporary storage
			list[y].hour=storeh2;
			list[y].min=storem2;
			strcpy(list[y].name,name2);
		}
	}
}
void CorrectSort (event list[], int *size, event e){
	AddEvent(list,e,*size);
	(*size)++;
	sort(list,*size);
}
void printEvent(const event e){ //<---printevent sourced by: stackexchange.com
	char hour1 = {(e.hour/10)+ '0'};//first digit
	char hour2 = {(e.hour-(e.hour/10)*10)+'0'};
	char min1 = {(e.min/10)+'0'};
	char min2 = {(e.min-(e.min/10)*10)+'0'};
	printf("%c%c:%c%c  ~%s\n",hour1,hour2,min1,min2,e.name);
}
void printList(const event list[],const int size){
	if(size==0){
		puts("\n You have no events scheduled. \n");
	}
	system("setterm -bold on");
	printf("\n Schedule: \n");
	system("setterm -bold off");
	for(int x=0;x<size;x++){
		printf(" [%d]  ",x);
		printEvent(list[x]);
	}
}
void deleteEvent(event list[],int *size){
	int x;
	if(*size==0){
		puts("\n You have no events to delete. \n");
		return;
	}
	char temp[100];
	int locate;
	system("setterm -bold on");
	printf("\n    DELETE EVENT   \n");
	system("setterm -bold off");
	printf("\n Enter event number you want to delete: ");
	fgets(temp,100,stdin);
	fgets(temp,100,stdin);
	strtok(temp,"\n");
	locate = atoi(temp);
	//locate=locate-y;
	if(locate>*size-1){
		printf(" \n No event found \n");
		return;
	}
	list[locate].hour=70;
	list[locate].min=70;
	strcpy(list[locate].name,"");
	sort(list,*size);
	(*size)--;
}

void menu(){
	printf("Press 1: to create event\n");
	printf("Press 2: to delete event\n");
	printf("Press 3: to exit\n\n");
	//main to function calendar
}
int main () {
	system("clear");
	event list[15];
	static const char* MonthDisplay[]={
		"January","February","March","April","May","June","July","August","September",
		"October","November","December"
	};
	int year, month, day,leap=0,x, day2;
	int count=0;
	char temp[100];
	signed char c; //userinput for calendar change
	int MonthArray[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	system("setterm -bold on"); //bold header
	printf("Events Calendar \n");
	system("setterm -bold off");
label1:printf("Enter year: ");
       scanf("%d",&year); //user input year
       if (year<0){
	       printf("Not a suitable year. \n");
	       goto label1; //label 1 for incorrect year input
       }
label2:printf("Enter month: ");
       scanf("%d", &month); //user input month
       if(!(month<13) || !(month>0)){
	       printf("Not a suitable month. \n");
	       goto label2; //label 2 for incorrect month input
       }
label3:printf("Enter day: ");
       scanf("%d", &day); //user input day
       if (day<1||day>31){
	       printf("Not a suitable day. \n");
	       goto label3;
       }else if(month==4||month==6||month==9||month==11){ //wrong input for 30 days
	       if (day>30){
		       printf("Not a suitable day. \n");
		       goto label3;
	       }
       }else if (month==2){ //wrong input for feb
	       if ((year%4)==0&&(year%100!=0)||(year%400==0)){ //leap year possibility
		       MonthArray[1]=29;
		       if(day>29){ //29 days
			       printf("Not a suitable day. \n");
			       goto label3;
		       }
	       }else{
		       if(day>28){ //28 days
			       printf("Not a suitable day. \n");
			       goto label3;
		       }
	       }
       }
       //printing calendar
       int DetermineDay;
label4:system("clear");
       x=1;
       DetermineDay=(x+=month<3?year:year-2,23*month/9+x+4+year/4-year/100+year/400)%7;
       if((year%4)==0&&(year%100!=0)||(year%400==0)){
	       MonthArray[1]=29;
	       if(month==1||month==2){
		       DetermineDay--;
		       if (DetermineDay<0){
			       DetermineDay=6;
		       }
	       }
       }else{
	       MonthArray[1]=28;
       }
       //Above line source:cadaeit.net
       system("setterm -bold on"); //bold header
       printf("\n         %s    %d \n", MonthDisplay[month-1],year); //header
       printf("\nSUN  MON  TUE  WED  THU  FRI  SAT\n");
       system("setterm -bold off");
       for(day2=1;day2<=DetermineDay;day2++){ //day2 is counter
	       printf("     ");
       } //initialize first day position
       printf(" ");
       for (day2=1;day2<=MonthArray[month-1];day2 = day2 + 1){
	       //fills calendar
	       if(day==day2){ //make output red
		       printf("\e[5;31;40m%2d\e[0m",day); //does not blink
	       }else{
		       printf("%2d",day2);
	       }
	       if(((day2+DetermineDay)%7) > 0) { //move on to next line after saturday
		       printf("   ");
	       }else{
		       printf("\n ");
	       }
       }
       //try to bold user input day
       printf("\n\n");
       //display day:
label5:printf("You have selected %s %d, %d \n",MonthDisplay[month-1],day,year);
       //display events
       //load from output file :(
       printList(list,count);
       //directions for user input
       printf("   - To switch between days, use (a) for previous day and (d) for the next day. \n");
       printf("   - To switch between months, use w (previous) and s (next).\n\n");
       menu();
       scanf("%c",&c);
       if(c=='\n'){
	       scanf("%c",&c);
       }
       while(c!=3){
	       if(c=='1'){
		       CorrectSort(list,&count,*NewEvent(&list[count]));
		       //save(list,count);
		       goto label4;
	       }else if(c=='2'){
		       deleteEvent(list,&count);
		       //save(list,count);
		       goto label4;
	       }else if(c=='3'){
		       system("clear");
		       system("setterm -bold on");
		       printf("\n\n\n HAVE A GREAT DAY WHILE I CODE THIS!!  :)) \n\n\n\n");
		       system("setterm -bold off");
		       break;
	       }else if(c=='w'){ //previous month
		       if(month==1){
			       year--;
			       month=12;
		       }else{
			       month--;
		       }
		       if(day>MonthArray[month-1]){
			       day=MonthArray[month-1];
		       }
		       goto label4;
	       }else if(c=='s'){ //next month
		       if(month==12){
			       month=1;
			       year++;
		       }else{
			       month++;
		       }
		       if(day>MonthArray[month-1]){
			       day=MonthArray[month-1];
		       }
		       goto label4;
	       }else if(c=='a'){ //previous day
		       if(day==1){
			       month--;
			       day=MonthArray[month-1];
		       }else{
			       day--;
		       }goto label4;
	       }else if(c=='d'){ //next day
		       if (day==MonthArray[month-1]){
			       day=1;
			       month++;
		       }else{
			       day++;
		       }
		       goto label4;
	       }else{
		       printf("Invalid response. Please try again. \n");
		       goto label4;
	       }
       }
       return 0;
}
