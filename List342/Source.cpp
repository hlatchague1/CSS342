#include "Child.h"
#include "List342.h"


int main()
{
//	//string first, last;
//	//int age;
//
//	Child c1("Mark", "Irvine", 50), c2("Mark", "Irvine", 49);/*, c3("Nathalie", "Irvine", 50);
//	Child c4("Mark", "Irvine", 50), c6;
//*/
//	//cout << "ENTER INFO: " << endl;
//	//cin >> first >> last >> age;
//
//	//Child c5(first, last, age);
//
//	//cout << "1 = true; 0 = false" << endl;
//	//cout << "c1 = " << c1 << endl;
//	//cout << "c2 = " << c2 << endl;
//	//cout << "c3 = " << c3 << endl;
//	//cout << "c4 = " << c4 << endl;
//	//cout << "c5 = " << c5 << endl;
//	//cout << "c6 = " << c6 << endl;
//	//cout << "c1 == c2 ? " << (c1 == c2) << endl;
//	//cout << "c1 == c4? " << (c1 == c4) << endl;
//	//cout << "c1 != c3 ? " << (c1 != c3) << endl;
//	//cout << "c1 < c2 = " << (c1 < c2) << "//false" << endl;
//	//cout << "c1 > c2 = " << (c1 > c2) << "//true" << endl;
//	//cout << "c2 < c3 = " << (c2 < c3) << endl;
//	//cout << "c2 > c3 = " << (c2 > c3) << endl;
//	//cout << "c4 > c5 = " << (c4 > c5) << endl;
//	//cout << "c4 < c5 = " << (c4 < c5) << endl;
//	/*cout << (c1 >= c2) << endl;
//	cout << (c2 >= c1) << endl;*/
//
//
//	List342<Child> list1;
//	list1.Insert(&c1);
//	list1.Insert(&c2);
//
//	//cout << list1;
//	//int y = 40;
//	//int* x = &y;
//	//List342<int> number;
//
//	//number.Insert(&y);
//
//	//
//
//	//cout << number;
//
//	List342<Child> class1;
//	class1.Insert(&c1);
//	class1.Insert(&c2);
//	class1.Insert(&c1);
//
//	cout << class1;

	Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6); 
	Child c5("Piqi", "Tangi", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7); 
	Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11; 
	List342<Child> class1, class2, soccer, chess; 
	int a = 1, b = -1, c = 13; 
	class1.Insert(&c1); 
	class1.Insert(&c2); 
	class1.Insert(&c3); 
	class1.Insert(&c4); 
	class1.Insert(&c5); 
	class1.Insert(&c6); 
	class1.Insert(&c5); 
	cout << "class1: " << class1 << endl; 
	if (class1.Insert(&c1)) 
	{ 
		cout << "ERROR::: Duplicate" << endl; 
	}
	class2.Insert(&c4); 
	class2.Insert(&c5); 
	class2.Insert(&c6); 
	class2.Insert(&c7); 
	class2.Insert(&c10); 
	cout << "Class2: " << class2 << endl;

	class1.Merge(class2); 
	class2.Merge(class1); 
	class1.Merge(class2); 
	class1.Merge(class1); 
	cout << "class1 and 2 Merged: " << class1 << endl; 
	if (!class2.isEmpty()) 
	{
		cout << "ERROR:: Class2 should be empty empty" << endl;
	}

	cout << "(class1 == class2)" << (class1 == class2) << endl;



	List342<Child> class3;
	class3.Insert(&c4);
	class3.Insert(&c5);
	class3.Insert(&c6);
	class3.Insert(&c7);
	class3.Insert(&c10);

	cout << "class3 = " << class3 << endl;

	cout << "(class3 == class3)" << (class3 == class3) << endl;
	cout << "(class3 != class 1) " << (class3 != class1) << endl;

	class1.Merge(class2);
	cout << "class1 after: " << class1 << endl;
	cout << "class2 after: " << class2 << endl;

	cout << "(class1 == class2)" << (class1 == class2) << endl;

	
}