#include <iostream>

using namespace std;

// prototype
int Catalan(int n);

// command line arguments added
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Incorrect number of arguments." << endl;
	}

	int number = atoi(argv[2]);

	// if correct number of arguments; print out catalan number
	if (number >= 0)
	{
		cout << Catalan(number) << endl;
	}
	else
	{
		cout << "Catalan does not take negative input." << endl;
	}
}

// calculates the catalan #
int Catalan(int n)
{
	// long int to support larger catalan #s
	long int number = 0;

	// base case
	if (n == 1 || n == 0)
	{
		return 1;
	}

	// recursive case
	else
	{
		for (int i = 0; i < n; i++)
		{
			number += Catalan(i) * Catalan(n - i - 1);
		}
		return number;
	}
}