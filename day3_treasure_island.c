#include <ctype.h> // toupper/tolower functions
#include <stdio.h>
#include <string.h>

void change_case(char *string);
void clear_choice(char *string);
int dead(int index);

int main(void) {
	char choice[10];
	char asci_art[] = "						                     ,\n"
					  "					               ._  \\/, ,|_.\n"
					  "					               -\\| \\|;|,'_.\n"
					  "					               `_\\|\\|;/-.\n"
					  "					                `_\\|/._\n"
					  "					               ,'__   __`.\n"
					  "					              / /_ | | _\\ \\\n"
					  "					             / ((o)| |(o)) \\\n"
					  "					             |  `--/ \\--'  |\n"
					  "					       ,--.   `.   '-'   ,'\n"
					  "					      (O..O)    `.uuuuu,'\n"
					  "					       \\==/     _|nnnnn|_\n"
					  "					      .'||`. ,-' \\_____/ `-.\n"
					  "					       _||,-'      | |      `.\n"
					  "					      (__)  _,-.   ; |   .'.  `.\n"
					  "					      (___)'   |__/___\\__|  \\(__).\n"
					  "					      (__)     :::::::::::  (___).\n"
					  "					        ||    :::::::::::::  (__).\n"
					  "					        ||    :::::::::::::\n"
					  "					             __|   | | _ |__\n"
					  "					            (_(_(_,' '._)_)_)\n";
	char title[] = " /  ############/                                                                             ######  /        ###                               ##   \n"
				   "/     #########                                                                              /#   /  /          ##                               ##   \n"
				   "#     /  #                                                                                  /    /  /           ##                               ##   \n"
				   " ##  /  ##                                                                                      /  /            ##                               ##   \n"
				   "    /  ###     ###  /###     /##       /###      /###   ##   ####    ###  /###     /##         ## ##    /###    ##      /###   ###  /###     ### ##   \n"
				   "   ##   ##      ###/ #### / / ###     / ###  /  / #### / ##    ###  / ###/ #### / / ###        ## ##   / #### / ##     / ###  / ###/ #### / ######### \n"
				   "   ##   ##       ##   ###/ /   ###   /   ###/  ##  ###/  ##     ###/   ##   ###/ /   ###     /### ##  ##  ###/  ##    /   ###/   ##   ###/ ##   ####  \n"
				   "   ##   ##       ##       ##    ### ##    ##  ####       ##      ##    ##       ##    ###   / ### ## ####       ##   ##    ##    ##    ##  ##    ##   \n"
				   "   ##   ##       ##       ########  ##    ##    ###      ##      ##    ##       ########       ## ##   ###      ##   ##    ##    ##    ##  ##    ##   \n"
				   "    ##  ##       ##       #######   ##    ##      ###    ##      ##    ##       #######   ##   ## ##     ###    ##   ##    ##    ##    ##  ##    ##   \n"
				   "     ## #      / ##       ##        ##    ##        ###  ##      ##    ##       ##       ###   #  /        ###  ##   ##    ##    ##    ##  ##    ##   \n"
				   "      ###     /  ##       ####    / ##    /#   /###  ##  ##      /#    ##       ####    / ###    /    /###  ##  ##   ##    /#    ##    ##  ##    /#   \n"
				   "       ######/   ###       ######/   ####/ ## / #### /    ######/ ##   ###       ######/   #####/    / #### /   ### / ####/ ##   ###   ###  ####/     \n"
				   "         ###      ###       #####     ###   ##   ###/      #####   ##   ###       #####      ###        ###/     ##/   ###   ##   ###   ###  ###      \n";
	printf("%s", asci_art);	
	printf("%s\n", title);
	printf("Welcome to Treasure Island.\nYour mission is to find the treasure.\n");
	printf("\nWill you go left or right?: ");
	scanf("%s", choice);
	change_case(choice);
	if(strcmp("LEFT", choice) != 0) {
		return dead(1);
	}
	clear_choice(choice);
	printf("\nYou come by a quiet river. The water looks cool and inviting.\n");
	printf("Do you swim or wait?: ");
	scanf("%s", choice);
	change_case(choice);
	if(strcmp("WAIT", choice) != 0) {
		return dead(2);
	}
	clear_choice(choice);
	printf("\nYou come to a small shack.\n");
	printf("You open the old wooden door and go inside.\n");
	printf("You enter a small room, each wall with a different door.\n");
	printf("Red, Blue or Yellow. Which do you pick?: ");
	scanf("%s", choice);
	change_case(choice);
	if(strcmp("YELLOW", choice) != 0) {
		if(choice[0] == 'R') {
			return dead(3);
		}
		else if(choice[0] == 'B') {
			return dead(4);
		}
		else {
			return dead(0);
		}
	}
	else {
		printf("\nYou open the door and are greeted by The Holy Grail...\n");
		printf("YOU WIN!!!!");
}
	return 0;
}

void change_case(char *string) {
	for(int i = 0; i < 10; i++) {
		string[i] = toupper(string[i]);
	}
}

void clear_choice(char *string) {
	for(int i = 0; i < 10; i++) {
		string[i] = '\0';
	}
}

int dead(int index) {
	switch(index) {
	case 1:
		printf("\nFall into a hole.\n");
		break;
	case 2:
		printf("\nAttacked by trout.\n");
		break;
	case 3:
		printf("\nBurned by fire.\n");
		break;
	case 4:
		printf("\nEaten by beasts.\n");
		break;
	}
	printf("GAME OVER!!\n");
	return 1;
}

/*
	a way to make case-insensitive input is to convert it with 
	toupper/tolower in a seperate function passed via pointer
*/