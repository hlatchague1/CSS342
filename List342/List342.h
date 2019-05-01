#pragma once

#ifndef LIST342_H
#define LIST342_H

#include <iostream>
#include <ostream>
#include <string>

using namespace std;


template <class ItemType>
class List342
{
public:
	List342<ItemType>();
	~List342();

	bool BuildList(string fileName);
	bool Insert(ItemType* obj);
	bool Remove(ItemType target, ItemType& result);
	bool Peek(ItemType target, ItemType& result) const;
	bool isEmpty() const;

	void DeleteList();
	bool Merge(List342& list1);

	List342 operator+(const List342& rhs);
	List342 operator+=(const List342& rhs);
	bool operator==(const List342& rhs);
	bool operator!=(const List342& rhs);
	List342 operator=(const List342& rhs);

	friend ostream operator << (ostream& output, const List342& outputList);



private:
	Node* headPtr;
	int itemCount;
};

#endif // !LIST342_H
