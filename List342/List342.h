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
	// overloads "cout" operator
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
				output << *traversingNode->data;
				traversingNode = traversingNode->next;
			}
		}
		return output;
	}

public:
	// constructors
	List342();
	List342(string fileName);
	List342(const List342& rhs); //copy constructor

	// destructor
	~List342() { this->DeleteList(); }
	
	// actions
	bool BuildList(string fileName);
	bool Insert(ItemType* obj);
	bool Remove(ItemType target, ItemType& result);
	bool Peek(ItemType target, ItemType& result) const;
	bool isEmpty() const;

	void DeleteList();
	bool Merge(List342& list1);

	// overloaded operators
	List342 operator+(const List342& rhs);
	List342 operator+=(const List342& rhs);
	bool operator==(const List342& rhs);
	bool operator!=(const List342& rhs);
	void operator=(const List342& rhs);

private:
	struct Node
	{
		ItemType* data = nullptr;
		Node* next = nullptr;
	};
	Node* headPtr = nullptr;
};

// constructor
template <class ItemType>
List342<ItemType>::List342()
{
	headPtr = nullptr;

}

// constructor
template <class ItemType>
List342<ItemType>::List342(string fileName)
{
	BuildList(fileName);
}

// copy constructor
template<class ItemType>
List342<ItemType>::List342(const List342<ItemType>& otherList)
{
	this->headPtr = nullptr;
	*this = otherList;
}

// builds list from file of string
template <class ItemType>
bool List342<ItemType>::BuildList(string fileName)
{
	ifstream inFile;

	inFile.open(fileName);
	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			ItemType* data = new ItemType();
			inFile >> (*data);
			Insert(data);
			delete data;
		}
		inFile.close();
	}
	else
	{
		cout << "File: " << fileName << " not found." << endl;
	}
	return true;
}

// inserts item in increasing order
template <class ItemType>
bool List342<ItemType>::Insert(ItemType* obj)
{
	Node* temp = new Node();
	Node* current;
	Node* previous;

	temp->data = new ItemType(*obj);

	if (temp == nullptr)
	{	
		return false;
	}
	if (!headPtr)
	{
		headPtr = temp;			
		return true;
	}

	if (*temp->data < *headPtr->data)
	{
		temp->next = headPtr;
		headPtr = temp;
		return true;
	}

	current = headPtr->next;		
	previous = headPtr;
	   
	while (current)
	{		
		if (*temp->data < *current->data)
		{
			temp->next = current;				
			previous->next = temp;
			return true;
		}
		else if (*temp->data == *current->data)
		{
			temp = nullptr;
			delete temp;
			return false;
		}
		previous = current;			
		current = current->next;
	}

	if (previous)
	{
		previous->next = temp;
		return true;
	}
	return false;
}

// Remove the target item from the list. 
// Return the item using a second parameter that is passed in by reference.
template <class ItemType>
bool List342<ItemType>::Remove(ItemType target, ItemType& result)
{
	Node* current;
	Node* previous;

	if (!headPtr)
	{
		return false;
	}

	if (target == *headPtr->data)
	{
		result = target;
		current = headPtr;
		headPtr = headPtr->next;
		delete current;
		return true;
	}

	previous = headPtr;
	current = headPtr->next;
	while (current)
	{
		if (target == *current->data)

		{
			result = target;
			previous->next = current->next;
			return true;
		}
		previous = current;
		current = current->next;
	}
	return false;
}

// Same as remove except item is not removed from the list
template <class ItemType>
bool List342<ItemType>::Peek(ItemType target, ItemType& result) const
{
	Node* current = headPtr;

	if (!current)
	{
		return true;
	}

	while (current)
	{
		if (target == *current->data)
		{
			result = *current->data;
			return true;
		}
		current = current->next;
	}
	return false;
}

// checks if list is empty
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

// Remove all items from the list
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

//  Takes a sorted list and merges into the calling sorted list 
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
			this->Insert(otherCurrent->data);
			thisCurrent = thisCurrent->next;
			otherCurrent = otherCurrent->next;
		}
		list1.DeleteList();
		return true;
	}
}

// overloads + operator
template <class ItemType>
List342<ItemType> List342<ItemType>::operator+(const List342& rhs)
{
	List342<ItemType> list;
	Node* temp;

	while (temp)
	{
		list.Insert(temp->data);
		temp = temp.next;
	}
	temp = rhs.headPtr;

	while (temp)
	{
		list.Insert(temp->data);
		temp = temp.next;
	}
	temp = nullptr;

	return list;
}

// overloads += operator
template <class ItemType>
List342<ItemType> List342<ItemType>::operator+=(const List342& rhs)
{
	if (rhs.headPtr == nullptr)
	{
		return *this;
	}
	Node* current = rhs.headPtr;
	while (current != nullptr)
	{
		Insert(current->data);
		current = current->next;
	}
	current = nullptr;
	return *this;
}

// checks for equality between two lists (true/false)
template <class ItemType>
bool List342<ItemType>::operator==(const List342& rhs)
{

	Node* current = headPtr;
	Node* rhsCurrent = rhs.headPtr;

	while (current && rhsCurrent)
	{
		if (current->data != rhsCurrent->data)
		{
			return false;
		}
		current = current->next;
		rhsCurrent = rhsCurrent->next;
	}
	return true;
}

// checks for inequality between two lists (true/false)
template <class ItemType>
bool List342<ItemType>::operator!=(const List342& rhs)
{
	Node* current = headPtr;
	Node* rhsCurrent = rhs.headPtr;

	while (current && rhsCurrent)
	{
		if (current->data == rhsCurrent->data)
		{
			return false;
		}
		current = current->next;
		rhsCurrent = rhsCurrent->next;
	}
	return true;

}

// Makes a deep copy of all new memory
template <class ItemType>
void List342<ItemType>::operator=(const List342& rhs)
{
	Node* rhsCurrent;
	Node* temp;

	if (this == &rhs)
	{
		return;
	}
	this->DeleteList();
	rhsCurrent = rhs.headPtr;
	this->headPtr = rhsCurrent;
	temp = this->headPtr->next;
	rhsCurrent = rhsCurrent->next;
	while (rhsCurrent)
	{
		temp = rhsCurrent;
		rhsCurrent = rhsCurrent->next;
	}
	return;
}
//

#endif // !LIST342_H
