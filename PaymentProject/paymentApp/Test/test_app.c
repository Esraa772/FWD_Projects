#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "../App/app.h"

void main(void)
{
	uint8_t ch = 0;
	puts("Test 1\n-------------------------------------------------------------\n");
	/*
	* As a bank customer have an account and has a valid and not expired card, 
	I want to withdraw an amount of money less than the maximum allowed and 
	less than or equal to the amount in my balance, so that I am expecting 
	that the transaction is approved and my account balance is reduced by
	the withdrawn amount.
	*/
	appStart();
	scanf_s("%c", &ch, (uint8_t)sizeof(ch));
	puts("\nTest 2\n-------------------------------------------------------------\n");
	/*
	* As a bank customer have an account, that has a valid and not expired card, 
	I want to withdraw an amount of money that exceeds the maximum allowed amount 
	so that I am expecting the transaction declined.
	*/
	appStart();
	scanf_s("%c", &ch, (uint8_t)sizeof(ch));
	puts("\nTest 3\n-------------------------------------------------------------\n");
	/*
	* As a bank customer have an account and has a valid and not expired card, 
	I want to withdraw an amount of money less than the maximum allowed and 
	larger than the amount in my balance so that I am expecting that 
	the transaction declined.
	*/
	appStart();
	scanf_s("%c", &ch, (uint8_t)sizeof(ch));
	puts("\nTest 4\n-------------------------------------------------------------\n");
	/*
	* As a bank customer have an account and a valid but expired card, 
	I want to withdraw an amount of money so that I expect that the 
	transaction declined.
	*/
	appStart();
	scanf_s("%c", &ch, (uint8_t)sizeof(ch));
	puts("\nTest 5\n-------------------------------------------------------------\n");
	/*
	* As a bank customer have an account and has a valid and not expired 
	but stolen card, I want to block anyone from using my card so that 
	I am expecting that any transaction made by this card is declined.
	*/
	appStart();
}
