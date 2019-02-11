#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int test = 1;                            // if test remains 1 it means all test cases passed and 0 means test cases failed.

	printf("\nTesting gain card function \n");
	struct gameState G;
	

	//added card for [whoseTurn] current player:
	// toFlag = 0 : add to discard
	// toFlag = 1 : add to deck
	// toFlag = 2 : add to hand
	int toFlag, i ,player = 0;
	int supplyPos = 5;

	for (i = 0; i <= 3; i++) {
		
		G.deckCount[0]= 3;
		G.deck[0][3]=1;
		G.handCount[0]=3;
		G.hand[0][3]=1;
		G.discardCount[0]=3;
		G.discard[0][3]=1;
		G.supplyCount[supplyPos] = 2;
		toFlag = i;
		if (toFlag == 1) {
			int numCard = G.deckCount[player];
			gainCard(supplyPos, &G, i, player);
			//printf("\n %d, %d, %d, %d\n", G.deck[player][G.deckCount[player]-1], supplyPos, numCard +1, G.deckCount[player]-1);
			if ((G.deck[player][G.deckCount[player]-1] == supplyPos)  && ((numCard+1) ==(G.deckCount[player]))) {
				printf("\nPassed the test case card added to the deck correctly \n");
				test = 1;
			}
			else {
				printf("\nFailed the test case card added to the deck correctly \n");
				test = 0;
			}
		}
		else if (toFlag == 2)
		{
			int numCard = G.handCount[player];
			gainCard(supplyPos, &G, i, player);
			if ((G.hand[player][G.handCount[player]-1] == supplyPos) && ((numCard + 1) == (G.handCount[player]))) {
				printf("\nPassed the test case card added to the hand correctly \n");
			}
			else {
				printf("\nFailed the test case card added to the hand correctly \n");
				test = 0;
			}
		
		
		}
		else
		{
			int numCard = G.discardCount[player];
			gainCard(supplyPos,&G,i,player);
			if ((G.discard[player][G.discardCount[player]-1] == supplyPos) && ((numCard + 1) == (G.discardCount[player]))) {
				printf("\nPassed the test case card added to the discard pile correctly \n");
			}
			else {
				printf("\nFailed the test case card added to the discard pile correctly \n");
				test = 0;
			}
	
				
		}
		
		

	}
	

	if (test == 0) {
		printf("\nFailed to pass all test cases. \n");
	}
	else {
		printf("\nPassed all test cases successfully. \n");
	}

 return 0;

}
