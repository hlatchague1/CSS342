#include <iostream>

using namespace std;

// prototype
int Catalan(int n);

int main(int argc, char* argv[])
{
	for (int i = 0; i <= 10; i++)
	{
		cout << "Catalan(" << i << "); // " << Catalan(i) << endl;
	}
}

int Catalan(int n)
{
	long int number = 0;
	if (n < 0)
	{
		cerr << "Invalid input! Please enter a positive number." << endl;
		exit(1);
	}
	if (n <= 1)
	{
		return 1;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			number += Catalan(i) * Catalan(n - i - 1);
		}
		return number;
	}
}