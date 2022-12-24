#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "test_server.h"
#include "../../Card/card.h"
#include "../../Terminal/terminal.h"
#include "../../Server/server.h"

extern ST_accountsDB_t accountsDB[255];

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
	printf("Function Name: listSavedTransactions\n");
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
	printf("Function Name: saveTransaction\n");
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
			.transState = DECLINED_INSUFFECIENT_FUND
		}
	};
		printf("===================================== Test Case 1 ========================================\n");
		printf("Test Case 1: save transactions \n");

		printf("Input Data (PAN, transAmmount, transState: %s, %f, ", transData[0].cardHolderData.primaryAccountNumber, transData[0].terminalData.transAmount);
		
		transData[0].transState == APPROVED ? printf("APPROVED\n") : 
			(transData[0].transState == DECLINED_STOLEN_CARD ? printf("DECLINED_STOLEN_CARD\n") : 
			(transData[0].transState == FRAUD_CARD ? printf("FRAUD_CARD\n") : printf("DECLINED_INSUFFECIENT_FUND\n")));
		actualResults = saveTransaction(&transData[0]);
		printf("Expected Results: ");

		printf("Actual Results: ");
		actualResults == SERVER_OK ? printf("SERVER_OK\n") : printf("SAVING_FAILED\n");
}

void recieveTransactionDataTest(void)
{
	ST_transaction_t transData;
	EN_transState_t actualResults;

	printf("Tester Namer: Esraa Abdelnaby\n");
	printf("Function Name: recieveTransactionData\n");
	puts("");

	strcpy_s(transData.cardHolderData.cardHolderName, sizeof("Esraa Abdelnaby Hassan"), "Esraa Abdelnaby Hassan");
	strcpy_s(transData.cardHolderData.cardExpirationDate, sizeof("11/21"), "11/21");
	strcpy_s(transData.terminalData.transactionDate, sizeof("30/01/2019"), "30/01/2019");
	transData.terminalData.maxTransAmount = 00.00;

	/********************************************* Test Case 1 *********************************/
	puts("===================================== Test Case 1 ========================================");
	printf("Test Case 1: acount is not found \n");

	printf("Input Data (PAN): 4738473109000000\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, sizeof(transData.cardHolderData.primaryAccountNumber), "4738473109000000");

	actualResults = recieveTransactionData(&transData);

	printf("Expected Results: FRAUD_CARD\n");

	printf("Actual Results:");
	(actualResults == APPROVED) ? printf("APPROVED\n") : printf("FRAUD_CARD\n");

	/********************************************* Test Case 2 *********************************/
	puts("===================================== Test Case 2 ========================================");
	printf("Test Case 2: acount is existed but blocked\n");

	printf("Input Data (PAN): 5807007076043875\n");

	memset(transData.cardHolderData.primaryAccountNumber, '\0', sizeof(transData.cardHolderData.primaryAccountNumber));

	strcpy_s(transData.cardHolderData.primaryAccountNumber, sizeof(transData.cardHolderData.primaryAccountNumber), "5807007076043875");

	actualResults = recieveTransactionData(&transData);

	printf("Expected Results: DECLINED_STOLEN_CARD\n");

	printf("Actual Results:");
	(actualResults == APPROVED) ? printf("APPROVED\n") : printf("DECLINED_STOLEN_CARD\n");

	/********************************************* Test Case 3 *********************************/
	puts("===================================== Test Case 3 ========================================");
	printf("Test Case 3: acount is running but low balance \n");

	printf("Input Data (PAN, balance, TransAmount): 0000000000053363, 11.0, 200.2\n");
	
	strcpy_s(transData.cardHolderData.primaryAccountNumber, sizeof(transData.cardHolderData.primaryAccountNumber), "0000000000053363");

	transData.terminalData.transAmount = 200.2;
	
	actualResults = recieveTransactionData(&transData);

	printf("Expected Results: DECLINED_INSUFFECIENT_FUND\n");

	printf("Actual Results:");
	(actualResults == APPROVED) ? printf("APPROVED\n") : printf("DECLINED_INSUFFECIENT_FUND\n");

	/********************************************* Test Case 4 *********************************/
	puts("===================================== Test Case 4 ========================================");
	printf("Test Case 4: acount is running with right balance and stored successfully \n");
	
	printf("Input Data (PAN, balance, TransAmount): 0000000000053363, 11.0, 10.0\n");

	strcpy_s(transData.cardHolderData.primaryAccountNumber, sizeof(transData.cardHolderData.primaryAccountNumber), "0000000000053363");

	transData.terminalData.transAmount = 10.0;

	actualResults = recieveTransactionData(&transData);

	printf("Expected Results: APPROVED\n");

	printf("Actual Results:");
	(actualResults == APPROVED) ? printf("APPROVED\n") : printf("DECLINED_INSUFFECIENT_FUND\n");
	printf("New balance for 0000000000053363 is: %f\n", accountsDB[2].balance);
}

