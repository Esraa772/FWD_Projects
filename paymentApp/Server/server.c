#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

ST_accountsDB_t accountsDB[255]=
{
	{2000.0,    RUNNING, "8989374615436851"},
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
	{4000,      BLOCKED, "4738473109000000"},
};

ST_transaction_t transactionsDB[255] = {
	{{"","",""},{0.0,0.0,""},0,0},
};

EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
{
	EN_transState_t funcState = FRAUD_CARD;
	uint16_t DBsize = sizeof(accountsDB) / sizeof(accountsDB[0]);
	uint16_t loopCounter;
	for (loopCounter = 0; loopCounter < DBsize; loopCounter++)
	{
		if (0 == strcmp(accountsDB[0].primaryAccountNumber, cardData->primaryAccountNumber))
		{
			accountRefrence->balance = accountsDB[loopCounter].balance;
			strcpy(accountRefrence->primaryAccountNumber, accountsDB[loopCounter].primaryAccountNumber);
			accountRefrence->state = accountsDB[loopCounter].state;
			funcState = APPROVED;
			break;
		}
	}
	return funcState;
}

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	EN_transState_t funcState = APPROVED;
	ST_accountsDB_t accountRefrence;
	funcState = isValidAccount(&(transData->cardHolderData), &accountRefrence);
	if (FRAUD_CARD != funcState)
	{
		if (transData->terminalData.transAmount > accountRefrence.balance)
		{
			funcState = DECLINED_INSUFFECIENT_FUND;
		}
		else if (accountRefrence.state == BLOCKED)
		{
			funcState = DECLINED_STOLEN_CARD;
		}

		else if ( transData->transactionSequenceNumber <= accountRefrence.)
		{
			funcState = INTERNAL_SERVER_ERROR;
		}
	}

	return funcState;
}
