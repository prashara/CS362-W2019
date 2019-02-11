#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	
	int cNum, cost=0, test=1;                                // test is 1 for true and 0 for false.
	// cNum stores card number since it's enum type, cost cost of the card.	

	printf("\n Testing getCost function \n");

	for (cNum=-3; cNum <= 27; cNum +=3)
	{
		cost = getCost(cNum);

		if (cNum < 0 || cNum >26) {
			if (cost == -1) {
				printf("\nPassed invalid card entered.Cost is: %d\n", cost);
			}
			else {
				printf("Failed invalid card entered.Cost is: %d\n", cost);
				test = 0;
			}
		}
		else if (cNum == 0)			//Curse: 0
		{
			if (cost == 0)
				printf("\nPassed where Curse cost %d.\n", cost);
			else
			{	printf("\nFailed where Curse cost %d.\n", cost);
				test = 0;
			}
		}
		else if (cNum == 3)	//Province: 8
		{
			if (cost == 8)
				printf("\nPassed where Province cost %d.\n", cost);
			else
			{	printf("\nFailed where Province cost %d.\n", cost);
				test = 0;
			}
		}
		else if (cNum == 6)	//Gold: 6
		{
			if (cost == 6)
				printf("\nPassed where Gold cost %d.\n", cost);
			else
			{	printf("\nFailed where Gold cost %d.\n", cost);
				test = 0;
			}
		}
		
		else if (cNum == 9)	//Feast: 4
		{
			if (cost == 4)
				printf("\nPassed where Feast cost %d.\n", cost);
			else
			{	printf("\nFailed where Feast cost %d.\n", cost);
				test = 0;
			}
		}	
		else if (cNum == 12)	//Remodel: 4
		{
			if (cost == 4)
				printf("\nPassed where Remodel cost %d.\n", cost);
			else
			{	printf("\nFailed where Remodel cost %d.\n", cost);
				test = 0;
			}
		}
		else if (cNum == 15)	//Baron: 4
		{
			if (cost == 4)
				printf("\nPassed where Baron cost %d.\n", cost);
			else
			{	printf("\nFailed where Baron cost %d.\n", cost);
				test = 0;
			}
		}
		else if (cNum == 18)	//Steward: 3
		{
			if (cost == 3)
				printf("\nPassed where Steward cost %d.\n", cost);
			else
			{	printf("\nFailed where Steward cost %d.\n", cost);
				test = 0;
			}	
		}
		else if (cNum == 21)	//Cutpurse: 4
		{
			if (cost == 4)
				printf("\nPassed where Cutpurse cost %d.\n", cost);
			else
			{	printf("\nFailed where Cutpurse cost %d.\n", cost);
				test = 0;
			}
		}
		else if (cNum == 24)	//Salvager: 4
		{
			if (cost == 4)
				printf("\nPassed where Salvager cost %d.\n", cost);
			else
			{	printf("\nFailed where Salvager cost %d.\n", cost);
				test = 0;
			}
		}
		
	}

	if (test == 1) {
		printf("\nPassed all test cases successfully\n");
	}
	else {
		printf("\nFailed to pass all test cases \n");
	}

	
	

	
	return 0;

}
