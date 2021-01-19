#include "Fund.h"
#include <iostream>

using namespace std; 

Fund::Fund()
{
	this->fundBalance = 0;
}

Fund::Fund(string fundName)
{
	this->fundName = fundName;
}

Fund::~Fund()
{
}

string Fund::getFundName() const
{
	return fundName;
}

int Fund::getFundBalance() const
{
	return fundBalance;
}

vector<string> Fund::getTransactionHistory()
{
	return transactionHistory;
}



void Fund::setFundName(string fundName) 
{
	this->fundName = fundName;
}

void Fund::setFundBalance(int fundBalance) 
{
	this->fundBalance = fundBalance;
}

void Fund::addToFund(int amountToAdd)
{
	fundBalance += amountToAdd;
}

void Fund::subtractFromFund(int amountToSubtract)
{
	if (fundBalance >= amountToSubtract)
	{
		fundBalance -= amountToSubtract;
	}
	else
	{
		cerr << "ERROR: Not enough funds to withdraw $" << amountToSubtract << " from this account." << endl;
	}
}

bool Fund::addToTransactionHistory(string transaction)
{
	transactionHistory.push_back(transaction);
	return true;
}

int Fund::sizeOfTransactionHistory() const
{
	return transactionHistory.size();
}

void Fund::displayTransactionHistory()
{
	{

		for (int i = 0; i < transactionHistory.size(); i++)
		{
			cout << transactionHistory[i] << endl;
		}
	}
}
