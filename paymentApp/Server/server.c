#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

ST_accountsDB_t accountsDB[]=
{
	{
	.balance = 2000.0,
	.state = RUNNING,
	.primaryAccountNumber = "8989374615436851"
	},
	{100000.0,  RUNNING, "0000000000007443"},
	{11.0,      RUNNING, "0000000000053363"},
	{1500.0,    RUNNING, "0000000208042010"},
	{1000000.0, RUNNING, "4130050008020406"},
	{1000.0,    RUNNING, "6500020049010200"},
	{765000.99, RUNNING, "4738744301000000"},

	{80000.0,   RUNNING, "5807007076043875"},
	{4600000.0, RUNNING, "0776440005050406"},
	{7500000.0, RUNNING, "4738526401000000"},
	{600000.0,  BLOCKED, "4738398603000000"},
};

ST_transaction_t transactionsDB[255];

static uint16_t storedDBSize = 0;

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t funcState = ACCOUNT_NOT_FOUND;
	uint16_t DBsize = sizeof(accountsDB) / sizeof(accountsDB[0]);
	uint16_t loopCounter;
	for (loopCounter = 0; loopCounter < DBsize; loopCounter++)
	{
		if (0 == strcmp(accountsDB[loopCounter].primaryAccountNumber, cardData->primaryAccountNumber))
		{
			accountRefrence->balance = accountsDB[loopCounter].balance;
			strcpy_s(accountRefrence->primaryAccountNumber,sizeof(accountsDB[loopCounter].primaryAccountNumber), accountsDB[loopCounter].primaryAccountNumber);
			accountRefrence->state = accountsDB[loopCounter].state;
			funcState = SERVER_OK;
			break;
		}
	}
	return funcState;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t funcState = SERVER_OK;
	if (BLOCKED == accountRefrence->state)
	{
		funcState = BLOCKED_ACCOUNT;
	}
	return funcState;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t funcState = LOW_BALANCE;

	if (termData->transAmount <= accountRefrence->balance)
	{
		funcState = SERVER_OK;
	}
	return funcState;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	static uint32_t transactionSequenceNumber = 0;
	EN_serverError_t funcState = SERVER_OK;

	transData->transactionSequenceNumber = (++transactionSequenceNumber);
	if (storedDBSize > 254)
	{
		funcState = SAVING_FAILED;
	}
	if (SERVER_OK == funcState)
	{
		transactionsDB[storedDBSize].transState = transData->transState;

		strcpy_s(&(transactionsDB[storedDBSize].cardHolderData.cardHolderName), sizeof(transData->cardHolderData.cardHolderName), &(transData->cardHolderData.cardHolderName));
		strcpy_s(transactionsDB[storedDBSize].cardHolderData.cardExpirationDate, sizeof(transData->cardHolderData.cardExpirationDate), transData->cardHolderData.cardExpirationDate);
		strcpy_s(transactionsDB[storedDBSize].cardHolderData.primaryAccountNumber, sizeof(transData->cardHolderData.primaryAccountNumber), transData->cardHolderData.primaryAccountNumber);

		strcpy_s(transactionsDB[storedDBSize].terminalData.transactionDate, sizeof(transData->terminalData.transactionDate), transData->terminalData.transactionDate);
		transactionsDB[storedDBSize].terminalData.transAmount = transData->terminalData.transAmount;
		transactionsDB[storedDBSize].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;

		printf("%s \n", transactionsDB[storedDBSize].cardHolderData.primaryAccountNumber);
		printf("%d\n", storedDBSize);
		storedDBSize++;

		listSavedTransactions();
	}

	return funcState;
}

void listSavedTransactions(void)
{
	uint16_t DBsize;
	uint16_t loopCounter;
	//DBsize = strlen(transactionsDB);

	//printf("%d \n", DBsize);
	if (0 == storedDBSize)
	{
		printf("No saved transactions to list!\n");
	}
	for (loopCounter = 0; loopCounter < storedDBSize ; loopCounter++)
	{
		puts("#########################");
		printf("Transaction Sequence Number : %d\n", transactionsDB[loopCounter].transactionSequenceNumber);
		printf("Transaction Date : %s\n", transactionsDB[loopCounter].terminalData.transactionDate);
		printf("Transaction Amount : %f\n", transactionsDB[loopCounter].terminalData.transAmount);
		printf("Transaction State : %d\n", transactionsDB[loopCounter].transState);
		printf("Terminal Max Amount : %f\n", transactionsDB[loopCounter].terminalData.maxTransAmount);
		printf("Cardholder Name : %s\n", transactionsDB[loopCounter].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transactionsDB[loopCounter].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date : %s\n", transactionsDB[loopCounter].cardHolderData.cardExpirationDate);
		puts("#########################");
	}
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t funcState = APPROVED;
	ST_accountsDB_t accountRefrence;
	
	return funcState;
}
