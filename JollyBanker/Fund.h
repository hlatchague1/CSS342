#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#ifndef FUND_H
#define FUND_H

using namespace std;

class Fund
{	
	friend ostream& operator<< (ostream& os, const Fund& fund)
	{
		os << fund.getFundName() << ": $" << fund.getFundBalance() << endl;
		return os;
	}

public:
	Fund();
	Fund(string fundName);
	~Fund();

	string getFundName() const;
	int getFundBalance() const;
	vector<string> getTransactionHistory();
	
	void setFundName(string fundName);
	void setFundBalance(int balance);

	void addToFund(int amountToAdd);
	void subtractFromFund(int amountToSubtract);
	bool addToTransactionHistory(string transaction);
	int sizeOfTransactionHistory() const;
	void displayTransactionHistory();

private:
	string fundName;
	int fundBalance = 0;
	vector<string> transactionHistory;
};

#endif // !FUND_H