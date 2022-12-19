#include <stdint.h>
#include "card.h"

/*************************** PREPROCESSORS ********************/
#define MIN_CARD_NAME_LEN	0x14
#define MAX_CARD_NAME_LEN	0x18
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
