#pragma once

#ifndef NODE_H
#define NODE_H

template <class ItemType>
class Node
{
public:
	Node<ItemType>();
	Node<ItemType>(const ItemType& item);
	Node<ItemType>(const ItemType& item, Node<ItemType>* nextNodePtr);

	~Node();

	ItemType getItem() const;
	Node<ItemType>* getNext() const;

	void setItem(const ItemType& item);
	void setNext(Node<ItemType>* nextNodePtr);

private:
	ItemType item;
	Node <ItemType>* next;
};

#endif // !NODE_H