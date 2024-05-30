#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_arguments(int argc, char **argv, char **flag, int *shift_amount, char **message);
void free_memory(char *flag, char *message);
void encrypt_message(int shift_amount, char *message);
void decrypt_message(int shift_amount, char *message);

int main(int argc, char **argv) {
	char *flag = NULL;
	int shift_amount = 0;
	char *message = NULL;

	if(!check_arguments(argc, argv, &flag, &shift_amount, &message)) {
		// if errors in parsing args to variables return error and end program with 1;
		free_memory(flag, message); // check to free any memory that may have been created in the process of parsing before fail
		return 1;
	}
	if(strcmp(flag, "-e") == 0) {
		encrypt_message(shift_amount, message);
	}
	else if(strcmp(flag, "-d") == 0) {
		decrypt_message(shift_amount, message);
	}

	free_memory(flag, message);
	return 0;
}

bool check_arguments(int argc, char **argv, char **flag, int *shift_amount, char **message) {
	// check correct number of arguments & printing error
	if(argc != 4) {
		fprintf(stderr, "[ERROR]: Incorrect usage.\n[USAGE]: <program> <-e/-d> <shift_amount> <message>\n");
		return false;
	}
	for(int i = 1; i < argc; i++) {
		switch(i) {
		case 1:
			// checking correct flag for encrypyt/dectrypt & printing error
			if(strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "-d") != 0) {
				fprintf(stderr, "[ERROR]: Incorrect usage.\n[USAGE]: <program> <-e/-d> <shift_amount> <message>\n");
				return false;
			}
			// allocate memory for flag variable to correct size & printing error if failed
			*flag = malloc(strlen(argv[1]) + 1);
			if(*flag == NULL) {
				fprintf(stderr, "[ERROR]: Memory allocation fail.");
				return false;
			}
			// copy from arg to variable
			strcpy(*flag, argv[1]);
			break;
		case 2:
			// converting to int and checking if natural number
			*shift_amount = atoi(argv[2]);
			if(*shift_amount < 1) {
				fprintf(stderr, "[VALUE ERROR]: Please enter a value greater than 0.");
				return false;
			}
			break;
		case 3:
			// allocate enough memory in variable to store message & print error if failed
			*message = malloc(strlen(argv[3]) + 1);
			if(*message == NULL) {
				fprintf(stderr, "[ERROR]: Memory allocation fail.");
				return false;
			}
			// copy from arg to variable
			strcpy(*message, argv[3]);
			break;
		}
	}
	return true;
}

void free_memory(char *flag, char *message) {
	// good practice to set pointers to NULL after freeing memory- stops them being used accidently 
	if(flag != NULL) {
		free(flag);
		flag = NULL;
	}
	if(message != NULL) {
		free(message);
		message = NULL;
	}
}

void encrypt_message(int shift_amount, char *message) {
	/*
		check if character is alpha, if not print as is
		check if shifting character will put it out of bounds of A-Z/a-z and correctly wrapping the shift around by -26
	*/
	for(int i = 0; i < strlen(message); i++) {
		if(isalpha(message[i])) {
			if(isupper(message[i]) && message[i] + shift_amount > 'Z' 
				|| islower(message[i]) && message[i] + shift_amount > 'z') {
				printf("%c", (message[i] + shift_amount) - 26);
			}
			else {
				printf("%c", message[i] + shift_amount);
			}
		}
		else {
			printf("%c", message[i]);
		}	
	}
	printf("\n");
}

void decrypt_message(int shift_amount, char *message) {
		/*
		check if character is alpha, if not print as is
		check if shifting character will put it out of bounds of A-Z/a-z and correctly wrapping the shift around by +26
	*/
	for(int i = 0; i < strlen(message); i++) {
		if(isalpha(message[i])) {
			if(isupper(message[i]) && message[i] - shift_amount < 'A' 
				|| islower(message[i]) && message[i] - shift_amount < 'a') {
				printf("%c", (message[i] - shift_amount) + 26);
			}
			else {
				printf("%c", message[i] - shift_amount);
			}
		}
		else {
			printf("%c", message[i]);
		}
	}
	printf("\n");
}
