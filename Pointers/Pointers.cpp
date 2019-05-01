// Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string reverse(string str);
string recursiveReverse(string& str, char* first, char* last);

int main()
{
	int* pointer;
	int x = 6;
	pointer = &x;
	

	cout << "pointer (address of x) = " << pointer << endl;
	cout << "x (value of x) = " << x << endl;
	cout << "&x (address of x) = " << &x << endl;

	cout << "*pointer (value of x) = " << *pointer << endl;

	string str = "cat";

	int start = 0;
	int length = str.length();
	char temp;
	char* first = &str[start];
	char* last = &str[length - 1];

	cout << "recursiveReverse(str, first, last) = " << recursiveReverse(str, first, last) << endl;



	
	string str2 = "no matter what";
	cout << "String: " << str << endl;
	cout << "Reverse(\"hello\"): " <<  reverse(str) << endl;
	cout << "String: " << str2 << endl;
	cout << "Reverse(\"no matter what\"): " << reverse(str2) << endl;


}

string reverse(string str)
{
	int start = 0;
	int length = str.length();
	char temp;
	char* first = &str[start];
	char* last = &str[length - 1];

	for (int i = 0; i < length/2; i++)
	{
		temp = *first;
		*first = *last;
		*last = temp;
		*(++first);
		*(--last);
	}
	return str;
}

string recursiveReverse(string& str, char* first, char* last)
{
	char temp;

	if (first == last)
	{
		return str;
	}
	else
	{
		temp = *first;
		*first = *last;
		*last = temp;
		return recursiveReverse(str, ++first, --last);
	}
}