#include "GreedyRobot.h"

// constant number dealing w rule saying
// robot can't go more than twice in same
// direction
const int GreedyRobot::MAX_NUM_SAME_DIRECTION;

// uninitialized constructor, sets 
// all equal to 0 & calls recursive
// method
GreedyRobot::GreedyRobot()
{

	setLocation(x, y, goalX, goalY);

	x = 0;
	y = 0;
	goalX = 0;
	goalY = 0;
	&counter;

	shortestPaths(x, y, pathName, 0, counter);
}

// destructor
GreedyRobot::~GreedyRobot()
{
}

// initialized constructor that calls
// the recursive method
GreedyRobot::GreedyRobot(int startX, int startY, int endX, int endY)
{

	setLocation(startX, startY, endX, endY);

	x = startX;
	y = startY;
	goalX = endX;
	goalY = endY;
	&counter;

	shortestPaths(x, y, pathName, 0, counter);
}

// return robot's x location
int GreedyRobot::getX() const
{
	return x;
}

// return robot's y location
int GreedyRobot::getY() const
{
	return y;
}

// returns treasure's x location
int GreedyRobot::getGoalX() const
{
	return goalX;
}

// returns treasure's y location
int GreedyRobot::getGoalY() const
{
	return goalY;
}

// sets location and returns true when done
bool GreedyRobot::setLocation(int x, int y, int goalX, int goalY) {
	this->x = x;
	this->y = y;
	this->goalX = goalX;
	this->goalY = goalY;

	return true;
}

// recursive method that determines the location of the treasure 
// in respect to the location of the robot, checks for the last 
// two letters added in the path to make sure the robot doesn't
// move more than twice in the same direction
void GreedyRobot::shortestPaths(int startX, int startY, string pathName, int pathLength, int& counter)
{
	// base case: prints out path and increment path counter
	if (startX == goalX && startY == goalY)
	{
		cout << pathName << endl;
		counter++;
	}
	// recursive case: checks location of treasure
	else
	{
		// Robot is West of treasure (move East)
		if (startX < goalX)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == 'E' && pathName[pathLength - 1] == 'E')
				{
					return;
				}
				else
				{
					shortestPaths(startX + 1, startY, pathName + 'E', pathLength + 1, counter);
				}
			}
			else
			{
				shortestPaths(startX + 1, startY, pathName + 'E', pathLength + 1, counter);
			}
		}
		// Robot is East of treasure (move West)
		else if (startX > goalX)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == 'W' && pathName[pathLength - 1] == 'W')
				{
					return;
				}
				else
				{
					shortestPaths(startX - 1, startY, pathName + 'W', pathLength + 1, counter);
				}
			}
			else 
			{
				shortestPaths(startX - 1, startY, pathName + 'W', pathLength + 1, counter);
			}
		}
		// Robot is South of treasure (move North)
		if (startY < goalY)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == 'N' && pathName[pathLength-1] == 'N')
				{
					return;
				}
				else
				{
					shortestPaths(startX, (startY + 1), pathName + 'N', pathLength + 1, counter);
				}
			}
			else
			{
				shortestPaths(startX, (startY + 1), pathName + 'N', pathLength + 1, counter);
			}
		}
		// Robot is North of treasure (move South)
		else if (startY > goalY)
		{
			if (pathName.length() >= MAX_NUM_SAME_DIRECTION)
			{
				if (pathName[pathLength - 2] == 'S' && pathName[pathLength - 1] == 'S')
				{
					return;
				}
				else
				{
					shortestPaths(startX, (startY - 1), pathName + 'S', pathLength + 1, counter);
				}
			}
			else
			{
				shortestPaths(startX, (startY - 1), pathName + 'S', pathLength + 1, counter);
			}
		}
	}
}

// >> operator overload takes in all 4 parameters
istream& operator >> (istream& input, GreedyRobot& r)
{
	input >> r.x >> r.y >> r.goalX >> r.goalY;
	return input;
}

// << operator overload outputs the number of paths
ostream& operator << (ostream& output, GreedyRobot& r)
{
	output << "Number of paths: " << r.counter << endl;
	return output;
}

