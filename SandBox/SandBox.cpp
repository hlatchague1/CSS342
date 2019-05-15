// SandBox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector <int> &a) {
	cout << "The vector elements are : ";
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i) << ' ';
}

int main()
{
	vector<int> myVector = { 1,2,34,0,4 };
	print(myVector);
	int firstIndex = 0;
	int size = myVector.size();
	int lastIndex = (myVector.size()) - 1;
	bool swap = false;
	int numberOfPasses = 1;
	int temp;
	while (!swap && (numberOfPasses <=  myVector.size()))
	{
		swap = true;
		for (int index = firstIndex; index < (size - numberOfPasses); index++)
		{
			int nextIndex = index + 1;
			if (myVector[index] > myVector[nextIndex])
			{
				temp = myVector[index];
				myVector[index] = myVector[index + 1];
				myVector[index + 1] = temp;
				swap = false;
			}
		}
		numberOfPasses++;
	}
	print(myVector);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
