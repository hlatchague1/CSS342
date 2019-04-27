#pragma once

#ifndef GREEDYROBOT_H
#define GREEDYROBOT_H

#include <string>
#include <iostream>

using namespace std;

class GreedyRobot
{
public:
	GreedyRobot();
	GreedyRobot(int x, int y, int goalX, int goalY);

	~GreedyRobot();

	int getX() const;
	int getY() const;
	int getGoalX() const;
	int getGoalY() const;

	void shortestPaths(int x, int y, string pathName, int directionCounter);


	static const int MAX_NUM_SAME_DIRECTION = 2;

private:
	int x = 0;
	int y = 0;
	int goalX = 0;
	int goalY = 0;

	string pathName = "";
	int pathLength = 0;
	int pathCount = 0;

	void moveRobotNorth(int x, int y, string pathName, int directionCounter);
};

#endif // !GREEDYROBOT_H
