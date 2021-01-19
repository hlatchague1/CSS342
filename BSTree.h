#ifndef BSTree_H
#define BSTree_H


#include <stdio.h>
#include "Account.h"


class BSTree
{
private:
	struct Node
	{
		Account* pAcct;
		Node* right;
		Node* left;
	};
	Node* root;

public:
	BSTree();
	~BSTree();
	bool Insert(Account* accountToInsert);
	void InsertHelper(Node* current, Account* accountToInsert);
	bool Retrieve(int targetID, Account*& accountToRetrieve) const;
	Account* RetrieveHelper(Node* current, int targetID) const;
	void Display() const;
	void DisplayHelper(Node* current) const;
	void Empty();
	void EmptyHelper(Node* current);
	bool isEmpty() const;
};
#endif
