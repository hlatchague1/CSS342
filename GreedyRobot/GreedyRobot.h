#pragma once

#ifndef GREEDYROBOT_H
#define GREEDYROBOT_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class GreedyRobot
{
public:
	// constructors
	GreedyRobot();
	GreedyRobot(int x, int y, int goalX, int goalY);

	// destructor
	~GreedyRobot();

	// getters
	int getX() const;
	int getY() const;
	int getGoalX() const;
	int getGoalY() const;

	// setter
	bool setLocation(int x, int y, int goalX, int goalY);

	// recursive method
	void shortestPaths(int x, int y, string pathName, int pathLength, int& counter);

	// stream operator overloaders
	friend istream& operator >> (istream& input, GreedyRobot& inputR);
	friend ostream& operator << (ostream& output, GreedyRobot& outputR);

	// static const variable
	static const int MAX_NUM_SAME_DIRECTION = 2;

private:
	int x = 0;
	int y = 0;
	int goalX = 0;
	int goalY = 0;


	string pathName = "";
	int pathLength = 0;
	int counter = 0;

};

#endif // !GREEDYROBOT_H
