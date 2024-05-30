#include <stdbool.h>
#include <stdio.h>

const int NAME_LENGTH = 35;
const int MAX_BIDS = 10;

struct Bid {
	char name[NAME_LENGTH];
	double bid_amount;
};

int main(void) {
	struct Bid *bids = NULL; // pointer to array store bid history
	bool still_bidding = false;
	char name[NAME_LENGTH] = "";
	double bid_amount = 0;
	// collect bids clearing the screen after each one and storing as a struct in bids
	// keep track of highest and lowest bids
	// end of program print highest and lowest bidder as well as history of bids


	while(still_bidding) {
		printf("Welcome to the Secret Auction Program\n");
		printf("What is your name?: ");
	}
}