#pragma once
#ifndef DB_H
#define DE_H

ST_accountsDB_t accountsDB[] =
{
	{2000.0,   RUNNING, "8989374615436851"},
	{100000.0, RUNNING, "0000000000007443"},
	{11.0,     RUNNING, "0000000000053363"},
	{1500.0,   RUNNING, "0000000208042010"},
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


#endif // !DB_H
