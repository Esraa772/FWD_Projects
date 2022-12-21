#pragma once
#ifndef CARD_H
#define CARD_H

/*********************************** Data containers **************************************/
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[21];
    uint8_t cardExpirationDate[7];
}ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;
/*****************************************************************************************/

/***************************************** Functions *************************************/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);
/*****************************************************************************************/

#endif // !CARD_H

