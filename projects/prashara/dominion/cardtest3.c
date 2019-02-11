#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define TESTCARD "village" 

int main(int argc, char** argv) {
	
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int bonus = 0;
	
		
	int test = 0;
	
	
	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	int currentHandCount = G.handCount[thisPlayer];	
	int currentActions = G.numActions;
	G.hand[thisPlayer][0] = village;

	printf("\n****Testing return value****\n");

	if (cardEffect(village, 0, 0, 0, &G, 0, &bonus)) {                  // Village returns 0.
		printf("Failed to return correct return value\n");
		test = 1;
	}
	else printf("Passed returned correct return value\n");

	printf("\n****Testing number of cards in hand****\n ");
	if (G.handCount[thisPlayer] != currentHandCount ) {         // +1 cards are drawn since one card is discarded and one is added hand count won't change.
		test = 1;
		printf("Failed to draw 1 card from the deck\n");
	}
	else printf("Passed 1 card drawn from the deck.\n");
	

	printf("\n****Testing number of actions.****\n ");                        // Check for +2 actions.
	if (G.numActions != currentActions + 2) {
		printf("Failed to add 2 actions.\n");
		test = 1;
	}
	else printf("Passed added 2 actions.\n");

	printf("\n****Testing village card discarded****\n");
	if (G.playedCards[G.playedCardCount - 1] != village) {
		printf("Failed to discard village card.\n");
		test = 1;
	}
	else printf("Passed village card discarded.\n");

	if (!test)
		printf("\nPassed all village card test successfully.\n");
	else printf("\nFailed to pass all village card test.\n");

	return 0;
}

