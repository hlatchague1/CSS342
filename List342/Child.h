#ifndef CHILD_H
#define CHILD_H

#include <string>
#include <iostream>

using namespace std;

class Child
{

public:
	// constructors
	Child(string firstName, string lastName, int age);
	Child() : firstName("Unknown"), lastName("Unknown"), age(0) {}
	
	// destructor
	~Child() = default;

	// setter
	bool setChild(string first, string last, int age);
	   
	// getters
	string getFirstName() const;
	string getLastName() const;
	int getAge() const;

	// overloaded operators
	bool operator == (const Child& rhs) const;
	bool operator != (const Child& rhs) const;
	bool operator < (const Child& rhs) const;
	bool operator > (const Child& rhs) const;
	bool operator>=(const Child& rhs)const;
	bool operator<=(const Child& rhs)const;

	friend istream& operator>>(istream& input, Child& childInput);
	friend ostream& operator<<(ostream& output, const Child& childOutput);

private:
	// private member variables
	string firstName = "";
	string lastName = "";
	int age = 0;
};

#endif // !CHILD_H