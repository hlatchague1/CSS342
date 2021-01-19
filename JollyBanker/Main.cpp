#include "Bank.h"
#include "Account.h"
#include "BSTree.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	Bank jolly;
	jolly.CreateTransaction("BankTransIn.txt");
	jolly.FulfillTransaction();
	jolly.Display();
	return 0;
}