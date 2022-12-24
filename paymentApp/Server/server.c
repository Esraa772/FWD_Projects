#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

ST_accountsDB_t accountsDB[]=
{
	{2000.0, RUNNING, "8989374615436851"},
	{100000.0, RUNNING, "0000000000007443"},
	{11.0, RUNNING, "0000000000053363"},
	{
		.balance = 1500.0,
		.state = RUNNING,
		.primaryAccountNumber = "0000000208042010"
	}, 
	{
		.balance = 1000000.0,
		.state = RUNNING,
		.primaryAccountNumber = "4130050008020406"
	},
	{
		.balance = 1000.0,
		.state = RUNNING,
		.primaryAccountNumber = "6500020049010200"
	},
	{
		.balance = 765000.99,
		.state = RUNNING,
		.primaryAccountNumber = "4738744301000000"
	},
	{
		.balance = 80000.0,
		.state = BLOCKED,
		.primaryAccountNumber = "5807007076043875"
	},
	{
		.balance = 4600000.0,
		.state = RUNNING,
		.primaryAccountNumber = "0776440005050406"
	},
	{7500000.0, RUNNING, "4738526401000000"},
	{600000.0,BLOCKED, "4738398603000000"},
};

ST_transaction_t transactionsDB[] =
{
	{
		NULL
	},
};


EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	EN_serverError_t funcState = ACCOUNT_NOT_FOUND;
	uint16_t DBsize = sizeof(accountsDB)/sizeof(accountsDB[0]);

	uint16_t loopCounter;
	for (loopCounter = 0; loopCounter < DBsize; loopCounter++)
	{
		if (0 == strcmp(accountsDB[loopCounter].primaryAccountNumber, cardData->primaryAccountNumber))
		{
			accountRefrence->balance = accountsDB[loopCounter].balance;
			strcpy_s(accountRefrence->primaryAccountNumber,sizeof(accountRefrence->primaryAccountNumber), accountsDB[loopCounter].primaryAccountNumber);
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
	EN_serverError_t funcState = SERVER_OK;

	if (termData->transAmount > accountRefrence->balance)
	{
		funcState = LOW_BALANCE;
	}
	return funcState;
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	EN_serverError_t funcState = SERVER_OK;
	static uint32_t transactionSequenceNumber;
	static uint16_t storedDBSize;

	transData->transactionSequenceNumber = (++transactionSequenceNumber);
	if (storedDBSize > 254)
	{
		funcState = SAVING_FAILED;
	}

	if (SERVER_OK == funcState && transData->cardHolderData.primaryAccountNumber != NULL)
	{
		transactionsDB[storedDBSize].transState = transData->transState;

		strcpy_s(transactionsDB[storedDBSize].cardHolderData.cardHolderName, sizeof(transData->cardHolderData.cardHolderName), transData->cardHolderData.cardHolderName);
		strcpy_s(transactionsDB[storedDBSize].cardHolderData.cardExpirationDate, sizeof(transData->cardHolderData.cardExpirationDate), transData->cardHolderData.cardExpirationDate);
		strcpy_s(transactionsDB[storedDBSize].cardHolderData.primaryAccountNumber, sizeof(transData->cardHolderData.primaryAccountNumber), transData->cardHolderData.primaryAccountNumber);

		strcpy_s(transactionsDB[storedDBSize].terminalData.transactionDate, sizeof(transData->terminalData.transactionDate), transData->terminalData.transactionDate);
		
		transactionsDB[storedDBSize].terminalData.transAmount = transData->terminalData.transAmount;
		transactionsDB[storedDBSize].terminalData.maxTransAmount = transData->terminalData.maxTransAmount;

		storedDBSize++;

		listSavedTransactions();
	}

	return funcState;
}

void listSavedTransactions(void)
{
	uint16_t DBsize;
	uint16_t loopCounter;
	DBsize = sizeof(transactionsDB) / sizeof(transactionsDB[0]);

	if (0 == DBsize)
	{
		printf("No saved transactions to list!\n");
	}
	for (loopCounter = 0; loopCounter < DBsize; loopCounter++)
	{
		puts("#########################");
		printf("Transaction Sequence Number: %d\n", transactionsDB[loopCounter].transactionSequenceNumber);
		printf("Transaction Date: %s\n", transactionsDB[loopCounter].terminalData.transactionDate);
		printf("Transaction Amount: %f\n", transactionsDB[loopCounter].terminalData.transAmount);
		
		if (APPROVED == transactionsDB[loopCounter].transState)
		{
			printf("Transaction State: APPROVED\n");
		}
		else if (DECLINED_INSUFFECIENT_FUND == transactionsDB[loopCounter].transState)
		{
			printf("Transaction State: DECLINED_INSUFFECIENT_FUND\n");
		}
		else if (DECLINED_STOLEN_CARD == transactionsDB[loopCounter].transState)
		{
			printf("Transaction State: DECLINED_STOLEN_CARD\n");
		}
		else if (FRAUD_CARD == transactionsDB[loopCounter].transState)
		{
			printf("Transaction State: FRAUD_CARD\n");
		}
		else if (INTERNAL_SERVER_ERROR == transactionsDB[loopCounter].transState)
		{
			printf("Transaction State: INTERNAL_SERVER_ERROR\n");
		}
		
		printf("Terminal Max Amount: %f\n", transactionsDB[loopCounter].terminalData.maxTransAmount);
		printf("Cardholder Name: %s\n", transactionsDB[loopCounter].cardHolderData.cardHolderName);
		printf("PAN: %s\n", transactionsDB[loopCounter].cardHolderData.primaryAccountNumber);
		printf("Card Expiration Date: %s\n", transactionsDB[loopCounter].cardHolderData.cardExpirationDate);
		puts("#########################");
	}
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	ST_accountsDB_t accountRefrence;
	uint8_t loopCounter;
	uint8_t DBsize = sizeof(accountsDB) / sizeof(accountsDB[0]);

	transData->transState = APPROVED;
	if (APPROVED == transData->transState && ACCOUNT_NOT_FOUND == isValidAccount(&transData->cardHolderData, &accountRefrence))
	{
		transData->transState = FRAUD_CARD;
	}
	if (APPROVED == transData->transState && BLOCKED_ACCOUNT == isBlockedAccount(&accountRefrence))
	{
		transData->transState = DECLINED_STOLEN_CARD;
	}
	if (APPROVED == transData->transState && LOW_BALANCE == isAmountAvailable(&transData->terminalData, &accountRefrence))
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
	}

	if (APPROVED == transData->transState && (SAVING_FAILED ==  saveTransaction(transData)))
	{
		transData->transState = INTERNAL_SERVER_ERROR;
	}

	if (APPROVED == transData->transState)
	{
		accountRefrence.balance -= transData->terminalData.transAmount;
		for (loopCounter = 0; loopCounter < DBsize; loopCounter++)
		{
			if (0 == strcmp(accountsDB[loopCounter].primaryAccountNumber, transData->cardHolderData.primaryAccountNumber))
			{
				accountsDB[loopCounter].balance = accountRefrence.balance;
			}
		}
	}
	return transData->transState;
}
