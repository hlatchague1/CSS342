#include "GreedyRobot.h"

const int GreedyRobot::MAX_NUM_SAME_DIRECTION;


GreedyRobot::GreedyRobot()
{
	x = 0;
	y = 0;
	goalX = 0;
	goalY = 0;

	shortestPaths(x, y, pathName, 0);
}


GreedyRobot::~GreedyRobot()
{
}

GreedyRobot::GreedyRobot(int startX, int startY, int endX, int endY)
{
	x = startX;
	y = startY;
	goalX = endX;
	goalY = endY;

	shortestPaths(x, y, pathName, 0);
}

int GreedyRobot::getX() const
{
	return x;
}

int GreedyRobot::getY() const
{
	return y;
}

int GreedyRobot::getGoalX() const
{
	return goalX;
}

int GreedyRobot::getGoalY() const
{
	return goalY;
}

void GreedyRobot::moveRobotNorth(int startX, int startY, string pathName, int pathLength)
{
	return shortestPaths(startX, (startY + 1), pathName + 'N', pathLength + 1);
}

void GreedyRobot::moveRobotSouth(int startX, int startY, string pathName, int pathLength)
{
	return shortestPaths(startX, (startY - 1), pathName + 'S', pathLength + 1);
}

void GreedyRobot::moveRobotEast(int startX, int startY, string pathName, int pathLength)
{
	return shortestPaths((startX + 1), startY, pathName + 'E', pathLength + 1);
}

void GreedyRobot::moveRobotWest(int startX, int startY, string pathName, int pathLength)
{
	return shortestPaths((startX - 1), startY, pathName + 'W', pathLength + 1);
}

void GreedyRobot::shortestPaths(int startX, int startY, string pathName, int pathLength)
{
	if (startX == goalX && startY == goalY)
	{
		cout << pathName << endl;
		cout << "Robot & treasure = same location." << endl;
		pathCount++;
	}
	else
	{
		// Robot = south of treasure
		if (startY < goalY)
		{
			// Robot = west of treasure
			if (startX < goalX)
			{
				moveRobotEast(startX, startY,pathName, pathLength);
			}
			// Robot = east of treasure
			else
			{
				moveRobotWest(startX, startY, pathName, pathLength);
			}

			moveRobotNorth(startX, startY, pathName, pathLength);
		}
		// Robot = north of treasure
		else
		{
			// Robot = west of treasure
			if (startX < goalX)
			{
				moveRobotEast(startX, startY, pathName, pathLength);
			}
			// Robot = east of treasure
			else
			{
				moveRobotWest(startX, startY, pathName, pathLength);
			}

			moveRobotSouth(startX, startY, pathName, pathLength);
		}














		// Robot is South of Treasure
		/*if (startX < goalX)
		{
			if(startY )
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == pathName[pathLength - 1])
				{
					shortestPaths(startX + 1, startY, pathName + 'E', pathLength + 1);
				}
			}
			else
			{
				shortestPaths(startX + 1, startY, pathName + 'E', pathLength + 1);
			}
		}
		else if (startX > goalX)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == pathName[pathLength - 1])
				{
					shortestPaths(startX - 1, startY, pathName + 'W', pathLength + 1);
				}
			}
			else
			{
				shortestPaths(startX - 1, startY, pathName + 'W', pathLength + 1);
			}
		}
		if (startY < goalY)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == pathName[pathLength - 1])
				{
					shortestPaths(startX, startY + 1, pathName + 'N', pathLength + 1);
				}
			}
			else
			{
				moveRobotNorth(startX, startY, pathName, pathLength);
			}
		}
		else if (startY > goalY)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == pathName[pathLength - 1])
				{
					shortestPaths(startX, startY - 1, pathName + 'S', pathLength + 1);
				}
			}
			else
			{
				shortestPaths(startX, startY - 1, pathName + 'S', pathLength + 1);
			}
		}
	}*/
	}
}


