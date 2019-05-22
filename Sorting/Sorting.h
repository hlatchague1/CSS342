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

void MergeSortHelper(vector<int>& myVector, int first, int mid, int last)
{
	vector<int> tempVector(myVector);
	int thisFirst = first;
	int tempFirst = mid + 1;
	int thisLast = mid;
	int tempLast = last;

	int index = thisFirst;
	while ((thisFirst <= thisLast) && (tempFirst <= tempLast))
	{
		if (myVector[thisFirst] <= myVector[tempFirst])
		{
			tempVector[index] = myVector[thisFirst];
			thisFirst++;
		}
		else
		{
			tempVector[index] = myVector[tempFirst];
			tempFirst++;
		}
		index++;
	}
	while (thisFirst <= thisLast)
	{
		tempVector[index] = myVector[thisFirst];
		thisFirst++;
		index++;
	}
	while (tempFirst <= tempLast)
	{
		tempVector[index] = myVector[tempFirst];
		tempFirst++;
		index++;
	}

	for (index = first; index <= last; index++)
	{
		myVector[index] = tempVector[index];
	}
}

void MergeSort(vector<int>& myVector, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		int middleIndex = firstIndex + (lastIndex - firstIndex) / 2;
		MergeSort(myVector, firstIndex, middleIndex);
		MergeSort(myVector, middleIndex + 1, lastIndex);
		MergeSortHelper(myVector, firstIndex, middleIndex, lastIndex);
	}
}

int min(const int a, const int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void IterativeMergeSort(vector<int> & myVector, int firstIndex, int lastIndex)
{
	for (int index = 1; index < lastIndex + 1; index = 2 * index)
	{
		for (int nextIndex = firstIndex; nextIndex < (lastIndex + 1) - index; nextIndex = nextIndex + (2 * index))
		{
			int minimum = min(nextIndex + (2 * index) - 1, lastIndex);
			MergeSortHelper(myVector, nextIndex, nextIndex + index - 1, minimum);
		}
	}
}

int partition(vector<int> & myVector, int low, int high)
{
	int pivot = myVector[high];
	int index = (low - 1);
	int temp;

	for (int nextIndex = low; nextIndex <= high - 1; nextIndex++)
	{
		if (myVector[nextIndex] <= pivot)
		{
			index++;
			temp = myVector[index];
			myVector[index] = myVector[nextIndex];
			myVector[nextIndex] = temp;
		}
	}
	temp = myVector[index + 1];
	myVector[index + 1] = myVector[high];
	myVector[high] = temp;
	return (index + 1);
}

void QuickSort(vector<int> & myVector, int low, int high)
{
	if (low < high)
	{
		int pivotIndex = partition(myVector, low, high);
		QuickSort(myVector, low, pivotIndex - 1);
		QuickSort(myVector, pivotIndex + 1, high);
	}
}

void ShellSort(vector<int> & myVector, int firstIndex, int lastIndex)
{
	for (int gap = lastIndex / 2; gap > 0; gap /= 2)
	{
		for (int index = gap; index <= lastIndex; index += 1)
		{
			int temp = myVector[index];
			int nextIndex;
			for (nextIndex = index; nextIndex >= gap && myVector[nextIndex - gap] > temp; nextIndex -= gap)
			{
				myVector[nextIndex] = myVector[nextIndex - gap];
			}
			myVector[nextIndex] = temp;
		}
	}
}

#endif // !SORTIMPLS_H