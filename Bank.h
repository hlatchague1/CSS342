#include "Account.h"
#include "BSTree.h"
#include <queue>
#include <stdio.h>
#include <iostream>

#ifndef BANK_H
#define BANK_H

using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	bool CreateTransaction(string fileName);
	void FulfillTransaction();
	bool OpenAccount(string firstName, string lastName, int accountID);
	bool Deposit(int accountID, int accountFundNumber, int amount, string transactionLine);
	bool Deposit(int accountID, int accountFundNumber, int amount);
	bool Withdraw(int accountID, int accountFundNumber, int amount, string transactionLine);
	bool Withdraw(int accountID, int accountFundNumber, int amount);
	bool Transfer(int givingAccountID, int givingAccountFundNumber, int amount, int receivingAccountID, int receivingAccountFundNumber);
	
	void DisplayTransactionHistory(int accountID, int fundNumber);
	void DisplayTransactionHistory(int accountID);
	void Display();

private:
	queue<string> transactionQueue; 
	BSTree treeOfAccounts;
};

#endif // !BANK_H