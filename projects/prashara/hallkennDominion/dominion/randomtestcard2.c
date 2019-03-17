#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "village" 

//village
int main(int argc, char** argv) {

	struct gameState G;
	int seed = 1000;
	int numPlayers = 2;
	int curPlayer = 0;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int deckSize, handSize;
	int handPos;
	int deckStart, handStart, discardStart;
	int i;
	int deckFailure = 0;
	int handFailure = 0;
	int discardFailure = 0;
	int testResult = 0;
	int result = 1;                                   // counter to check if test cases are passed successfully. 0 for true 1 for false.
	int bonus = 0;

#define NUM_TEST 10000

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

	// initialize a game state and player cards
	srand(time(NULL));
	//randomize hand size
	for (i = 0; i < NUM_TEST; i++) {
		initializeGame(numPlayers, k, seed, &G);

		deckSize = (rand() % MAX_DECK) + 1;
		//set handsize
		handSize = (rand() % deckSize) + 1;


		G.deckCount[curPlayer] = deckSize - handSize;
		if (G.deckCount[curPlayer] <= 2)
		{
			G.deckCount[curPlayer] = 3;                  // We need min. 3 cards in deck to draw 3 cards for smithy to function properly. Otherwise it takes discard card in deck.
		}
		G.handCount[curPlayer] = handSize;
		G.discardCount[curPlayer] = rand() % 6 + 5;        // Discard card count 5 to 10.


		handPos = G.handCount[curPlayer] - 1;
		//printf("Using this handpos : %d\n", handPos);
		
		deckStart = G.deckCount[0];
		//printf("deck before %d\n", deckStart);
		handStart = G.handCount[0];
		//printf("Hand before %d\n", handStart);
		discardStart = G.playedCardCount;
		//printf("Discard before %d\n", discardStart);



		cardEffect(village, 0, 0, 0, &G, handPos, &bonus);

		//printf("deck after %d\n", G.deckCount[0]);

		//printf("hand After %d\n", G.handCount[0]);

		//printf("Discard After %d\n\n", G.playedCardCount);

		if (G.handCount[0] != (handStart)) {
			printf("\nFailed to add 1 cards to hand.\n");
			handFailure++;
			result = 0;
		}

		if (G.deckCount[0] != (deckStart - 1)) {
			printf("\nFailed to remove 1 cards from deck.\n");
			deckFailure++;
			result = 0;
		}

		if (G.playedCardCount != (discardStart + 1)) {
			printf("\nFailed to discard village card from hand.\n");
			discardFailure++;
			result = 0;
		}

		if (result == 1) {
			//printf("\n Tests passed successfully.\n");
			testResult++;
		}
		
	}
				
	printf("\nTotal number of Tests passed: %d\n", testResult);
	printf("\nTotal number of Tests for adding cards to hand test failed:  %d\n", handFailure);
	printf("\nTotal number of Tests of drawing cards from deck  failed: %d\n", deckFailure);
	printf("\nTotal numbers of Tests of discarding village failed: %d\n", discardFailure);
	
	return 0;
}

