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


//void InsertionSort(vector<int>& myVector, int firstIndex, int lastIndex)
//{
//
//
//}
//
//void MergeSort(vector<int>& myVector, int firstIndex, int lastIndex)
//{
//
//
//}
//
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