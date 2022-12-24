#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "app.h"

extern ST_accountsDB_t accountsDB[255];

void appStart(void)
{
	EN_cardError_t cardState;
	EN_terminalError_t termState;
	ST_accountsDB_t accountRefrence;
	ST_transaction_t transData;
	EN_transState_t transState;
	
	float maxAmount = 100.0;

	setMaxAmount(&transData.terminalData, maxAmount);

	printf("Enter card holder name: ");
	cardState = getCardHolderName(&transData.cardHolderData);
	if (cardState == WRONG_NAME)
	{
		printf("Wrong card name! please enter a name between 20 to 24 characters.\n");
		return;
	}

	printf("Enter card expiration date: ");
	cardState = getCardExpiryDate(&transData.cardHolderData);
	if (cardState == WRONG_EXP_DATE)
	{
		printf("Wrong expiration date! please enter it in formate MM/YY.\n");
		return;
	}

	printf("Enter card PAN: ");
	cardState = getCardPAN(&transData.cardHolderData);
	if (cardState == WRONG_PAN)
	{
		printf("Wrong card PAN! please enter PAN number between 16 to 19 digits.\n");
		return;
	}

	printf("Enter transaction date: ");
	termState = getTransactionDate(&transData.terminalData);
	if (termState == WRONG_DATE)
	{
		printf("Wrong transaction date! please enter it in formate DD/MM/YY.\n");
		return;
	}
	termState = isCardExpired(&transData.cardHolderData, &transData.terminalData);
	if (termState == EXPIRED_CARD)
	{
		printf("Expired Card! Please try another one with valid expiration Date.\n");
		return;
	}

	printf("Enter transaction amount: ");
	termState = getTransactionAmount(&transData.terminalData);
	if (termState == INVALID_AMOUNT)
	{
		printf("invalid amount! Please try another one, higher than zero, in this fomrate xx.xx.\n");
		return;
	}

	termState = isBelowMaxAmount(&transData.terminalData);
	if (termState == EXCEED_MAX_AMOUNT)
	{
		printf("invalid amount! please enter an amount below the Maximum %f.\n", maxAmount);
		return;
	}

	termState = isValidCardPAN(&transData.cardHolderData);
	if (INVALID_CARD == termState)
	{
		printf("Fraud card Declined! invalid card the PAN number is not a real card number\n");
		return;
	}
	
	transState = recieveTransactionData (&transData);

	if (FRAUD_CARD == transState)
	{
		printf("Declined! Account not found!\n");
		return;
	}
	if (DECLINED_STOLEN_CARD == transState)
	{
		printf("Declined! card is blocked! \n");
		return;
	}
	if (DECLINED_INSUFFECIENT_FUND == transState)
	{
		printf("Declined! insuffecient fund! \n");
		return;
	}
	if (INTERNAL_SERVER_ERROR == transState)
	{
		printf("Declined! cannot save transaction! \n");
		return;
	}

	isValidAccount(&transData.cardHolderData, &accountRefrence);
	printf("Transaction saved! Your new balance is: %f\n", accountRefrence.balance);
}