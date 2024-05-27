#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

const int MAX_WORDS = 213;
const int MAX_WORD_LENGTH = 20;
const int MAX_STAGES = 6;

char words[MAX_WORDS][MAX_WORD_LENGTH];
char *hangman_title[] = {
"	 _                                             \n"
"	| |                                            \n"
"	| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n"
"	| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n"
"	| | | | (_| | | | | (_| | | | | | | (_| | | | |\n"
"	|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n"
"	                    __/ |                      \n"
"	                   |___/    \n"
};

char *stages[] = {
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|\\  |\n"
	" / \\  |\n"
	"      |\n"
	"=========\n",
	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|\\  |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	" /|   |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	"  |   |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	"  +---+\n"
	"  |   |\n"
	"  O   |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"=========\n",

	"  +---+\n"
	"  |   |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"      |\n"
	"=========\n",
};

void initialise_words(void);
bool check_guessed(char guessed[], char input, int num_guessed);
bool check_letter(char word[], char *guess, int word_len, char c);
bool check_match(char guess[], int word_len);

int main(void) {
	srand(time(NULL));

	int index, word_len, chances = MAX_STAGES-1, num_guessed = 0;
	char word[MAX_WORD_LENGTH], guess[MAX_WORD_LENGTH], guessed[MAX_WORD_LENGTH];
	char input;
	bool win = false;

	initialise_words();
	index = rand() % MAX_WORDS;
	strcpy(word, words[index]);
	word_len = strlen(word);

	for(int i = 0; i < word_len; i++) {
		guess[i] = '_';
	}
	guess[word_len] = '\0'; // mark end of string, important for functions like printf that look for \0

	printf("%s", hangman_title[0]);
	printf("%s\n", word);

	while(1) {
		if((chances) == 0) {
			break;
		}
		printf("\nYou have %d chances left!\n", (chances));
		printf("%s\n", stages[chances]);
		printf("%s\n", guess);

		printf("Guess a letter: ");
		scanf(" %c", &input);
		input = tolower(input);
		if(!isalpha(input)) { // correct input check
			printf("Please enter a valid alphabetical character.\n");
			continue;
		}
		if(check_guessed(guessed, input, num_guessed)) {
			printf("Already guessed this letter!\n");
			continue;
		}
		guessed[num_guessed] = input;
		num_guessed++;
		
		if (!check_letter(word, guess, word_len, input)) {
			chances--;
		}

		if(check_match(guess, word_len)) {
			win = true;
			break;
		}
	}

	if(win) {
		printf("\n** %s **\n", guess);
		printf("CONGRATULATIONS!! You guessed it!\n\n");
	}
	else{
		printf("\nSORRY... you didn't get it..\n");
		printf("The word was... %s\n", word);
	}

	return 0;
}

void initialise_words(void) {
	int num_words = 0; // word counter
	char line[MAX_WORD_LENGTH]; // setting length of line to be read
	FILE *ptr = fopen("./words.csv", "r"); // open file 
	if(ptr == NULL) {
		printf("Error while opening the file.\n");
		exit(1);
	}
	while(fgets(line, sizeof(line), ptr) != NULL) { // cycle until no lines left- adding to line buffer
		char *token = strtok(line, ",\n"); // store single word, using "," as a deliminator into token, including the new line element
		while(token != NULL) { // cycle until no words remaining
			strncpy(words[num_words], token, MAX_WORD_LENGTH); // copy from buffer to array
			words[num_words][strcspn(words[num_words], "\n")] = '\0';
			num_words++;
			token = strtok(NULL, ",\n"); // tells the loop to keep running/tokenising
		}
	}
	fclose(ptr);
}

bool check_guessed(char guessed[], char input, int num_guessed) {
	for (int i = 0; i < num_guessed; i++) {
		if(guessed[i] == input) {
			return true;
		}
	}
	return false;
}

bool check_letter(char word[], char *guess, int word_len, char c) {
	bool found = false;
	for(int i = 0; i < word_len; i++) {
		if(word[i] == c) {
			guess[i] = c;
			found = true;
		}
	}
	return found;
}

bool check_match(char guess[], int word_len) {
	for(int i = 0; i < word_len; i++) {
		if(guess[i] == '_') {
			return false;
		}
	}
	return true;
}