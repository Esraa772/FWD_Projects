#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "terminal.h"

/********************************** preprocessors ********************/
#define MAX_TERM_DATE_LEN 0x0A
/*********************************************************************/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t funcState = TERMINAL_OK;
	uint8_t length = 0;
	(void)gets(termData->transactionDate);
	length = strlen(termData->transactionDate);

	if (MAX_TERM_DATE_LEN != length)
	{
		funcState = WRONG_DATE;
	}
	else if (funcState != WRONG_DATE)
	{
		for (uint8_t i = 0; i < length; i++)
		{
			if (i == 2 || i == 5)
			{
				if (termData->transactionDate[i] != '/')
				{
					funcState = WRONG_DATE;
					break;
				}
			}
			else if (!isdigit(termData->transactionDate[i]))
			{
				funcState = WRONG_DATE;
				break;
			}
		}
		if (funcState != WRONG_DATE)
		{
			if (termData->transactionDate[3] == '0' && termData->transactionDate[4] == '2' && termData->transactionDate[0] > '2')
			{
				funcState = WRONG_DATE;
			}
			else if ((termData->transactionDate[0] > '3') || (termData->transactionDate[1] > '9') || (termData->transactionDate[3] > '1'))
			{
				funcState = WRONG_DATE;
			}
			else if (termData->transactionDate[3] == '1' && termData->transactionDate[4] > '2')
			{
				funcState = WRONG_DATE;
			}

		}
	}


	return funcState;
}

static void remove_spaces(uint8_t* primaryAccountNumber) {
	uint8_t* cleanPrimaryAccountNumber = primaryAccountNumber;
	do {
		while (*cleanPrimaryAccountNumber == ' ') {
			++cleanPrimaryAccountNumber;
		}
	} while (*primaryAccountNumber++ = *cleanPrimaryAccountNumber++);
}

//EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
//{
//	EN_terminalError_t funcState = TERMINAL_OK;
//	uint8_t charCount = 0;
//	uint8_t tempData;
//	uint32_t sumOfPan = 0;
//	uint8_t length;
//	if (cardData->primaryAccountNumber == NULL)
//	{
//		funcState = INVALID_CARD;
//	}
//	else
//	{
//		remove_spaces(cardData->primaryAccountNumber);
//
//		length = strlen(cardData->primaryAccountNumber);
//
//		for (charCount; charCount < length; charCount += 2)
//		{
//			tempData = cardData->primaryAccountNumber[charCount] - '0';
//			
//			((tempData * 2) > 9) ? ((tempData *= 2) - 9) : (tempData *= 2);
//
//			sumOfPan += (uint32_t)(tempData + (cardData->primaryAccountNumber[charCount + 1] - '0'));
//		}
//
//		if ((sumOfPan % 10) != 0 && sumOfPan != 0)
//		{
//			funcState = INVALID_CARD;
//		}
//	}
//
//	return funcState;
//}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	EN_terminalError_t funcState = TERMINAL_OK;
	uint8_t cradYear = ((cardData->cardExpirationDate[3] - '0') * 10) + (cardData->cardExpirationDate[4] - '0');
	uint8_t termYear = ((termData->transactionDate[8] - '0') * 10) + (termData->transactionDate[9]-'0');
	uint8_t cradMonth = ((cardData->cardExpirationDate[0] - '0') * 10) + (cardData->cardExpirationDate[1] - '0');
	uint8_t termMonth = ((termData->transactionDate[3] - '0') * 10) + (termData->transactionDate[4] - '0');

	if (cradYear < termYear || (cradYear == termYear && cradMonth < termMonth))
	{
		funcState = EXPIRED_CARD;
	}

	return funcState;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t funcState = TERMINAL_OK;
	scanf_s("%f", &termData->transAmount);
	if (termData->transAmount <= 0)
	{
		funcState = INVALID_AMOUNT;
	}

	return funcState;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t funcState = TERMINAL_OK;
	if (termData->transAmount > termData->maxTransAmount)
	{
		funcState = EXCEED_MAX_AMOUNT;
	}

	return funcState;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	EN_terminalError_t funcState = TERMINAL_OK;
	if (maxAmount <= 0)
	{
		funcState = INVALID_MAX_AMOUNT;
	}

	if (INVALID_MAX_AMOUNT != funcState)
	{
		termData->maxTransAmount = maxAmount;
	}

	return funcState;
}
