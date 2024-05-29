#include <stdio.h>
#include <string.h>

int check_error_arguements(int argc, char **arg);
void help_message(void);
void encrypt_message(char **n, char **arg);

int main(int argc, char**argv) {

	// TODO rework the program to parse each argument into its own variable during the arguments check at the start of the program
	// dynamically allocate for strings as i cant be sure how long they will be from the start

	if(check_error_arguements(argc, &argv[1])) {
		return 1;
	}
	if(strcmp(argv[1], "-h") == 0) {
		help_message();
	}
	else if(strcmp(argv[1], "-e") == 0) {
		encrypt_message(&argv[2], &argv[3]);
	}
	else if(strcmp(argv[1], "-d") == 0) {
		;
	}
	return 0;
}

int check_error_arguements(int argc, char **arg) {
	if(strcmp(*arg, "-h") == 0 && argc == 2) {
		return 0;
	}
	else if(argc < 4) {
		fprintf(stderr, "ERROR: Insufficient arguements.\n");
		printf("Usage: ./day8_caesar <-e/-d> <shift amount> <message>\n\t\"-h\" for help\n");
		return 1;
	}
	return 0;
}

void help_message(void) {
	printf("[USAGE] ./day8_caesar <-e/-d> <shift amount> <message>\n");
	printf("\t-e: encrypt\n\t-d: decrypt\n");
	printf("\tshift amount: shift value by _ spaces\n");
	printf("\tmessage: message to encrypt/decrypt\n");
}

void encrypt_message(char **n, char **arg) {
	;
}