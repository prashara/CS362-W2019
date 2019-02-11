#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define TESTCARD "smithy" 

//Smithy card tests.
int main(int argc, char** argv) {
	
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int bonus = 0;
	
	
	
	int test = 0;
	
	
	initializeGame(numPlayers, k, seed, &G);         // initialize the game.

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	
	int currentHandCount = G.handCount[thisPlayer];
	G.hand[thisPlayer][0] = smithy;
	
	printf("\n****Testing return value****\n");

	if (cardEffect(smithy, 0, 0, 0, &G, 0, &bonus)) {                  // Smithy returns 0.
		printf("Failed to return correct return value.\n");
		test = 1;
	}
	else printf("Passed returned correct return value.\n");

	printf("\n****Testing number of cards in hand****\n ");
	if (G.handCount[thisPlayer] != (currentHandCount + 2)) {         // +3 cards are drawn but we need to subtract 1 since smithy has been played.
		test = 1;
		printf("Failed to draw 3 cards from the deck.\n");
	}
	else printf("Passed 3 cards drawn from the deck.\n");
	currentHandCount = currentHandCount + 2;

	printf("\n****Testing smithy card discarded****\n");
	if (G.playedCards[G.playedCardCount - 1] != smithy) {
		printf("Failed to discard smithy card\n");
		test = 1;
	}
	else printf("Passed smithy card discarded.\n");

	if (!test)
		printf("\nPassed all smithy card tests successfully\n");
	else printf("\nFailed to pass all smithy card test cases.\n");

	return 0;
}
