#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	struct gameState G1;
	struct gameState G2;
	struct gameState G3;
	struct gameState G4;


	int supply = 5;
	int supplyPos = 5;
	G1.whoseTurn = 1;
	G2.whoseTurn = 1;
	G3.whoseTurn = 1;
	G4.whoseTurn = 1;

	printf("\n*****Testing buy card function****\n");
	int result=-2;  // checks the return value of the function.
	//Case 1: if (state->numBuys < 1)
	printf("\n*****Test Case 1****\n");
	G1.numBuys = 0;
	G1.supplyCount[supply] = 2;
	G1.coins = 2;
	result = buyCard(supplyPos, &G1);    
	if (result == -1) {
		printf("\nPassed the test case when number of buys < 1 . \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when number of buys < 1 . \n");
	}

	//Case 2: if (supplyCount(supplyPos, state) <1)
	printf("\n*****Test Case 2****\n");
	G2.numBuys = 1;
	G2.supplyCount[supply] = 0;
	result = buyCard(supplyPos, &G2);
	G2.coins = 3;

	if (result == -1) {
		printf("\nPassed the test case when there is no card left of the given type . \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when there is no card left of the given type . \n");
	}

	// Case 3:if (state->coins < getCost(supplyPos)
	printf("\n*****Test Case 3****\n");
	G3.coins = 2 ;   // choose a card whose getCost is more than this.
	G3.numBuys = 1;
	G3.supplyCount[supply] = 2;
	result = buyCard(supplyPos, &G3);
	if (result == -1) {
		printf("\nPassed the test case when the chosen card cost is more than available coins. \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when the chosen card cost is more than available coins. \n");
	}
	// getCost(5) is 3
	// Else condition check state->phase=1; or G.phase =1;

   // Variables needed for gain card functions here.
	printf("\n****Test Case 4 ****\n");
	G4.numBuys = 4;
	int buys = G4.numBuys;
	G4.supplyCount[supply] = 2;
	G4.coins = 4;
	int totalCoins = G4.coins;
	G4.discardCount[1] = 2;
	G4.discard[0][1] = 1;
	result = buyCard(supplyPos, &G4);
	
	printf("Num of buys left :%d\n",G4.numBuys);
	printf("Coins left after buying : %d\n",G4.coins);
	if ((totalCoins == G4.coins + getCost(supplyPos)) && (buys == G4.numBuys + 1) && (result == 0 )) 
	{
		printf("\nPassed the test case when the chosen card is bought and added to discard pile. \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when the chosen card is bought and added to discard pile. \n");
	}
   // These things happen in gaincard functions:
		// 1. state->discard[player][state->discardCount[player]] = supplyPos;
		// 2. state->discardCount[player]++;
	//Check for these 2:  state->coins = (state->coins) - (getCost(supplyPos));
	//	Check for this condition as well. state->numBuys--;

	
	printf("\n****End of test cases****\n");
	
	return 0;

}
