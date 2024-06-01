#include <stdio.h>

int main(void) {
	double bill = 0.0;
	double tip_percentage = 0;
	int num_persons = 0;
	double total_with_tip = 0.0;
	printf("Welcome to the tip calculator!\n");
	printf("\nHow much was the total bill?: ");
	scanf("%lf", &bill);
	printf("How much is the tip you would like to give? 10, 12, or 15?: ");
	scanf("%lf", &tip_percentage);
	printf("How many people to split the bill?: ");
	scanf("%d", &num_persons);
	total_with_tip = (bill/num_persons) * (1.0 + tip_percentage/100);
	printf("\nEach person should pay: $%.2lf\n", total_with_tip);
	return 0;
}