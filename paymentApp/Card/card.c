#include <stdint.h>
#include "card.h"

/*************************** PREPROCESSORS ********************/
#define MIN_CARD_NAME_LEN	     0x14
#define MAX_CARD_NAME_LEN	     0x18
#define CORRECT_EXP_DATE_LEN     0x05
#define PAN_MIN_LEN				 0x10
#define PAN_MAX_LEN				 0x13
/*************************************************************/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	EN_cardError_t funcState = CARD_OK;
	uint8_t charCount = 0;
	uint8_t length = 0;
	(void) gets(cardData->cardHolderName);
	length = strlen(cardData->cardHolderName);

	if (MIN_CARD_NAME_LEN > length || MAX_CARD_NAME_LEN < length)
	{
		funcState = WRONG_NAME;
	}
	return funcState;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	EN_cardError_t funcState = CARD_OK;
	uint8_t charCount = 0;
	uint8_t length = 0;
	(void)gets(cardData->cardExpirationDate);
	length = strlen(cardData->cardExpirationDate);

	if ( (CORRECT_EXP_DATE_LEN != length)              || 
		 (!isdigit((cardData->cardExpirationDate[0]))) || 
		 (!isdigit((cardData->cardExpirationDate[1]))) || 
		 (!isdigit((cardData->cardExpirationDate[3]))) || 
		 (!isdigit((cardData->cardExpirationDate[4]))) || 
		 (cardData->cardExpirationDate[2] != '/')      || 
		 (cardData->cardExpirationDate[0] > '1')       || 
		 ((cardData->cardExpirationDate[0] == '1') && (cardData->cardExpirationDate[1] > '2'))
		)
	{
		funcState = WRONG_EXP_DATE;
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

static EN_cardError_t luhnAlgorithm(uint8_t* panNumber, uint8_t len)
{
	EN_cardError_t funcState = CARD_OK;
	uint8_t charCount = 0;
	uint32_t sumOfPan = 0;
	for (charCount; charCount < len; charCount+=2)
	{
		panNumber[charCount] -= '0';
		panNumber[charCount + 1] -= '0';

		(panNumber[charCount] * 2) > 9 ? (panNumber[charCount] = (panNumber[charCount] * 2) - 9): (panNumber[charCount] *= 2);
		sumOfPan += (uint32_t)( panNumber[charCount] + panNumber[charCount+1]);
	}
	
	if ((sumOfPan % 10) != 0)
	{
		funcState = WRONG_PAN;
	}

	return funcState;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	EN_cardError_t funcState = CARD_OK;
	uint8_t length = 0;
	(void)gets(cardData->primaryAccountNumber);

	remove_spaces(cardData->primaryAccountNumber);

	length = strlen(cardData->primaryAccountNumber);

	if (PAN_MAX_LEN < length || PAN_MIN_LEN > length)
	{
		funcState = WRONG_PAN;
	}

	if (funcState != WRONG_PAN)
	{
		funcState = luhnAlgorithm(cardData->primaryAccountNumber, length);
	}
	return funcState;
}