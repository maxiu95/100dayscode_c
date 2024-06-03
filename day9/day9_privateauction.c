#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME_LENGTH 36
#define MAX_BIDS 10

struct Bidder {
	char name[NAME_LENGTH];
	double bid_amount;
};

void get_valid_name(struct Bidder *bidder_ptr); // acts as a verification loop until a correct value is passed by the user
bool get_name_input(char *name); // directly takes input from user, returning true if meets correct conditions
void get_valid_bid(struct Bidder *bidder_ptr);
bool get_bid_input(double *amount);
char get_valid_keep_bidding(void);
bool get_valid_y_or_n(char *y_or_n);

int main(void) {
	struct Bidder collected_bids[MAX_BIDS]; // store bid history
	int num_bids = 0;
	bool still_bidding = true;
	// collect bids clearing the screen after each one and storing as a struct in bids
	// keep track of highest and lowest bids
	// end of program print highest and lowest bidder as well as history of bids

	while(still_bidding) {
		struct Bidder new_bidder;
		printf("Welcome to the 'Secret Auction'. Please place your bid.\n");
		// collect user input and add to new_bidder struct
		get_valid_name(&new_bidder);
		get_valid_bid(&new_bidder);
		// add to array
		collected_bids[num_bids] = new_bidder;
		num_bids++;
		if(get_valid_keep_bidding() == 'n') {
			break;
		}
		// clear screen
		printf("\033[2J\033[1;1H");

	}
	for(int i = 0; i < num_bids; i++) {
		printf("%s %.2lf\n", collected_bids[i].name, collected_bids[i].bid_amount);

	}
}

void get_valid_name(struct Bidder *bidder_ptr) {
	bool valid_input = false;
	char name[NAME_LENGTH];
	while(!valid_input) {
		printf("Please enter your name (35 char MAX): ");
		valid_input = get_name_input(name);
		if(!valid_input) {
			fprintf(stderr, "[INPUT ERROR]: Please input a valid name of maximum 35 characters.\n");
		}
	}
	strncpy(bidder_ptr->name, name, NAME_LENGTH);
}

bool get_name_input(char *name) {
	char input[100];
	// check there is input
	if(fgets(input, sizeof(input), stdin) == NULL) {
		return false;
	}
	if(strlen(input) > NAME_LENGTH) {
		return false;
	}
	// strcspn scans the string for newline char acting as an index as fgets also copies the newline from the enter key
	input[strcspn(input, "\n")] = '\0';
	strncpy(name, input, NAME_LENGTH);
	return true;
}

void get_valid_bid(struct Bidder *bidder_ptr) {
	bool valid_input = false;
	double amount = 0.0;
	while(!valid_input) {
		printf("Please enter your bid?: $");
		valid_input = get_bid_input(&amount);
		if(!valid_input) {
			fprintf(stderr, "[INPUT ERROR]: Please enter a valid amount of money.\n");
		}
	}
	bidder_ptr->bid_amount = amount;
}

bool get_bid_input(double *amount) {
	char input[100];
	char *endptr; // for strtof function check
	if(fgets(input, sizeof(input), stdin) == NULL) {
		return false;
	}
	*amount = strtod(input, &endptr);
	/*
		check if converstion failed. If the conversion completed, endptr will be pointing to the character after the last character converted to double
		i.e. /n. however if conversion failed (no double input), input pointer will still be at the start as well as the endptr as no conversion took place
	*/
	if(endptr == input) {
		return false;
	}
	// cycle over any clearspace until last char.. buildup to check for null terminal at the end
	while(isspace((unsigned char) *endptr)) {
		endptr++;
	}
	if(*endptr != '\0') {
		return false;
	}
	return true;
}

char get_valid_keep_bidding(void) {
	bool valid_input = false;
	char y_or_n = 'y';
	while(!valid_input) {
		printf("Are there any new bidders? (y/n): ");
		valid_input = get_valid_y_or_n(&y_or_n);
		if(!valid_input) {
			fprintf(stderr, "[INPUT ERROR]: Please enter 'y' or 'n'.\n");
		}
	}
	return y_or_n;
}

bool get_valid_y_or_n(char *y_or_n) {
	char input[100];
	if(fgets(input, sizeof(input), stdin) == NULL) {
		return false;
	}
	// check input is a single char
	if (strlen(input) > 2) {
		return false;
	}
	for(int i = 0; i < strlen(input); i++) {
		tolower(input[i]);
	}
	if(input[0] != 'y' && input[0] != 'n') {
		return false;
	}
	*y_or_n = input[0];
	return true;
} 
