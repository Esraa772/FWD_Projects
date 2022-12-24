#include <stdint.h>
#include <stdio.h>
#include "test_server.h"
#include "../../Card/card.h"
#include "../../Terminal/terminal.h"
#include "../../Server/server.h"

ST_accountsDB_t accountsDB[255];

ST_transaction_t transactionsDB[255];

void isValidAccountTest(void)
{
	ST_cardData_t cardData;
	ST_accountsDB_t accountRefrence;
	EN_serverError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isValidAccount\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: acount not found\n");

	printf("Input Data (card Pan): 4738473109000000\n");
	/*test: "4738473109000000"*/
	strcpy_s(cardData.primaryAccountNumber,sizeof(cardData.primaryAccountNumber), "4738473109000000");

	actualResults = isValidAccount(&cardData, &accountRefrence);
	printf("Expected Results: ACCOUNT_NOT_FOUND\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK && &accountRefrence != NULL) ? printf("SERVER_OK\n") : printf("ACCOUNT_NOT_FOUND\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: acount is existed\n");

	//memset(cardData.primaryAccountNumber, '\0', sizeof(cardData.primaryAccountNumber));
	printf("Input Data (card Pan): 0000000000007443\n");
	/*test: "0000000000007443"*/
	strcpy_s(cardData.primaryAccountNumber, sizeof(cardData.primaryAccountNumber), "0000000000007443");

	actualResults = isValidAccount(&cardData, &accountRefrence);
	printf("Expected Results: SERVER_OK\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK && &accountRefrence != NULL) ? printf("SERVER_OK\n") : printf("ACCOUNT_NOT_FOUND\n");
}

void isBlockedAccountTest(void)
{
	ST_cardData_t cardData;
	ST_accountsDB_t accountRefrence;
	EN_serverError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBlockedAccount\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: acount is Blocked \n");

	printf("Input Data (card Pan): 4738398603000000\n");
	/*test: "4738473109000000"*/
	strcpy_s(cardData.primaryAccountNumber, sizeof(cardData.primaryAccountNumber), "4738398603000000");

	(void) isValidAccount(&cardData, &accountRefrence);
	actualResults = isBlockedAccount(&accountRefrence);

	printf("Expected Results: BLOCKED_ACCOUNT\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK && &accountRefrence != NULL) ? printf("SERVER_OK\n") : printf("BLOCKED_ACCOUNT\n");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: acount is Blocked \n");

	printf("Input Data (card Pan): 0000000000053363\n");
	/*test: "4738473109000000"*/
	strcpy_s(cardData.primaryAccountNumber, sizeof(cardData.primaryAccountNumber), "0000000000053363");

	(void)isValidAccount(&cardData, &accountRefrence);
	actualResults = isBlockedAccount(&accountRefrence);

	printf("Expected Results: SERVER_OK\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK && &accountRefrence != NULL) ? printf("SERVER_OK\n") : printf("BLOCKED_ACCOUNT\n");

}

void isAmountAvailableTest(void)
{
	ST_terminalData_t termData;
	ST_accountsDB_t accountRefrence;
	EN_serverError_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBlockedAccount\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: acount is low balance \n");

	printf("Input Data (PAN, balance, TransAmount): 0000000000053363, 11.0, 200.2\n");
	termData.transAmount = 200.2;
	actualResults = isAmountAvailable(&termData,&accountsDB[2]);

	printf("Expected Results: LOW_BALANCE\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK) ? printf("SERVER_OK\n") : printf("LOW_BALANCE\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: acount is with the available balance range \n");

	printf("Input Data (PAN, balance, TransAmount): 0000000000007443, 100000.0, 1200.0\n");
	termData.transAmount = 1200.0;
	actualResults = isAmountAvailable(&termData, &accountsDB[1]);

	printf("Expected Results: SERVER_OK\n");

	printf("Actual Results:");
	(actualResults == SERVER_OK) ? printf("SERVER_OK\n") : printf("LOW_BALANCE\n");

}

void listSavedTransactionsTest(void)
{
	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBlockedAccount\n");
	puts("");

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: list all transactions\n");

	printf("Input Data: No input\n");
	listSavedTransactions();

	printf("Expected Results: NONE\n");

	printf("Actual Results: NONE");
}

void saveTransactionTest(void)
{
	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: isBlockedAccount\n");
	puts("");
	EN_serverError_t actualResults;
	ST_transaction_t transData[4] = {
		{
			/* DECLINED_INSUFFECIENT_FUND */
			.cardHolderData.cardHolderName = NULL,
			.cardHolderData.primaryAccountNumber = "0000000000053363",
			.cardHolderData.cardExpirationDate = NULL,
			.terminalData.transAmount = 200.0,
			.terminalData.transactionDate = NULL,
			.terminalData.maxTransAmount = 00.0,
			.transState = DECLINED_INSUFFECIENT_FUND,
		},
		{
			/* APPROVED */
			.cardHolderData.primaryAccountNumber = "0000000000007443",
			.terminalData.transAmount = 1200.0,
			.transState = APPROVED,
		},
		{
			/* BLOCKED ACCOUNT */
			.cardHolderData.primaryAccountNumber = "4738398603000000",
			.terminalData.transAmount = 20.00,
			.transState = DECLINED_STOLEN_CARD,
        },
		{
			/* FRAUD CARD*/
			.cardHolderData.primaryAccountNumber = "1368589636987841",
			.terminalData.transAmount = 200.00,
			.transState = FRAUD_CARD,
		},
	};
	uint8_t j = 0;
	for (uint16_t i = 0; i < 257; i++)
	{
		if (j > 3)
		{
			j = 0;
		}

		printf("===================================== Test Case %d ========================================\n", i+1);
		printf("Test Case %d: save transactions \n", i+1);

		printf("Input Data (PAN, transAmmount, transState: %s, %f, ", transData[j].cardHolderData.primaryAccountNumber, transData[j].terminalData.transAmount);
		
		transData[j].transState == APPROVED ? printf("APPROVED\n") : 
			(transData[j].transState == DECLINED_STOLEN_CARD ? printf("DECLINED_STOLEN_CARD\n") : 
			(transData[j].transState == FRAUD_CARD ? printf("FRAUD_CARD\n") : printf("DECLINED_INSUFFECIENT_FUND\n")));
		actualResults = saveTransaction(&transData[j]);
		printf("Expected Results: ");

		255 > i ? printf("SERVER_OK\n") : printf("SAVING_FAILED\n");

		printf("Actual Results: ");
		actualResults == SERVER_OK ? printf("SERVER_OK\n") : printf("SAVING_FAILED\n");

		j++;
		getch();
	}
}

