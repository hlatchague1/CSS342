#pragma once

#ifndef BIRD_H
#define BIRD_H

#include <string>

using namespace std;

class Bird
{
public:
	//constructors & destructor
	//Bird();
	//Bird(string name, int birdID);
	//~Bird();

	////getters
	//string getName();
	//int getBirdID();

	////setter
	//void setBird(string birdName, int ID);

	////overloaded operators
	//Bird operator+(const Bird& rhs) const;
	//Bird operator-(const Bird& rhs) const;
	//bool operator==(const Bird& rhs) const;
	//bool operator!=(const Bird& rhs) const; 
	   	 
private:
	string name;
	int birdID;
};

#endif