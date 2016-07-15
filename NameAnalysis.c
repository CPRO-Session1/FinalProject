#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

const int max = 4428; //This is the hard-coded number of names/lines in the data file

typedef struct nameProfile {
	char name[100];
	int yearData[11];
	float average;
	float standdev;
} nprof; //This creates a structure to store the various data corresponding to an inputted name


void storeNames(nprof *storage, FILE *census) { //This function stores all the names and their data in an struct array for easy access but doesn't calculate average or standard deviation, because it is more efficient to only calculate those values for the names the user enters.
	for (int i = 0; i < max; i++) {
		char temp[100];
		fgets(temp, sizeof(temp), census);
		char * ptr;
		ptr = strtok(temp, " ");
		strcpy(storage[i].name,ptr);
		int index = 0;
		ptr = strtok(NULL, " ");
		while (ptr != NULL) {
			storage[i].yearData[index] = atoi(ptr);
			ptr = strtok(NULL, " ");
			index++;
		}

		printf("\n");
	}
}

int main()
{
	FILE *census;
	census = fopen("CensusData.txt", "r");
	nprof storage[max];
	storeNames(storage, census);
	printf("Welcome to the name analysis program! Using US census data, this program displays\n");
	printf("various statistics to any given name, including popularity by decade as well as\n");
	printf("the average popularity and standard deviation across the 20th century.\n");
	printf("\nLet's begin!\n\n");

	int notFound = 0;
	printf("Please enter a name (First letter uppercase followed by lowercase, first names only):\n");
	char *temp = (char*) malloc(sizeof(char)); //Creates a dynamic array to prevent data loss as well as allow comparison with the names in the structures
	char c;
	int i = 0, j = 1;
	while (c != '\n') { //This reads character by character from input and reallocates the array size as neccessary (idea taken from stackoverflow, link in the README)
		c = getc(stdin);
		temp = (char*)realloc(temp, j * sizeof(char));
		temp[i] = c;
		i++;
		j++;
	}
	temp[i - 1] = '\0';
	for (int i = 0; i < max; i++) { //This is the loop that compares the inputted name with the array of name structures
		if (!(strcmp(storage[i].name, temp))){ //Tests the names for equality
			printf("\nName: %s\n", storage[i].name);
			storage[i].average = 0.0;
			for (int j = 0; j < 11; j++) { //prints data for each decade
				printf("%d: %d\n", 1900 + j * 10, storage[i].yearData[j]);
				storage[i].average += storage[i].yearData[j];
			}
			storage[i].average /= 11;
			printf("Average: %f\n", storage[i].average);
			storage[i].standdev = 0.0;
			for (int j = 0; j < 11; j++) { //Calculates standard deviation
				storage[i].standdev += (storage[i].yearData[j] - storage[i].average) * (storage[i].yearData[j] - storage[i].average);
			}
			storage[i].standdev /= 10;
			storage[i].standdev = sqrt(storage[i].standdev);
			printf("Standard Deviation: %f\n", storage[i].standdev);
			notFound++;
		}
	}
	if (notFound == 0) {
		printf("That name was not found.\n");
	}
	// This closes the dynamic array for the input name as well as the census file.
	free(temp); 
	fclose(census);
	return 0;
}




