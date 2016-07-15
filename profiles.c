//Anya Lauria 
//Final Project - Creating profiles 
#include <stdio.h>
#include <string.h> 
#include <math.h> 
#include <stdlib.h> 
#include <time.h> 

int female_names_begin = 0, female_names_end = 5;//Creating an index for all names here
int male_names_begin = 6, male_names_end = 10;
int nonb_names_begin = 11, nonb_names_end = 15;


char allelf_names[][100] = {//Array of all elf names 
   "Luthien Faelivrin",
   "Morwen Miriel",
   "Anie Elensar",
   "Larien Telemnar",
   "Inwe Anwarunya",

   "Elendil Alcarin",
   "Cindar Luinwe",
   "Maglor Mithrandir",
   "Arminas Tewele",
   "Daeron Nenharma",

   "Amrod Culmano",
   "Gilthoniel Minyatur",
   "Feawen Silfilas",
   "Linwe Anwamane",
   "Alasse Taralom"
};

char* elfn(char gender){//This function calculates a new elf name
  int kk;
  if(gender == 'M'){
    kk = (rand() % (male_names_end - male_names_begin)) + male_names_begin;
    return allelf_names[kk];
  }

  else if(gender == 'F'){
    kk = (rand() % (female_names_end - female_names_begin)) + female_names_begin;
    return allelf_names[kk];
  }

  else if(gender == 'B'){
    kk = (rand() % (nonb_names_end - nonb_names_begin)) + nonb_names_begin;
    return allelf_names[kk];
  }
}


char allhob_names[][100] = {//Array of all hobbit names 
  "Rosie-Posie Proudfoot",
  "Pansy Loamsdown",
  "Esmerelda Grubb",
  "Azaeila Sandybanks",
  "Tigerlily Burrows",
  
  "Nob Dogwood",
  "Berilac Gamgee-Took",
  "Bodo Tolkien",
  "Fastolph Sackville-Baggins",
  "Hamson Sandybanks",

  "Dimple Proudfoot",
  "Sancho Hamwich",
  "Olo Bumbleroot",
  "Marmadas Brockhouse",
  "Popo Baggy-Hillocks",

};
 
char* hobbitn(char gender){//This function calculates a new hobbit name
  int kk; 
  if(gender == 'M'){
    kk = (rand() % (male_names_end - male_names_begin)) + male_names_begin;
    return allhob_names[kk];
  }

  else if(gender == 'F'){
    kk = (rand() % (female_names_end - female_names_begin)) + female_names_begin;
    return allhob_names[kk];
  }

  else if(gender == 'B'){
    kk = (rand() % (nonb_names_end - nonb_names_begin)) + nonb_names_begin;
    return allhob_names[kk];
  }

}




int elfa(int age){//This function calculates a new elf age 

  int new_agelf;
  new_agelf = age + 57;
  return new_agelf;
}

int hobbita(int age){//This function calculates a new hobbit age

  int new_agehob;
  new_agehob = age + 20; 
  return new_agehob;
}


int main(){	
  srand(time(0));
  char yes1, yes2, yes3, yes4, yes5, yes6, yes7;//These variables will be used in do while loops for the user to decide	
                                                //if they'd like to continue or start a section over

  printf("\nWelcome to the Middle Earth simulator! This is creating your own profile\n");
   


  char creature; //This variable is for the user to choose what creature they are 
  do{
  printf("\nYou can enter Middle Earth as either an elf or a hobbit- which would you like to be?\n");
 invalid_race:
  printf("'E' for elf||'H' for hobbit||\n"); 
  scanf(" %c", &creature); 
  if(creature != 'E' && creature != 'H'){//Validating input 
    printf("Invalid Input\n\n\n");
    goto invalid_race;
  }
  printf("Enter 'y' to continue, else 'n' to repeat this section\n");
  scanf(" %c", &yes1);
  }while(yes1 != 'y');


  char gender = 0; //In this block of code,  the user chooses a gender
  do{
  printf("\n");
  printf("It is now time for you to build facts about yourself.\n"); 
  printf("First, your identity! What gender do you identify with?\n");
 invalid_gender:
  printf("'F' for female||'B' for non-binary||'M' for male||\n");
  scanf(" %c", &gender); 
  if(gender != 'F' && gender != 'M' && gender != 'B'){//Validating input 
    printf("Invalid Input\n\n\n");
    goto invalid_gender;  
  }
  printf("\n"); 
  printf("\nEnter 'y' to continue, else 'n' to repeat this section\n");
  scanf(" %c", &yes2);
  }while(yes2 != 'y');


  char firstname[20];//In this block of code, the user recieves a name-- a function is called 
  printf("\n\nWonderful! Now, when in Middle Earth, do as the Middle Earthlings do! You need a new name suited for your creature's race.\n");
  char* name;
  if(creature == 'E'){
	  name = elfn(gender);
  }
  else if(creature == 'H'){
	  name = hobbitn(gender);
  }
  do{
  printf("\nEnter you first name!\n"); 
  scanf(" %s", &firstname[20]);
  printf("\nYour new name is %s\n", name);
  printf("\n\nEnter 'y' to continue, else 'n' to repeat this section\n");
  scanf(" %c", &yes3);
  }while(yes3 != 'y');
  
  

  int age;//This block of code calculates the new age as well as average lifespan-- a function is called  
  do{
  printf("\nNow you are going to find out what age you are!\n"); 
 invalid_age:
  printf("To calculate your new age, you first must enter your real age.\n");
  int err = scanf(" %d", &age); 
  if(err != 1){
    printf("Invalid Input\n\n\n");
    goto invalid_age;
  }
  if(creature == 'E'){
    elfa(age); 
    printf("\n\nYour new age is %d! Elves do not physically age- in other words, you are immortal!\n", elfa(age));
    printf("However, Elves can be slain by violence as well as extreme negative emotion- so be careful!\n");
  }
  else if(creature == 'H'){
    hobbita(age);
    printf("\n\nYour new age is %d!\n", hobbita(age)); 
    printf("Hobbits have an average lifespan of 100 years. ");
    printf("They are considered adult at the age of 33, & middle aged at approximately 55.\n");
  }
  printf("\nEnter 'y' to continue, else 'n' to repeat this section\n");
  scanf(" %c", &yes4);
  }while(yes4 != 'y');



  int a;//This block of code allows the user to choose a realm -- I make use of files here
  int b;
  int c;
  int d;
  int realm;
  printf("\n\n\nMiddle Earth is an enormous place ... you do need a community to live in!\n");
  do{
 invalid_realm:
  printf("You have two realms to choose from.\n\n");
  printf("\n'1' for the first option||'2' for the second option\n\n"); 
  if(creature == 'H'){
    FILE *hobbitplace1 = fopen("hobbitplace1.txt", "r"); 
    if(hobbitplace1){
      while ((c = getc(hobbitplace1)) != EOF)
	putchar(c);
      printf("\n");
      fclose(hobbitplace1);
    }

    FILE *hobbitplace2 = fopen("hobbitplace2.txt", "r"); 
    if(hobbitplace2){
      while ((d = getc(hobbitplace2)) != EOF)
	putchar(d);
      printf("\n");
      fclose(hobbitplace2);
    }
  }
  else if(creature == 'E'){
    FILE *elfplace1 = fopen("elfplace1.txt", "r"); 
    if(elfplace1){
      while ((c = getc(elfplace1)) != EOF)
	putchar(c);
      printf("\n");
      fclose(elfplace1);
    }

    FILE *elfplace2 = fopen("elfplace2.txt", "r"); 
    if(elfplace2){
      while ((d = getc(elfplace2)) != EOF)
	putchar(d);
      printf("\n"); 
      fclose(elfplace2);
    }
  }
  scanf(" %d", &realm);
  if( realm != 1 && realm != 2){//Validating input 
    printf("Invalid Input\n"); 
    goto invalid_realm;
  }


printf("\n\nYou will now find out what language you speak!\n");
if(creature == 'E' && realm == 1){//In this block of code, user recieves the dialect they speak
	FILE* quenya = fopen("quenya.txt", "r");
	if(quenya){
		while ((a = getc(quenya)) != EOF)
			putchar(a);
		printf("\n");
		fclose(quenya);
	}
}
else if(creature == 'E' && realm == 2){
	FILE* sindarin = fopen("sindarin.txt", "r");
	if(sindarin){
		while ((a = getc(sindarin)) != EOF)
			putchar(a);
		printf("\n");
		fclose(sindarin);
	}
}
else if(creature == 'H' && realm == 1){
	FILE* hobbitish = fopen("hobbitish.txt", "r");
	if(hobbitish){
		while ((a = getc(hobbitish)) != EOF)
			putchar(a);
		printf("\n");
		fclose(hobbitish);
	}
}
else if(creature == 'H' && realm == 2){
	FILE* stoorish = fopen("stoorish.txt", "r");
	if(stoorish){
		while ((a = getc(stoorish)) != EOF)
			putchar(a);
		printf("\n");
		fclose(stoorish);
	}
}
printf("\nEnter 'y' to continue, else 'n' to repeat this section\n");
scanf(" %c", &yes5);
}while(yes5 != 'y');
	
int job_num;
printf("\nWhether it be in an Elvish community, or a Hobbit community, every inhabitant has a role!\n");
printf("So, it is now time for you to choose your very own role!\n");
do{
printf("These are your options. Keep in mind- if you pick a job in a county you do not live in, you WILL have to commute!\n");
invalid_jobnum:
printf("To pick what job you would like, enter the number listed next to it\n");
if(creature == 'H'){
	FILE* hobbitjobs = fopen("hobbitjobs.txt", "r");
	if(hobbitjobs){
		while ((b = getc(hobbitjobs)) != EOF)
			putchar(b);
		printf("\n");
		fclose(hobbitjobs);
	}
}
else if(creature == 'E' && realm == 1){
	FILE* elfjobs2 = fopen("elfjobs2.txt", "r");
	if(elfjobs2){
		while ((b = getc(elfjobs2)) != EOF)
			putchar(b);
		printf("\n");
		fclose(elfjobs2);
	}
}
else if(creature == 'E' && realm == 2){
	FILE* elfjobs = fopen("elfjobs.txt", "r");
	if(elfjobs){
		while ((b = getc(elfjobs)) != EOF)
			putchar(b);
		printf("\n");
		fclose(elfjobs);
	}
}
scanf("%d", &job_num);
if(job_num != 1 && job_num != 2 && job_num != 3 && job_num != 4 && job_num != 5 && job_num != 6){
	printf("\nInvalid Input\n");
	goto invalid_jobnum;
}
printf("\nEnter 'y' to continue, else 'n' to repeat this section\n");
scanf(" %c", &yes6);
}while(yes6 != 'y');








printf("\n\nYou have come to the end of building your custom profile!\n");//The final profile
printf("This is how everything looks in the end.\n");

if(creature == 'H' && realm == 1){//printing the final profile 
	if(job_num == 1){
	        printf("You are %s, a homely hobbit of The Shire. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job as a cook will propel you along a bright path, though mind you- the Sackville-Bagginses can be a tough bunch!\n", name, hobbita(age));
	}
	else if(job_num == 2){
		printf("You are %s, a homely hobbit of The Shire. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job as a gardener will propel you along a bright path, and Samwise Gamgee is most likely the best employer one can get these days!\n", name, hobbita(age));
	}
	else if(job_num == 3){
		printf("You are %s, a homely hobbit of The Shire. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job as an edior will propel you along a bright path, especially since editing Bilbo's book is an honor indeed!\n", name, hobbita(age));
	}

}
else if(creature == 'H' && realm == 2){
        if(job_num == 4){
		printf("You are %s, a hardy hobbit of Buckland. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job as at the Took Townhouse may not be a dream job, but it will propel you along the path of finding one that is!\n", name, hobbita(age));
	}
	else if(job_num == 5){
		printf("You are %s, a hardy hobbit of Buckland. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job with with the MIDDLE EARTH JOURNEY will probably be exciting enough to be the only job in your lifetime! Safe travels, dear hobbit!\n", name, hobbita(age));
	}
	else if(job_num == 6){
		printf("You are %s, a hardy hobbit of Buckland. At the age of %d, you have achieved plenty, yet still have much to achieve! Your job as an assistant party planner will be delightful, and there are surely many more to come your way!\n", name, hobbita(age));
	}
}
else if(creature == 'E' && realm == 1){//At this point I realized perhaps I should have done these ifs under job_num 
	if(job_num == 1){
		printf("You are %s, an ancient elf of Lothlorien. Your age doesn't matter, though you are %d. Your job in Tengwar, an elvish library, will propel you along your path of learning and education- though in this situation, one may hope books are your refuge... 100,000 is a lot.\n", name, elfa(age));
	}
        else if(job_num == 2){
		printf("You are %s, an ancient elf of Lothlorien. Your age doesn't matter, though you are %d. Your job as a researcher will propel you along your path of discovery and learning. Safe travels, mighty elf.\n", name, elfa(age));
	}
        else if(job_num == 3){
		printf("You are %s, an ancient elf of Lothlorien. Your age doesn't matter, though you are %d. Your job as a guardian will bring to you many trials, but you will surely reap your rewards, as you are sure to learn a lot from Galadriel.\n", name, elfa(age));
	}
	
}
else if(creature == 'E' && realm == 2){
        if(job_num == 1){
		printf("You are %s, a regal elf of Rivendell. Your age doesn't matter, though you are %d. Your job as a messenger will take you to many corners of the world, and you will see and learn a lot. Safe travels, mighty elf.\n", name, elfa(age));
	}
        else if(job_num == 2){
		printf("You are %s, a regal elf of Rivendell. Your age doesn't matter, though you are %d. Your job as a potions master will reveal to you mysteries of the world you may not have realized even existed. Tread carefully, dear elf.\n", name, elfa(age));
	}
        else if(job_num == 3){
		printf("You are %s, a regal elf of Rivendell. Your age doesn't matter, though you are %d. Your position in the elvish army will bring you many trials, but you will grow in both mind and body. Be safe, dear elf.\n", name, elfa(age));
	}
}

printf("\n\n\n\n Would you like to continue and take your avatar through a social interaction, or exit the game?\n");
printf("'y' to continue, else 'n' to exit\n");
char continue1; 
scanf(" %c", &continue1); 
if(continue1 != 'y'){
	goto end_sim;
}
else{
	printf("\n\n\nTo select an option, enter the option number\n");
}

if(creature == 'H'){//SHORT text adventure for Hobbits
printf("\n\nYou have just entered your new house. Work starts tomorrow, and you haven't even begun unpacking.\n");
printf("You know you have no time for some traditional hobbitish pipe and tea, and must get on to packing immediately.\n");
printf("\n\nThere is a knock at your door. It is an exceptionally plump Hobbit.\n");
printf("He says, 'Top of the morning to you! My name is Malcolm Proudfoot, I'm your new neighbour!...'\n");
printf("'...Would you care for a little snack in my humble little hobbit hole? Tea, cheese, bread and ham?'\n");
printf("\n\nYour options are :\n");
printf("|1. No, thank you- I have got to pack. Perhaps another time?|2. Yes, that sounds wonderful!|\n");
int quest1;
scanf(" %d", &quest1);
if(quest1 == 1){
	printf("\n\nHobbits do not decline tea invitations! You are now forever in social exile.\n");
	goto end_sim;
}

printf("\nYou enter his house. His wife and children greet you at the door, and one of the children makes a comment:\n");
printf("'Jeepers mister, you certainly are short for a Hobbit'\n");
printf("\n\nYour options are:\n");
printf("|1.You certainly are ugly, not just for a hobbit!|2.Haha, what a cute boy you have!|3.Bye, I have to go now|\n");
int quest2;
scanf(" %d", &quest2);
if(quest2 == 1){
	printf("\nThat was an unacceptable response! The child is so hurt he won't come out of his room. SOICAL EXILE!\n");
goto end_sim;
}
else if(quest2 == 3){
	printf("\n\nThe Proudfoot family is slightly affronted. They don't let you go. Perhaps you should be careful about what you say hereon.\n");
}

printf("They serve you tea that has clearly gone bad. What do you do?\n");
printf("\n\nYour options are:\n");
printf("|1.You drink the tea|2.You politely take a sip and then surreptiously pour it into a plant|3.You don't drink it|\n");
int quest3;
scanf(" %d", &quest3);
if(quest3 == 2){
	if(quest2 == 3){
		printf("\n\n\nYou should have been more careful! They caught you, and are deeply offended. You are now forever in social exile!\n");
		goto end_sim;
	}
}
if(quest3 == 3){
	printf("A Hobbit never turns down food! You are now forever in social exile!\n");
	goto end_sim;
}

printf("\n\nIt is now time for you to leave, and the Proudfoots cannot wait to have you over again!\n");
printf("Congratulations! You survived your very first social interaction without social exile. Clearly, Hobbit life is for you! This is the end of the sim.\n");
}



else if(creature == 'E'){//SHORT text adventure for Elves
printf("\n\nYou have just entered your new home. Work starts tomorrow, and you haven't even begun unpacking.\n");
printf("You would like to hike around the new area and collect some new specimens, but you know you're short on time.\n");
printf("\n\nThere is a knock on your door. It is an exceptionally tall, intimidating guard elf. He says:\n");
printf("I am Adewale, the local messenger elf. I have been instructed to show you the ropes of weapons allowed here, and also how to use them...\n");
printf("You are slightly offended. The elf has a slightly demeaning look about him, and you know how to use weapons, thank you very much.\n");
printf("What do you say? Your options are:\n");
printf("|1.Okay, let's go.|2.No thank you, I'm busy.|3.Thanks, but no thanks. I know my way around a bow.|\n");
int quest4;
scanf(" %d", &quest4);
if(quest4 == 2){
	printf("\n\nThe elf is slightly affronted, and does not allow you to decline. Perhaps you should be careful abou what you to say hereon.\n");
}
else if(quest4 == 3){
	printf("\n\nYou anger the guard elf, and he binds your hands and puts you in prison. You are imprisoned forever.\n");
	goto end_sim;
}

printf("\n\nThe elf hands you a bow. You accidentally shoot it into a tree, and the elf smirks.\n");
printf("How do you react?\n");
printf("\n\nYour options are:\n");
printf("|1.You ignore him|2.You shoot him|3.You blatantly tell him his height is ridiculous and perhaps he shouldn't scoff\n");
int quest5;
scanf(" %d", &quest5);
if(quest5 == 2){
	printf("\nWOW! You absolutely never hurt a fellow elf. You are shot down by other elves around you.\n");
	goto end_sim;
}
else if(quest5 == 3 && quest4 == 2){
	printf("\nYou had to be careful about your actions! You anger the guard elf, and he imprisions you.\n");
        goto end_sim;
}
else if(quest5 == 3){
	printf("\nThe elf is livid! Perhaps you should be careful about what you say hereon.\n");
}

printf("\n\nThe elf is walking back to your home with you, but accidentally leads you the wrong way.\n");
printf("What do you say?\n");
printf("\n\nYour options are:\n");
printf("|1.You slip away onto the right path, and leave him walking|2.You tell him politely he is going the wrong way|3.You loudly exclaim, 'Wow, how embarassing for you!|\n");
int quest6;
if(quest6 == 1 && quest5 == 3){
	printf("\nWrong choice! You angered the elf, and he imprisons you!\n");
	goto end_sim;
}
else if(quest6 == 1 && quest4 == 2){
	printf("\nWrong choice! You angered the elf, and he imprisons you!\n");
	goto end_sim;
}
else if(quest6 == 3){
	printf("\nYou cannot say that to a guard elf! He is angered, and imprisons you!\n");
	goto end_sim;
}

printf("\n\nCongratulations! You survived your first social interaction without being imprisoned for life! Clearly, elf life is the life for you!\n");
}


end_sim:
return 0; 


}
