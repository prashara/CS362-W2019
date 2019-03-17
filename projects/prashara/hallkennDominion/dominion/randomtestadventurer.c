#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define TESTCARD "adventurer" 

//adventurer
int main(int argc, char** argv) {
	
	struct gameState G;
	int seed = 1000;
	int numPlayers = 2;
	int curPlayer = 0;
	int k[10] = { adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room };
	int deckSize , handSize;
	int i,j,bonus=0,handPos=0;
	int randomCard , randKCard;
	int coinStart , coinEnd;
	int result = 1;                             // 1 if test result . 0 if test failed.
	int discardC, discardS , discardG;
	
	int testresult = 0;
	int drawTestFailed = 0;
	int discardTestFailed = 0;
	
	
	#define NUM_TEST 10000

	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	srand(time(NULL));
	//randomize hand size
	for (i = 0; i < NUM_TEST; i++) {
		initializeGame(numPlayers, k, seed, &G);
		coinStart = 0;
		deckSize = (rand() % MAX_DECK) + 1;
		//set handsize
		handSize = (rand() % deckSize) + 1;


		G.deckCount[curPlayer] = deckSize - handSize;
		G.handCount[curPlayer] = handSize;

			
		for (j = 0; j < G.deckCount[curPlayer]; j++) {
				randomCard = (rand() % 17) + 1;        // We have following cards 3 types of treasure cards, 3 types of  Victory cards , 10 Kingdom cards,1 type of curse card.
				randKCard = rand() % (10);                 // Select random kingdom cards.
				if (randomCard == 1) {
					G.deck[curPlayer][j] = copper;
				}
				else if (randomCard == 2) {
					G.deck[curPlayer][j] = silver;
				}
				else if (randomCard == 3) {
					G.deck[curPlayer][j] = gold;
				}
				else if (randomCard == 4) {
					G.deck[curPlayer][j] = curse;
				}
				else if (randomCard == 5) {
					G.deck[curPlayer][j] = estate;
				}
				else if (randomCard == 6) {
					G.deck[curPlayer][j] = duchy;
				}
				else if (randomCard == 7) {
					G.deck[curPlayer][j] = province;
				}
				else {
					G.deck[curPlayer][j] = k[randKCard];
				}
		}
		
		
		for (j = 0; j < G.handCount[curPlayer]; j++) {
			if (G.hand[curPlayer][j] == copper || G.hand[curPlayer][j] == silver || G.hand[curPlayer][j] == gold) {
				coinStart++;
			}
			
		}
		//printf("Coin Count before: %d\n", coinStart);
		//printf("discard count before: %d\n", G.discardCount[curPlayer]);
		//printf("deckSize: %d, deck: %d, and hand: %d\n", deckSize, G.deckCount[0], G.handCount[0]); 
		
		cardEffect(adventurer, 0, 0, 0, &G, handPos, &bonus);

		coinEnd = 0;

		for (j = 0; j < G.handCount[curPlayer]; j++) {
			if (G.hand[curPlayer][j] == copper || G.hand[curPlayer][j] == silver || G.hand[curPlayer][j] == gold) {
				coinEnd++;
			}
		}
		//printf("Coin Count after: %d\n", coinEnd);
		//printf("discard count after: %d\n", G.discardCount[curPlayer]);
		discardC = 0;
		discardS = 0;
		discardG = 0;
		for (j = 0; j < G.discardCount[curPlayer]; j++) {
			if (G.discard[curPlayer][j] == copper) {
				discardC++;
			}
			else if (G.discard[curPlayer][j] == silver) {
				discardS++;
			}
			else if (G.discard[curPlayer][j] == gold) {
				discardG++;
			}
		}
		
		if (coinEnd > (coinStart + 2)) {
			printf("\nIncorrect number of treasure cards drawn from the deck.Test Failed\n");
			drawTestFailed++;
			result = 0;
		}

		if (coinEnd < coinStart) {
			printf("\nCoins got removed from the hand. Test Failed\n");
			drawTestFailed++;
			result = 0;
		}
		if (discardC != 0) {
			printf("\nCopper coins removed from hand. Test Failed\n");
			discardTestFailed++;
			result = 0;
		}

		if (discardS != 0) {
			printf("\nSilver coins removed from hand. Test Failed\n");
			discardTestFailed++;
			result = 0;
		}

		if (discardG != 0) {
			printf("\nGold coins removed from hand. Test Failed\n");
			discardTestFailed++;
			result = 0;
		}
		

		if (result == 1) {
			//printf("\nTest case %d : All tests  passed successfully.\n",i);
			testresult++;
		}
		/********************************************
		int urNum;
		printf("Enter your number \n");
		scanf("%d", &urNum);
		********************************************/

	}

	
	printf("\nTotal number of Tests passed: %d\n", testresult);
	printf("\nTotal number of Tests for drawing test failed:  %d\n", drawTestFailed);
	printf("\nTotal number of Tests of drawing Treasure cards  failed: %d\n", discardTestFailed);

	return 0;
}

