#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../../Card/card.h"
#include "../../Terminal/terminal.h"

void getTransactionDateTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getTransactionDate\n");
	puts("");
	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: NULL transaction date\n");

	printf("Input Data: ");
	actualResults = getTransactionDate(&termData);
	memset(termData.transactionDate, '\0', sizeof(termData.transactionDate));

	printf("Expected Results: WRONG_DATE\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: transaction date less than 10\n");

	printf("Input Data: ");
	actualResults = getTransactionDate(&termData);
	memset(termData.transactionDate, '\0', sizeof(termData.transactionDate));

	printf("Expected Results: WRONG_DATE\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");

	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: transaction date more than 10\n");

	printf("Input Data: ");
	actualResults = getTransactionDate(&termData);
	memset(termData.transactionDate, '\0', sizeof(termData.transactionDate));

	printf("Expected Results: WRONG_DATE\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");

	/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: transaction date wrong formate\n");

	printf("Input Data: ");
	actualResults = getTransactionDate(&termData);
	memset(termData.transactionDate, '\0', sizeof(termData.transactionDate));

	printf("Expected Results: WRONG_DATE\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");

	/********************************************* Test Case 5 *********************************/
	puts("===================================== Test Case 5 ========================================");
	printf("Test Case 5: correct transaction date\n");

	printf("Input Data: ");
	actualResults = getTransactionDate(&termData);
	memset(termData.transactionDate, '\0', sizeof(termData.transactionDate));

	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
}

void isCardExpriedTest(void)
{
	ST_cardData_t cardData;
	ST_terminalData_t termData;
	EN_terminalError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isCardExpried\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: Card is still working \n");

	printf("Input Data (card expiration date): ");
	actualResults = getCardExpiryDate (&cardData);
	printf("Input Data (transaction date): ");
	actualResults = getTransactionDate (&termData);

	actualResults = isCardExpired(&cardData, &termData);

	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXPIRED_CARD\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: Card is expired \n");

	printf("Input Data (card expiration date): ");
	actualResults = getCardExpiryDate(&cardData);
	printf("Input Data (transaction date): ");
	actualResults = getTransactionDate(&termData);

	actualResults = isCardExpired(&cardData, &termData);

	printf("Expected Results: EXPIRED_CARD\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXPIRED_CARD\n");
}

void getTransactionAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: getTransactionAmount\n");
	puts("");
	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: amount less than 0\n");

	printf("Input Data: ");
	actualResults = getTransactionAmount(&termData);

	printf("Expected Results: INVALID_AMOUNT\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: amount is 0\n");

	printf("Input Data: ");
	actualResults = getTransactionAmount(&termData);

	printf("Expected Results: INVALID_AMOUNT\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");

	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: amount is correct\n");

	printf("Input Data: ");
	actualResults = getTransactionAmount(&termData);

	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");

}

void isBelowMaxAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBelowMaxAmount\n");
	puts("");
	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: amount exceed maximum\n");

	printf("Input Data (the max is 500.0): 600.99\n");
	termData.maxTransAmount = 500.0;
	termData.transAmount = 600.99;
	actualResults = isBelowMaxAmount(&termData);

	printf("Expected Results: EXCEED_MAX_AMOUNT\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNTs\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: amount is below maximum\n");

	printf("Input Data (the max is 500.0): 200.05\n");
	termData.maxTransAmount = 500.0;
	termData.transAmount = 200.05;
	actualResults = isBelowMaxAmount(&termData);

	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNT\n");
}

void setMaxAmountTest(void)
{
	ST_terminalData_t termData;
	EN_terminalError_t actualResults;
	float maxTransAmount;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBelowMaxAmount\n");
	puts("");
	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: maximum amount is less than 0 \n");

	printf("Input Data : -225.88\n");
	maxTransAmount = -225.88;
	actualResults = setMaxAmount(&termData, maxTransAmount);

	printf("Expected Results: INVALID_MAX_AMOUNT\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNTs\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: maximum amount is 0 \n");

	printf("Input Data : 0.0\n");
	maxTransAmount = 0.0;
	actualResults = setMaxAmount(&termData, maxTransAmount);

	printf("Expected Results: INVALID_MAX_AMOUNT\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNTs\n");
	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: maximum amount correct\n");

	printf("Input Data : 55.99\n");
	maxTransAmount = 55.99;
	actualResults = setMaxAmount(&termData, maxTransAmount);

	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNTs\n");
}

void isValidCardPANTest(void)
{
	ST_cardData_t cardData;
	EN_terminalError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isValidCardPAN\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: Card PAN is not Luhn number\n");

	printf("Input Data: ");
	actualResults = getCardPAN(&cardData);

	actualResults = isValidCardPAN(&cardData);
	printf("Expected Results: INVALID_CARD\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_CARD\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: Card PAN is a valid Luhn number\n");
	memset(cardData.primaryAccountNumber, '\0', sizeof(cardData.primaryAccountNumber));
	printf("Input Data: ");
	actualResults = getCardPAN(&cardData);

	actualResults = isValidCardPAN(&cardData);
	printf("Expected Results: TERMINAL_OK\n");

	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_CARD\n");

}
