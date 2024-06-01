#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
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
void get_valid_keep_bidding(void);

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
		// break;
		get_valid_keep_bidding();
	}
	for(int i = 0; i < num_bids; i++) {
		printf("%s\n", collected_bids[i].name);
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
	;
}

bool get_bid_input(double *amount) {
	;
}

void get_valid_keep_bidding(void) {
	;
}
