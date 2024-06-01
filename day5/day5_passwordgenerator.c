#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int TYPES_OUTPUT = 3;
const int ALPHABET = 26;
const int NUMBERS = 10;
const int SYMBOLS = 11;

char alphabet[ALPHABET];
char numbers[NUMBERS];
char symbols[SYMBOLS];

void populate_chars(void);
void password(int _alphabet, int _numbers, int _symbols);

int main(void) {
	srand(time(NULL));

	int _alphabet = 0, _numbers = 0, _symbols = 0;

	populate_chars();

	printf("== Welcome to the password generator. ==\n");
	printf("\nHow many letters would you like in your password?: ");
	scanf("%d", &_alphabet);
	printf("How many numbers would you like in your password?: ");
	scanf("%d", &_numbers);
	printf("How many symbols would you like in your password?: ");
	scanf("%d", &_symbols);

	password(_alphabet, _numbers, _symbols);

	return 0;
}

void populate_chars(void) {
	for(int i = 0; i < 26; i++) {
		alphabet[i] = 'a' + i;
		if(i < 10) {
			numbers[i] = '0' + i;
		}
		if(i < 11) {
			symbols[i] = '!' + i;
		}
	}
}

void password(int _alphabet, int _numbers, int _symbols) {
	int index, alph = 0, nums= 0, symbl = 0;
	printf("\n");
	while(alph < _alphabet || nums < _numbers || symbl < _symbols) {
		index = rand() % TYPES_OUTPUT;
		switch(index) {
		case 0:
			if(alph < _alphabet) {
				index = rand() % ALPHABET;
				printf("%c", alphabet[index]);
				alph++;
			}
			break;
		case 1:
			if(nums < _numbers) {
				index = rand() % NUMBERS;
				printf("%c", numbers[index]);
				nums++;
			}
			break;
		case 2:
			if(symbl < _symbols) {
				index = rand() % SYMBOLS;
				if(symbols[index] == '"') {
            		printf("\"");
            	}
            	else {
            		printf("%c", symbols[index]);
            	}
				symbl++;
			}
			break;
		}
	}
	printf("\n");
}
