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

	int test = 1;// test is 1 for true and 0 for false
	int i, result = -2;
	printf("\n*****Testing isGameOver function****\n");
	// Case1 if stack of Province cards is empty, the game ends
	printf("\n*****Test Case 1****\n");
	G1.supplyCount[province] = 0; // Province cards are empty 
	for (i = 0; i < 25; i++) {
		if (i != 3)
		{
		   G1.supplyCount[i] = 5;    // supply piles are not empty.
		}
	}

	result = isGameOver(&G1);
	if (result == 1) {
		printf("\nPassed the test case when province cards are empty and supply pile is not empty. \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when province cards are empty and supply pile is not empty. \n");
		test = 0;
	}



	//Case 2  if three supply pile are at 0, the game ends
	printf("\n*****Test Case 2****\n");

	G2.supplyCount[province] = 4; // Province cards are not empty.
	for (i = 0; i < 25; i++) {
		if (i % 8 == 0) {              // every 8th supply pile is empty.So, 3 piles are empty.
			G2.supplyCount[i] = 0;
		}
		else {
			G2.supplyCount[i] = 5;    // rest supply piles are not empty.
		}
	}

	result = isGameOver(&G2);

	if (result == 1) {
		printf("\nPassed the test case when province cards are not empty and 3 supply piles are empty. \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when province cards are not empty and 3 supply piles are empty. \n");
		test = 0;
	}
	// Case 3: Neither of these 2 game is not over yet.

	printf("\n*****Test Case 3****\n");

	G3.supplyCount[province] = 4; // Province cards are not empty.
	for (i = 0; i < 25; i++) {
		if (i % 20 == 0) {              // So 0th and  20th supply pile is empty.So, 2 piles are empty.
			G3.supplyCount[i] = 0;
		}
		else {
			G3.supplyCount[i] = 5;    // rest supply piles are not empty.
		}
	}

	result = isGameOver(&G3);


	if (result == 0) {
		printf("\nPassed the test case when neither province cards nor 3 supply piles are empty \n");
		result = -2;
	}
	else {
		printf("\nFailed the test case when neither province cards nor 3 supply piles are empty \n");
		test = 0;
	}
	printf("\n****End of test cases****\n");

	if (test == 1) {
		printf("Passed all test cases successfully\n");
	}
	else {
		printf("Failed to pass all test cases \n");
	}
	
	return 0;

}
