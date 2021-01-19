#include "Account.h"
#include <iostream>

using namespace std;

Account::Account()
{
	funds[0].setFundName("Money Market");
	funds[1].setFundName("Prime Money Market");
	funds[2].setFundName("Long-Term Bond");
	funds[3].setFundName("Short-Term Bond");
	funds[4].setFundName("500 Index Fund");
	funds[5].setFundName("Capital Value Fund");
	funds[6].setFundName("Growth Equity Fund");
	funds[7].setFundName("Growth Index Fund");
	funds[8].setFundName("Value Fund");
	funds[9].setFundName("Value Stock Index");
}

Account::Account(int accountID)
{
	this->accountID = accountID;
}

Account::Account(string firstName, string lastName, int accountID)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->accountID = accountID;
}

Account::~Account()
{
}

string Account::getFirstName() const
{
	return firstName;
}

string Account::getLastName() const
{
	return lastName;
}

int Account::getAccountID() const
{
	return accountID;
}

Fund Account::getFundByCorrespondingID(int fundID) const
{
	return funds[fundID];
}

string Account::getFundName(int fundID) const
{
	return funds[fundID].getFundName();
}

int Account::getTotalBalance() const
{
	return totalBalance;
}

void Account::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Account::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Account::setAccountID(int ID)
{
	accountID = ID;
}

int Account::findFundBalance(int fundID)
{
	Fund thisFund = funds[fundID];
	return thisFund.getFundBalance();
}

void Account::addToFundAccount(int amountAdded, int fundID)
{
	funds[fundID].addToFund(amountAdded);
}

void Account::removeFromFundAccount(int amountRemoved, int fundID)
{
	funds[fundID].subtractFromFund(amountRemoved);
}

void Account::displayHistory()
{
	for (int i = 0; i < MAX_NUM_FUNDS; i++)
	{
		cout << funds[i];
	}
}

void Account::writeToFund(int fundID, string text)
{
	funds[fundID].addToTransactionHistory(text);
}

void Account::displayFundHistory(int fundID)
{
	cout << funds[fundID].getFundName() << ": $" << funds[fundID].getFundBalance() << endl;
	funds[fundID].displayTransactionHistory();
}

bool Account::operator==(const Account& otherAccount) const
{
	if (accountID == otherAccount.accountID)
	{
		return true;
	}
	return false;
}

bool Account::operator!=(const Account& otherAccount) const
{
	if (accountID != otherAccount.accountID)
	{
		return true;
	}
	return false;
}

bool Account::operator<(const Account& otherAccount) const
{
	if (accountID < otherAccount.accountID)
	{
		return true;
	}
	return false;
}

bool Account::operator>(const Account& otherAccount) const
{
	if (accountID > otherAccount.accountID)
	{
		return true;
	}
	return false;
}
