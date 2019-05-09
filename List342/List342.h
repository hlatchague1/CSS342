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

public:
	List342<ItemType>();
	//List342(string fileName);
	List342<ItemType>(const List342& rhs);
	~List342<ItemType>();

	bool BuildList(string fileName);
	bool Insert(ItemType* obj);
	//bool Remove(ItemType target, ItemType& result);
	//bool Peek(ItemType target, ItemType& result) const;
	bool isEmpty() const;

	//void DeleteList();
	//bool Merge(List342& list1);

	//List342 operator+(const List342& rhs);
	//List342 operator+=(const List342& rhs);
	//bool operator==(const List342& rhs);
	//bool operator!=(const List342& rhs);
	//List342 operator=(const List342& rhs);

	friend ostream operator << (ostream& output, const List342<ItemType>& outputList);

private:
	template <class ItemType>
	struct Node
	{
		ItemType* data = nullptr;
		Node<ItemType>* next = nullptr;
	};
	Node<ItemType>* headPtr;
	int itemCount = 0;
};


#endif // !LIST342_H
