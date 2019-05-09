#include "Child.h"
#include "List342.h"


int main()
{
	string first, last;
	int age;

	Child c1("Mark", "Irvine", 50), c2("Mark", "Irvine", 49), c3("Nathalie", "Irvine", 50);
	Child c4("Mark", "Irvine", 50), c6;

	cout << "ENTER INFO: " << endl;
	cin >> first >> last >> age;

	Child c5(first, last, age);

	cout << "1 = true; 0 = false" << endl;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	cout << "c3 = " << c3 << endl;
	cout << "c4 = " << c4 << endl;
	cout << "c5 = " << c5 << endl;
	cout << "c6 = " << c6 << endl;
	cout << "c1 == c2 ? " << (c1 == c2) << endl;
	cout << "c1 == c4? " << (c1 == c4) << endl;
	cout << "c1 != c3 ? " << (c1 != c3) << endl;
	cout << "c1 < c2 = " << (c1 < c2) << "//false" << endl;
	cout << "c1 > c2 = " << (c1 > c2) << "//true" << endl;
	cout << "c2 < c3 = " << (c2 < c3) << endl;
	cout << "c2 > c3 = " << (c2 > c3) << endl;
	cout << "c4 > c5 = " << (c4 > c5) << endl;
	cout << "c4 < c5 = " << (c4 < c5) << endl;

	List342<Child> list1;
	list1.Insert(&c1);
	list1.Insert(&c2);

	cout << list1;



	
}