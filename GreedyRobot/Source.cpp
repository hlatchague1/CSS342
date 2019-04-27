#include "GreedyRobot.h"

int main()
{
	cout << "r2(1,2,1,2);" << endl;
	GreedyRobot r2(1, 2, 1, 2);

	cout << "r3(1,2,1,3);" << endl;
	GreedyRobot r3(1, 2, 1, 3);

	cout << "r4(1,2,0,2);" << endl;
	GreedyRobot r4(1, 2, 0, 2);

	cout << "r1(1,2,2,3);" << endl;
	GreedyRobot r1(1, 2, 2, 3);

	cout << "r5(1, 2, 3, 5);" << endl;
	GreedyRobot r5(1, 2, 3, 5);

	cout << "r6(0,0,0,10);" << endl;
	GreedyRobot r6(0, 0, 0, 10);

}