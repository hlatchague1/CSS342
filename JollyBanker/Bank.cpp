#include "Bank.h"
#include <string>
#include <fstream>
#include <sstream> 
#include <iostream>
#include <string>

using namespace std;

Bank::Bank()
{
}

Bank::~Bank()
{
}

bool Bank::CreateTransaction(string fileName)
{
	ifstream inputFile;
	inputFile.open(fileName);
	string transactionString;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			while (getline(inputFile, transactionString))
			{
				transactionQueue.push(transactionString);
			}
		}
		inputFile.close();
		return true;
	}
	else
	{
		cerr << "ERROR: " << fileName << " failed to open. " << endl;
		return false;
	}
}


void Bank::FulfillTransaction()
{
	while (!transactionQueue.empty())
	{
		string transactionLine = transactionQueue.front();
		string command = transactionLine.substr(0, 1);
		string stringWithoutCommand = transactionLine.substr(2, transactionLine.length());

		if (command == "O")
		{
			string strLastName = transactionLine.substr(2, transactionLine.length());
			string lastName = strLastName.substr(0, strLastName.find(" "));
			string strFirstName = strLastName.substr(strLastName.find(" ") + 1, strLastName.length());
			string firstName = strFirstName.substr(0, strFirstName.find(" "));
			string accountNum = strFirstName.substr(strFirstName.find(" ") + 1, strFirstName.length());
			int accountID = atoi(accountNum.c_str());

			OpenAccount(firstName, lastName, accountID);
		}

		else if (command == "D")
		{
			string strAccountID = transactionLine.substr(2, 4);
			string strFundID = transactionLine.substr(6, 1);
			string strAmount = transactionLine.substr(8);
			int accountID = atoi(strAccountID.c_str());
			int fundID = atoi(strFundID.c_str());
			int amount = atoi(strAmount.c_str());

			Deposit(accountID, fundID, amount, transactionLine);
		}

		else if (command == "W")
		{
			string strAccountID = transactionLine.substr(2, 4);
			string strFundID = transactionLine.substr(6, 1);
			string strAmount = transactionLine.substr(8);
			int accountID = atoi(strAccountID.c_str());
			int fundID = atoi(strFundID.c_str());
			int amount = atoi(strAmount.c_str());

			Withdraw(accountID, fundID, amount, transactionLine);

		}
		else if (command == "T")
		{
			string strGivingAccountID = transactionLine.substr(2, 4);
			string strGivingFundID = transactionLine.substr(6, 1);
			string strReceivingAccountID = transactionLine.substr(8);

			string stringWithoutCommand = transactionLine.substr(transactionLine.find(" ") + 1, transactionLine.length());
			string strAmount = stringWithoutCommand.substr(stringWithoutCommand.find(" ") + 1, stringWithoutCommand.length());
			string strFinalAmount = strAmount.substr(0, strAmount.find(" "));

			string theTransferID = strAmount.substr(strAmount.find(" ") + 1, 4);
			string thefundID = strAmount.substr(strAmount.length() - 1, 1);
			int ID = atoi(strGivingAccountID.c_str());
			int fundID = atoi(strGivingFundID.c_str());
			int amount = atoi(strFinalAmount.c_str());
			

			int transferID = atoi(theTransferID.c_str());
			int transferFund = atoi(thefundID.c_str());

			Transfer(ID, fundID, amount, transferID, transferFund);
		}

		else if (command == "H")
		{
			string strAccountandFundID = transactionLine.substr(2);
			if (strAccountandFundID.length() > 4)
			{

				string strFundID = strAccountandFundID.substr(4);
				string strAccountID = strAccountandFundID.substr(0, 4);
				int accountID = atoi(strAccountID.c_str());
				int fundID = atoi(strFundID.c_str());

				DisplayTransactionHistory(accountID, fundID);
			}
			else
			{
				int accountID = atoi(strAccountandFundID.c_str());
				DisplayTransactionHistory(accountID);
			}
		}
		transactionQueue.pop();
	}
}


bool Bank::OpenAccount(string firstName, string lastName, int accountID)
{
	Account* newAccount;

	if (treeOfAccounts.Retrieve(accountID, newAccount))	//See if account exists
	{
		cerr << "ERROR: Account " << accountID << " is already open. Transaction refused." << endl;
		return false;
	}
	else
	{
		newAccount = new Account;
		newAccount->setFirstName(firstName);
		newAccount->setLastName(lastName);
		newAccount->setAccountID(accountID);
		treeOfAccounts.Insert(newAccount);
		return true;
	}
}

bool Bank::Deposit(int accountID, int accountFundNumber, int amount, string transactionLine)
{

	Account* thisAccount;

	if (treeOfAccounts.Retrieve(accountID, thisAccount))
	{
		thisAccount->addToFundAccount(amount, accountFundNumber);
		thisAccount->writeToFund(accountFundNumber, transactionLine);
		return true;
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " does not exist. Transaction Failed." << endl;
		return false;
	}
}

bool Bank::Deposit(int accountID, int accountFundNumber, int amount)
{

	Account* thisAccount;

	if (treeOfAccounts.Retrieve(accountID, thisAccount))
	{
		thisAccount->addToFundAccount(amount, accountFundNumber);
		return true;
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " does not exist. Transaction Failed." << endl;
		return false;
	}
}

bool Bank::Withdraw(int accountID, int accountFundNumber, int amount, string transactionLine)
{
	Account* thisAccount;
	if (treeOfAccounts.Retrieve(accountID, thisAccount))
	{
		thisAccount->removeFromFundAccount(amount, accountFundNumber);
		thisAccount->writeToFund(accountFundNumber, transactionLine);
		return true;
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " not found. Withdrawal refused. " << endl;
		return false;
	}

}

bool Bank::Withdraw(int accountID, int accountFundNumber, int amount)
{	

	Account* thisAccount;
	if (treeOfAccounts.Retrieve(accountID, thisAccount))
	{
		thisAccount->removeFromFundAccount(amount, accountFundNumber);
		return true;
	}
	else
	{
		cerr << "ERROR: Account " << accountID << " not found. Withdrawal refused. " << endl;
		return false;
	}
}

bool Bank::Transfer(int givingAccountID, int givingAccountFundNumber, int amount, int receivingAccountID, int receivingAccountFundNumber)
{
	Account* givingAccount;
	Account* receivingAccount;
	if (!treeOfAccounts.Retrieve(givingAccountID, givingAccount))
	{
		cerr << "ERROR: Account " << givingAccountID << " not found. Transferal refused." << endl;
		return false;
	}
	else if (!treeOfAccounts.Retrieve(receivingAccountID, receivingAccount))
	{
		cerr << "ERROR: Account " << receivingAccountID << " not found. Transferal refused." << endl;
		return false;
	}
	else
	{
		Withdraw(givingAccountID, givingAccountFundNumber, amount);
		Deposit(receivingAccountID, receivingAccountFundNumber, amount);
		return true;
	}
}

void Bank::Display()
{
	cout << endl;
	cout << "Processing done. Final balances" << endl;
	treeOfAccounts.Display();
}

void Bank::DisplayTransactionHistory(int accountID, int fundNumber)
{
	Account* temp;
	
	treeOfAccounts.Retrieve(accountID, temp);
	cout << "Transaction History for " << temp->getFirstName() << " " << temp->getLastName() << " " << temp->getFundByCorrespondingID(fundNumber) << endl;
	temp->displayFundHistory(fundNumber);
}

void Bank::DisplayTransactionHistory(int accountID)
{
	Account* temp;

	treeOfAccounts.Retrieve(accountID, temp);
	cout << "Transaction History for " << temp->getFirstName() + " " + temp->getLastName() << " by fund." << endl;

	for (int i = 0; i < MAX_NUM_FUNDS; i++)
	{
		temp->displayFundHistory(i);
	}
	cout << endl;
}
