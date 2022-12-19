#include <stdint.h>
#include <stdio.h>
#include "card.h"

void getCardHolderNameTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actualResults;
	uint8_t expectedResults[11];

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getCardHolderName\n");
	puts("");

/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: NULL card holder name\n");

	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: ");
	(void)gets(expectedResults);

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: card holder name less than 20 characters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: ");
	(void)gets(expectedResults);

	memset(expectedResults, '\0', sizeof(expectedResults));

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");

/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: card holder name more than 24 characaters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: ");
	(void)gets(expectedResults);

	memset(expectedResults, '\0', sizeof(expectedResults));

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");

/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: card holder name inrange from 20 to 24 charcters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: ");
	(void)gets(expectedResults);

	memset(expectedResults, '\0', sizeof(expectedResults));

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
}

void main(void)
{
	getCardHolderNameTest();
}