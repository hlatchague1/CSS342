#include "List342.h"
#include "Child.h"


template <class ItemType>
List342<ItemType>::List342()
{
	this->headPtr = nullptr;
}

template<class ItemType>
List342<ItemType>::List342(const List342& otherList)
{
	this->headPtr = nullptr;
	*this = otherList;
}

template <class ItemType>
List342<ItemType>::~List342()
{
}

template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
		ifstream inFile;
		inFile.open(fileName);
		while (!inFile.eof())
		{
			ItemType* temp;
			inFile >> *temp;
			Insert(temp);
		}
		return false;
}

template <class ItemType>
bool List342<ItemType>::Insert(ItemType* obj)
{
	Node* newNode = new Node;
	newNode.data = *obj;
	ItemType* temp;
	if (headPtr == nullptr)
	{
		headPtr = newNode.data;
		newNode.next = nullptr;
		return true;
	}
	//if (*hearPtr == *newNode.data)
	//{
	//	return false;
	//}
	if (*headPtr < *newNode.data)
	{
		temp = headPtr->data;
		headPtr = newNode.data;
		newNode.next = *temp;
	}
	else
	{
		Node* traversingNode = headPtr;
		while ((traversingNode.next != nullptr) && (*newNode.data < *traversingNode.data))
		{
			traversingNode = traversingNode.next;
		}
		temp = traversingNode.data;
		traversingNode.next = newNode.data;
		newNode.next = *temp;
		return true;
	}
	return false;
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

//template <class ItemType>
//void List342<ItemType>::DeleteList()
//{
//
//}
//
//template <class ItemType>
//bool List342<ItemType>::Merge(List342& list1)
//{
//
//}
//
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
//
//template <class ItemType>
//bool List342<ItemType>::operator==(const List342& rhs)
//{
//
//}
//
//
//template <class ItemType>
//bool List342<ItemType>::operator!=(const List342& rhs)
//{
//
//}
//
//template <class ItemType>
//List342<ItemType> List342<ItemType>::operator=(const List342& rhs)
//{
//
//}
//
template <class ItemType>
ostream operator<<(ostream& output, const List342<ItemType>& outputList)
{
	Node* traversingNode = new Node;
	traversingNode = outputList.headPtr;

	if (outputList.isEmpty())
	{
		output << "List is empty!" << endl;
	}
	else
	{
		while (traversingNode != nullptr)
		{
			output << *(traversingNode->data) << endl;
			traversingNode = traversingNode.next;
		}
	}
	return output;
}
