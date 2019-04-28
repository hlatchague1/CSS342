#include "GreedyRobot.h"

int main()
{
	int x, y, goalX, goalY;

	cout << "Please enter a starting X, starting Y, goal X, and goal Y (in this order): " << endl;
	cin >> x >> y >> goalX >> goalY;

	cout << "Robot Location: (" << x << ", " << y << ")" << "\t"
		<< "Treasure Location: (" << goalX << ", " << goalY << ")" << endl;
	GreedyRobot r0(x, y, goalX, goalY);
	cout << r0 << endl;

	cout << "Robot Location: (1, 2)\tTreasure Location: (3, 5)" << endl;
	GreedyRobot r1(1, 2, 3, 5);
	cout << r1 << endl;

	cout << "Robot Location: (1, 0)\tTreasure Location: (-2, 3) " << endl;
	GreedyRobot r2(1,0,-2,3);
	cout << r2 << endl;

	cout << "Robot Location: (0, 0)\tTreasure Location: (0, 10) " << endl;
	GreedyRobot r3(0,0,0,10);
	cout << r3 << endl;

}