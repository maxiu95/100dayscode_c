#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *choices[] = {
	"    _______\n"
    "---'   ____)\n"
    "      (_____)\n"
    "      (_____)\n"
    "      (____)\n"
    "---.__(___)\n",

    "   _______\n"
	"---'   ____)____\n"
	"          ______)\n"
	"          _______)\n"
	"         _______)\n"
	"---.__________)\n",

	"    _______\n"
	"---'   ____)____\n"
	"          ______)\n"
	"       __________)\n"
	"      (____)\n"
	"---.__(___)\n",
};

const int MIN = 0;
const int MAX = 2;

int check_input(char *input);
void generate_comp(int *comp);
void print_result(int user, int comp);

int main(void) {
	srand(time(NULL));
	char user_input; 
	int user_choice, comp_choice;
	printf("What do you choose? [R]ock, [P]aper or [S]cissors: ");
	scanf("%c", &user_input);
	user_choice = check_input(&user_input);
	generate_comp(&comp_choice);
	printf("\n==YOU==\n%s\n", choices[user_choice]);
	printf("\n==COMPUTER==\n%s\n", choices[comp_choice]);
	print_result(user_choice, comp_choice);
	
	return 0;
}

int check_input(char *input) {
	*input = toupper(*input);
	switch(*input) {
	case 'R':
		return 0;
	case 'P':
		return 1;
	case 'S':
		return 2;
	}
	return -1;
}

void generate_comp(int *comp) {
	*comp = rand() % (MAX - MIN + 1) + MIN;
}

void print_result(int user, int comp) {
	if(user == comp) {
		printf("DRAW!\n");
	}
	else if(user == 0 && comp == 2 
			|| user == 1 && comp == 0
				|| user == 2 && comp == 1) {
		printf("WIN!\n");
	}
	else if(user == 2 && comp == 0 
			|| user == 0 && comp == 1
				|| user == 1 && comp == 2) {
		printf("LOSE!\n");
	}
}
