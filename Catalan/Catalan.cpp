#include <iostream>

using namespace std;

// prototype
int Catalan(int n);

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
		cout << "Argument must be <= 0." << endl;
	}
}

// calculates the catalan #
int Catalan(int n)
{
	// long int to support larger catalan #s
	long int number = 0;

	// invalid entry
	if (n < 0)
	{
		cerr << "Invalid input! Please enter a positive number." << endl;
		exit(1);
	}

	// base case
	if (n <= 1)
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