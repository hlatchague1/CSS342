#pragma once

#ifndef CHILD_H
#define CHILD_H

#include <string>
#include <iostream>

using namespace std;

class Child
{
public:
	// constructors
	Child() : firstName("Unknown"), lastName("Unknown"), age(0) {}
	Child(string firstName, string lastName, int age);
	
	// destructor
	~Child();

	// getters
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;

	// setter
	bool setChild(string firstName, string lastName, int age);

	// overloaded operators
	bool operator == (const Child& rhs) const;
	bool operator != (const Child& rhs) const;
	bool operator < (const Child& rhs) const;
	bool operator > (const Child& rhs) const;
	bool operator>=(const Child& rhs)const;
	bool operator<=(const Child& rhs)const;


	// friend overloaded operators (cin/cout)
	friend istream& operator>> (istream& input, const Child& childInput);
	friend ostream& operator<< (ostream& output, const Child& childOutput);

private:
	// private member variables
	string firstName = "";
	string lastName = "";
	int age = 0;
};

#endif // !CHILD_H