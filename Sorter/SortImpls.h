#ifndef SORTIMPLS_H
#define SORTIMPLS_H

#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

void BubbleSort(vector<int>& myVector, int pass, int length)
{
	int lastIndex = (myVector.size() - 1);
	bool swap = false;
	int numberOfPasses = 0;
	int temp;
	while (!swap && (numberOfPasses < myVector.size() - 1))
	{
		swap = true;
		for (int index = 0; index < (length - numberOfPasses); index++)
		{
			if (myVector[index] > myVector[index + 1])
			{
				temp = myVector[index];
				myVector[index] = myVector[index + 1];
				myVector[index + 1] = temp;
				swap = false;
			}
		}
		numberOfPasses++;
	}
}


void InsertionSort(vector<int>& myVector, int firstIndex, int length)
{
	int unsortedList, sortedList;
	for (firstIndex; firstIndex <= length; firstIndex++)
	{
		unsortedList = myVector[firstIndex];
		sortedList = firstIndex - 1;

		while (sortedList >= 0 && myVector[sortedList] > unsortedList)
		{
			myVector[sortedList + 1] = myVector[sortedList];
			sortedList = sortedList - 1;
		}
		myVector[sortedList + 1] = unsortedList;
	}

}

void MergeSort(vector<int>& myVector, int firstIndex, int lastIndex)
{
	if (first < last)
	{

	}

}

//void IterativeMergeSort(vector<int>& myVector, int firstIndex, int lastIndex)
//{
//
//
//}
//
//void QuickSort(vector<int>& myVector, int firstIndex, int lastIndex)
//{
//
//
//}
//
//void ShellSort(vector<int>& myVector, int firstIndex, int lastIndex)
//{
//
//
//}

#endif // !SORTIMPLS_H