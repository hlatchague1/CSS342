#include "Child.h"

using namespace std;

Child::Child(string first, string last, int age)
{
	setChild(first, last, age);
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

bool Child::operator>=(const Child& rhs)const
{
	if (this->firstName == rhs.lastName && firstName == this->firstName && age == this->age)
	{
		return true;
	}
	else if (*this > rhs)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Child::operator<=(const Child& rhs)const
{
	if (this->firstName == rhs.lastName && firstName == this->firstName && age == this->age)
	{
		return true;
	}
	else if (*this < rhs)
	{
		return true;
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

istream& operator>>(istream& input, Child& childInput)
{
	string first, last;
	int age;
	input >> first >> last >> age;
	childInput.setChild(first, last, age);
	return input;
}