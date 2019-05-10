#pragma once

#ifndef LIST342_H
#define LIST342_H

#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

using namespace std;

template <class ItemType>
class List342
{

	friend ostream& operator<< (ostream& output, const List342<ItemType>& outputList)
	{
		Node* traversingNode = outputList.headPtr;

		if (outputList.isEmpty())
		{
			output << "List is empty!" << endl;
		}
		else
		{
			while (traversingNode) // traversingNode != nullptr (same thing)
			{
				output << *(traversingNode->data);
				traversingNode = traversingNode->next;
			}
		}
		return output;
	}

public:
	List342();
	List342(string fileName);
	List342(const List342& rhs); //copy constructor
	~List342();

	int getItemCount();
		
	bool BuildList(string fileName);
	bool Insert(ItemType* obj);
	//bool Remove(ItemType target, ItemType& result);
	//bool Peek(ItemType target, ItemType& result) const;
	bool isEmpty() const;

	void DeleteList();
	bool Merge(List342& list1);

	//List342 operator+(const List342& rhs);
	//List342 operator+=(const List342& rhs);
	bool operator==(const List342& rhs);
	bool operator!=(const List342& rhs);
	//List342 operator=(const List342& rhs);

private:
	struct Node
	{
		ItemType* data = nullptr;
		Node* next = nullptr;
	};
	Node* headPtr = nullptr;
	int itemCount = 0;
};

template <class ItemType>
List342<ItemType>::List342()
{
	headPtr = nullptr;
	itemCount = 0;

}

template <class ItemType>
List342<ItemType>::List342(string fileName)
{
	BuildList(fileName);
}

template<class ItemType>
List342<ItemType>::List342(const List342<ItemType>& otherList)
{
	this->headPtr = nullptr;
	*this = otherList;
}

template <class ItemType>
List342<ItemType>::~List342()
{
	this->DeleteList();

}

template <class ItemType>
int List342<ItemType>::getItemCount()
{
	return itemCount;
}

template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);
	while (!inFile.eof())
	{
		string* temp = this->next; // maybe itemtype
		inFile >> *temp;
		Insert(temp);
		return true;
	}
	return false;
}

template <class ItemType>
bool List342<ItemType>::Insert(ItemType* obj)
{
	//Node* newNode = new Node;
	//newNode->data = obj;
	//ItemType* temp;
	//if (headPtr == nullptr)
	//{
	//	headPtr = newNode;
	//	newNode.next = nullptr;
	//	return true;
	//}
	////if (*hearPtr == *newNode.data)
	////{
	////	return false;
	////}
	//else if (headPtr->data > newNode->data)
	//{
	//	newNode.next = headPtr;
	//	headPtr = newNode;
	//	return true;
	//}
	//else
	//{
	//	Node* traversingNode = headPtr;
	//	while ((traversingNode.next != nullptr) && (newNode->data < traversingNode->data))
	//	{
	//		traversingNode = traversingNode.next;
	//	}
	//	temp = traversingNode.data;
	//	traversingNode.next = newNode.data;
	//	newNode.next = *temp;
	//	return true;
	//}
	//return false;


	if (obj == nullptr || ((headPtr != nullptr) && (*obj == *headPtr->data)))
	{
		return false;
	}

	Node* temp = new Node;
	temp->next = nullptr;
	temp->data = new ItemType(*obj);

	if (headPtr == nullptr || *temp->data < *headPtr->data)
	{
		temp->next = headPtr;
		headPtr = temp;
		temp = nullptr;
		return true;
	}

	Node* current = headPtr->next;
	Node* previous = headPtr;

	while (current != nullptr && *current->data <= *temp->data)
	{
		previous = current;
		current = current->next;
	}

	if (*previous->data == *temp->data)
	{
		temp = nullptr;
		delete temp;
		return false;

	}

	temp->next = current;
	previous->next = temp;
	temp = nullptr;
	current = nullptr;
	previous = nullptr;
	return true;
}

//template <class ItemType>
//bool List342<ItemType>::Remove(ItemType target, ItemType& result)
//{
//
//}
//
//template <class ItemType>
//bool List342<ItemType>::Peek(ItemType target, ItemType& result) const
//{
//
//}
//

template <class ItemType>
bool List342<ItemType>::isEmpty() const
{
	if (headPtr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class ItemType>
void List342<ItemType>::DeleteList()
{
	Node* current = headPtr;
	Node* next;
	while (current)
	{
		next = current->next;
		current = nullptr;
		current = next;
	}
	headPtr = nullptr;
}

template <class ItemType>
bool List342<ItemType>::Merge(List342& list1)
{
	Node* thisCurrent = headPtr;
	Node* otherCurrent = list1.headPtr;

	if ((thisCurrent == nullptr && otherCurrent == nullptr) || (*this == list1))
	{
		return false;
	}
	else
	{
		while (thisCurrent && otherCurrent)
		{
			thisCurrent = thisCurrent->next;
			Insert((*otherCurrent).data);
			otherCurrent = otherCurrent->next;
		}
		list1.DeleteList();
		return true;
	}
}

//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator+(const List342& rhs)
//{
//
//}
//
//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator+=(const List342& rhs)
//{
//
//}

template <class ItemType>
bool List342<ItemType>::operator==(const List342& rhs)
{

	Node* current = headPtr;
	Node* rhsNode = rhs.headPtr;

	while (current != nullptr && rhsNode != nullptr)
	{
		if (current->data != rhsNode->data)
		{
			return false;
		}
		current = current->next;
		rhsNode = rhsNode->next;
	}
	return true;
}


template <class ItemType>
bool List342<ItemType>::operator!=(const List342& rhs)
{
	Node* current = headPtr;
	Node* rhsNode = rhs.headPtr;

	while (current != nullptr && rhsNode != nullptr)
	{
		if (current->data == rhsNode->data)
		{
			return false;
		}
		current = current->next;
		rhsNode = rhsNode->next;
	}
	return true;

}
//
//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator=(const List342& rhs)
//{
//
//}
//

//template <class ItemType>
//ostream& operator<<(ostream& output, const List342<ItemType>& outputList)
//{
//	List342<ItemType>::Node* traversingNode;
//	traversingNode = outputList.headPtr;
//
//	if (outputList.isEmpty())
//	{
//		output << "List is empty!" << endl;
//	}
//	else
//	{
//		while (traversingNode) // traversingNode != nullptr (same thing)
//		{
//			output << *(traversingNode->data);
//			traversingNode = traversingNode.next;
//		}
//	}
//	return output;
//}


#endif // !LIST342_H
