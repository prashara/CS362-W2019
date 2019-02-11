#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define TESTCARD "great_hall" 


int main(int argc, char** argv) {
	
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G;
	int k[10] = { adventurer, embargo, village, minion, mine, great_hall,
		sea_hag, tribute, smithy, council_room };
	int bonus = 0;
	
	
	
	int failedTest = 0;
	

	initializeGame(numPlayers, k, seed, &G);

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	
	int currentHandCount = G.handCount[thisPlayer];
	int currentActions = G.numActions;
	G.hand[thisPlayer][0] = great_hall;
	
	printf("\n****Testing return value****\n");

	if (cardEffect(great_hall, 0, 0, 0, &G, 0, &bonus)) {                  // great_hall returns 0.
		printf("Failed to return correct return value\n");
		failedTest = 1;
	}
	else printf("Passed returned correct return value\n");

	printf("\n****Testing number of cards in hand****\n ");
	if (G.handCount[thisPlayer] != currentHandCount ) {         // +1 cards are drawn since one card is discarded and one is added hand count won't change.
		failedTest = 1;
		printf("Failed to draw 1 card from the deck\n");
	}
	else printf("Passed 1 card drawn from the deck.\n");
	

	printf("\n****Testing number of actions.****\n ");                            // Check for +1 actions.
	if (G.numActions != currentActions + 1) {
		printf("Failed to add 1 actions.\n");
		failedTest = 1;
	}
	else printf("Passed added 1 actions.\n");

	printf("\n****Testing great_hall card discarded****\n");
	if (G.playedCards[G.playedCardCount - 1] != great_hall) {
		printf("Failed to discard great_hall.\n");
		failedTest = 1;
	}
	else printf("Passed discarded great_hall.\n");

	if (!failedTest)
		printf("\nPassed all great_hall card test successfully.\n");
	else printf("\nFailed to pass all great_hall card test.\n");

	return 0;
}
