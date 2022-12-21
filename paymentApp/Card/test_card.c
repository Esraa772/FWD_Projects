#include <stdint.h>
#include <stdio.h>
#include "card.h"

void getCardHolderNameTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getCardHolderName\n");
	puts("");

/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: NULL card holder name\n");

	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: WRONG_NAME\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: card holder name less than 20 characters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: WRONG_NAME\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");

/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: card holder name more than 24 characaters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: WRONG_NAME\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");

/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: card holder name inrange from 20 to 24 charcters\n");
	printf("Input Data: ");
	actualResults = getCardHolderName(&card);
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));

	printf("Expected Results: WRONG_NAME\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
}

void getCardExpiryDateTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getCardExpiryDate\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: NULL card expiration date\n");

	printf("Input Data: ");
	actualResults = getCardExpiryDate(&card);
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));

	printf("Expected Results: WRONG_EXP_DATE\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: card expiration date less than 5 \n");

	printf("Input Data: ");
	actualResults = getCardExpiryDate(&card);
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));

	printf("Expected Results: WRONG_EXP_DATE\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");

	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: card expiration date more than 5 \n");

	printf("Input Data: ");
	actualResults = getCardExpiryDate(&card);
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));

	printf("Expected Results: WRONG_EXP_DATE\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");

	/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: card expiration date wrong formate \n");

	printf("Input Data: ");
	actualResults = getCardExpiryDate(&card);
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));

	printf("Expected Results: WRONG_EXP_DATE\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");

	/********************************************* Test Case 5 *********************************/
	puts("===================================== Test Case 5 ========================================");
	printf("Test Case 5: card expiration date correct formate and length \n");

	printf("Input Data: ");
	actualResults = getCardExpiryDate(&card);
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));

	printf("Expected Results: CARD_OK\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
}

void getCardPANTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getCardPAN\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: corrrect card PAN number\n");

	printf("Input Data: ");
	actualResults = getCardPAN(&card);
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));

	printf("Expected Results: CARD_OK\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: card PAN number less than 16\n");

	printf("Input Data: ");
	actualResults = getCardPAN(&card);
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));

	printf("Expected Results: WRONG_PAN\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");

	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: card PAN number more than 19\n");

	printf("Input Data: ");
	actualResults = getCardPAN(&card);
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));

	printf("Expected Results: WRONG_PAN\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");

	/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: NULL card PAN number\n");

	printf("Input Data: ");
	actualResults = getCardPAN(&card);
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));

	printf("Expected Results: WRONG_PAN\n");

	printf("Actual Results:");
	actualResults == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");

}

//void main(void)
//{
//	getCardHolderNameTest();
//	getCardExpiryDateTest();
//	getCardPANTest();
//}