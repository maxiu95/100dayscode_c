#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


#define NAME_LENGTH 35
#define MAX_BIDS 10

struct Bid {
	char name[NAME_LENGTH];
	double bid_amount;
};

int main(void) {
	struct Bid bids[MAX_BIDS]; // store bid history
	int num_bids = 0;
	bool still_bidding = true;
	char continue_bid[5] = "";
	// collect bids clearing the screen after each one and storing as a struct in bids
	// keep track of highest and lowest bids
	// end of program print highest and lowest bidder as well as history of bids


	while(still_bidding) {
		if(num_bids == MAX_BIDS - 1) {
			!still_bidding;
		}
		struct Bid new_bid;
		printf("Welcome to the Secret Auction Program\n");
		printf("What is your name? [Max 35 characters]: ");
		scanf("%s", new_bid.name);
		printf("What is your bid? : $");
		scanf("%f", new_bid.bid_amount);
		bids[num_bids] = new_bid;
		num_bids++;

		printf("Any new bidders? (y/n): ");
		scanf("%s", &continue_bid);
		if(strcmp(continue_bid, "y")) {
			still_bidding = false;
		}
	}
}