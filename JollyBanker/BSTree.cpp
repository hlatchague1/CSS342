#include "BSTree.h"
#include <iostream>

using namespace std;

BSTree::BSTree()
{
	root = nullptr;
}
BSTree::~BSTree()
{
	Empty();
}

bool BSTree::Insert(Account* accountToInsert)
{
	Node* newNode = new Node;
	newNode->pAcct = accountToInsert;
	newNode->left = nullptr;
	newNode->right = nullptr;
	if (!root)
	{
		root = newNode;
		return true;
	}
	InsertHelper(root, accountToInsert);
	return true;
}

void BSTree::InsertHelper(Node* current, Account* accountToInsert)
{
	Node* newNode = new Node;
	newNode->left = nullptr;
	newNode->right = nullptr;
	newNode->pAcct = accountToInsert;
	if (current == NULL)
	{
		current = newNode;
		return;
	}
	else if (accountToInsert->getAccountID() < current->pAcct->getAccountID())
	{
		if (!current->left)
		{
			current->left = newNode;
		}
		else
		{
			InsertHelper(current->left, accountToInsert);
		}
	}
	else
	{
		if (!current->right)
		{
			current->right = newNode;
		}
		else
		{
			InsertHelper(current->right, accountToInsert);
		}
	}
}

bool BSTree::Retrieve(int targetID, Account*& accountToRetrieve) const
{
	accountToRetrieve = RetrieveHelper(root, targetID);
	return accountToRetrieve != nullptr;
}

Account* BSTree::RetrieveHelper(Node* current, int targetID) const
{
	if (!current)
	{
		return nullptr;

	}
	else if (current->pAcct->getAccountID() == targetID)
	{
		return current->pAcct;

	}
	else if (targetID < current->pAcct->getAccountID())
	{
		return RetrieveHelper(current->left, targetID);
	}
	else
	{
		return RetrieveHelper(current->right, targetID);
	}
}



void BSTree::Display() const
{
	DisplayHelper(root);
}

void BSTree::DisplayHelper(Node* current) const
{
	if (!current)
	{
		return;
	}
	DisplayHelper(current->left);
	cout << *current->pAcct << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << current->pAcct->getFundByCorrespondingID(i);
	}
	cout << endl;
	DisplayHelper(current->right);
}

void BSTree::Empty()
{
	EmptyHelper(root);
}

void BSTree::EmptyHelper(Node* current)
{
	if (!current)
	{
		return;
	}
	else if (current->left)
	{
		EmptyHelper(current->left);
	}
	else if (current->right)
	{
		EmptyHelper(current->right);
	}
	else if (current)
	{
		delete current->pAcct;
		delete current;
		current = nullptr;
	}
}

bool BSTree::isEmpty() const
{
	return root == NULL;
}

