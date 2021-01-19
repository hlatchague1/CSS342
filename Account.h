#include "Fund.h"
#include <stdio.h>
#include <iostream>

#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

const int MAX_NUM_FUNDS = 10;

class Account
{

	friend ostream& operator<< (ostream& os, const Account& account)
	{
		os << account.getFirstName() << " " << account.getLastName() << " Account ID: " << account.getAccountID();
		return os;
	}

public:
	Account();
	Account(int accountID);
	Account(string firstName, string lastName, int accountID);
	~Account();

	string getFirstName() const;
	string getLastName() const;
	int getAccountID() const;
	int getTotalBalance() const;

	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setAccountID(int accountID);

	Fund getFundByCorrespondingID(int fundID) const;
	string getFundName(int fundID) const;

	int findFundBalance(int fundID);
	void addToFundAccount(int amountAdded, int fundID);
	void writeToFund(int fundID, string text);
	void removeFromFundAccount(int amountRemoved, int fundID);
	void displayHistory();
	void displayFundHistory(int fundID);

	bool operator==(const Account& otherAccount) const;
	bool operator!=(const Account& otherAccount) const;
	bool operator<(const Account& otherAccount) const;
	bool operator>(const Account& otherAccount) const;

private:
	Fund funds[MAX_NUM_FUNDS];
	string firstName;
	string lastName;
	int accountID;
	int totalBalance;
};

#endif // !ACCOUNT_H

