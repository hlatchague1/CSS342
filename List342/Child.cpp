#include "Child.h"


Child::Child(string first, string last, int age)
{
	setChild(first, last, age);
}

Child::~Child()
{
}

string Child::getFirstName() const
{
	return firstName;
}

string Child::getLastName() const
{
	return lastName;
}

int Child::getAge() const
{
	return age;
}

bool Child::setChild(string first, string last, int age)
{
	firstName = first;
	lastName = last;
	this->age = age;

	return true;
}

bool Child::operator==(const Child& rhs) const
{
	if (this->lastName == rhs.lastName && this->firstName == rhs.firstName
		&& this->age == rhs.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Child::operator!=(const Child& rhs) const
{
	if (this->lastName != rhs.lastName || this->firstName != rhs.firstName
		|| this->age != rhs.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Child::operator<(const Child& rhs) const
{
	if (this->lastName < rhs.lastName)
	{
		return true;
	}
	else if (this->lastName == rhs.lastName)
	{
		if (this->firstName < rhs.firstName)
		{
			return true;
		}
		else
		{
			if (this->age < rhs.age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (this->firstName == rhs.firstName)
		{
			if (this->age < rhs.age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

bool Child::operator>(const Child& rhs) const
{
	if (this->lastName > rhs.lastName)
	{
		return true;
	}
	else if (this->lastName == rhs.lastName)
	{
		if (this->firstName > rhs.firstName)
		{
			return true;
		}
		else
		{
			if (this->age > rhs.age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (this->firstName == rhs.firstName)
		{
			if (this->age > rhs.age)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& output, const Child& childOutput)
{
	output << childOutput.getFirstName() << childOutput.getLastName() << childOutput.getAge();
	return output;
}

istream& operator>>(istream& input, const Child& childInput)
{
	string first = childInput.getFirstName(); 
	string last = childInput.getLastName();
	int age = childInput.getAge();

	input >> first, last, age;
	return input;
}