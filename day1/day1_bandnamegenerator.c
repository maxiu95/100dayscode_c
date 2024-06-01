#include <stdio.h>
#include <string.h>

int main(void) {
	char city[20];
	char pet[10];
	printf("Welcome to the band name generator.\n");
	printf("Firstly, tell me the name of your hometown: ");
	fgets(city, sizeof(city), stdin);
	city[strcspn(city, "\n")] = '\0';
	printf("Next, tell me the name of a pet: ");
	fgets(pet, sizeof(pet), stdin);
	pet[strcspn(pet, "\n")] = '\0';
	printf("\nBand name: %.19s %.9s!!\n", city, pet);
	return 0;
}

/* 
learning point
	stored string arrays using fgets will end in a newline that will affect combining them
	in a printf, so to combat this we must find where that character is and replace
	it with a null character.
	*/