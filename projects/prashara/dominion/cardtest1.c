#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define TESTCARD "adventurer" 

//adventurer
int main(int argc, char** argv) {
	
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G1, G2, G3;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int bonus = 0;
	
	
	int test = 0;                                   // counter to check if test cases are passed successfully. 0 for true 1 for false.
	
	// initialize a game state and player cards
	

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	
	// case 1 deck has 1 treasure card.

	initializeGame(numPlayers, k, seed, &G1);

	G1.handCount[thisPlayer] = 5;                       // initialize hand count.

	G1.deckCount[thisPlayer] = 3;                       // initialize hand count.

	int currentHandCount1 = G1.handCount[thisPlayer];
	
	
	
	G1.deck[thisPlayer][0] = smithy;
	G1.deck[thisPlayer][1] = copper;
	G1.deck[thisPlayer][2] = estate;

	G1.hand[thisPlayer][0] = steward; 
	G1.hand[thisPlayer][1] = copper;
	G1.hand[thisPlayer][2] = duchy;
	G1.hand[thisPlayer][3] = estate; 
	G1.hand[thisPlayer][4] = feast;



	printf("\n****Test Case 1****\n");
	
	if (cardEffect(adventurer, 0, 0, 0, &G1, 0, &bonus)) {                  // Adventurer returns 0.
		printf("\nFailed to return correct return value.\n");
		test = 1;
	}
	else printf("\nPassed returned correct return value.\n");
	
	if (G1.hand[thisPlayer][G1.handCount[thisPlayer] - 1] == copper) {
		printf("\nPassed 1 treasure card drawn from the deck\n");
	}
	else {
		printf("\nFailed to draw 1 treasure card from the deck\n");
		test = 1;
	}
	//printf("Hand count is : %d\n", G1.handCount[thisPlayer]);
	if (G1.handCount[thisPlayer] == currentHandCount1 + 1) {
		printf("\nPassed correct hand count test\n");
	}
	else {
		printf("\nFailed correct hand count test.\n");
		test = 1;
	}
	// case 2 hand has 2 treasure card
	printf("\n****Test Case 2****\n");

	initializeGame(numPlayers, k, seed, &G2);

	G2.handCount[thisPlayer] = 5;                       // initialize hand count.

	G2.deckCount[thisPlayer] = 3;                       // initialize hand count.

	int currentHandCount2 = G2.handCount[thisPlayer];
	


	G2.deck[thisPlayer][0] = smithy;
	G2.deck[thisPlayer][1] = copper;
	G2.deck[thisPlayer][2] = gold;

	G2.hand[thisPlayer][0] = steward;
	G2.hand[thisPlayer][1] = copper;
	G2.hand[thisPlayer][2] = duchy;
	G2.hand[thisPlayer][3] = estate;
	G2.hand[thisPlayer][4] = feast;

	cardEffect(adventurer, 0, 0, 0, &G2, 0, &bonus);

	
	if (G2.hand[thisPlayer][G2.handCount[thisPlayer] - 1] == copper && G2.hand[thisPlayer][G2.handCount[thisPlayer] - 2]== gold) {
		printf("\nPassed 2 treasure card drawn from the deck\n");
	}
	else {
		printf("\nFailed to draw 2 treasure card from the deck\n");
		test = 1;
	}
	//printf("Hand count is : %d\n", G1.handCount[thisPlayer]);
	if (G2.handCount[thisPlayer] == currentHandCount2 + 2) {
		printf("\nPassed correct hand count test\n");
	}
	else {
		printf("\nFailed correct hand count test.\n");
		test = 1;
	}


	// Case 3 deck has 0 treasure card.

	printf("\n****Test Case 3****\n");

	initializeGame(numPlayers, k, seed, &G3);

	G3.handCount[thisPlayer] = 5;                       // initialize hand count.

	G3.deckCount[thisPlayer] = 3;                       // initialize hand count.

	int currentHandCount3 = G3.handCount[thisPlayer];
	


	G3.deck[thisPlayer][0] = smithy;
	G3.deck[thisPlayer][1] = estate;
	G3.deck[thisPlayer][2] = estate;

	G3.hand[thisPlayer][0] = steward;
	G3.hand[thisPlayer][1] = copper;
	G3.hand[thisPlayer][2] = duchy;
	G3.hand[thisPlayer][3] = estate;
	G3.hand[thisPlayer][4] = feast;

	cardEffect(adventurer, 0, 0, 0, &G2, 0, &bonus);


	if (G3.hand[thisPlayer][G3.handCount[thisPlayer] - 1] == feast) {
		printf("\nPassed 0 treasure card drawn from the deck\n");
	}
	else {
		printf("\nFailed to draw 0 treasure card from the deck\n");
		test = 1;
	}
	//printf("Hand count is : %d\n", G1.handCount[thisPlayer]);
	if (G3.handCount[thisPlayer] == currentHandCount3 ) {               // No change in handcount.
		printf("\nPassed correct hand count test\n");
	}
	else {
		printf("\nFailed correct hand count test.\n");
		test = 1;
	}

	

	if (!test)
		printf("\nPassed all adventurer card test cases successfully\n");
	else printf("\nFailed to pass all adventurer card test cases\n");

	return 0;
}
