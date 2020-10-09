// point.h
// Landon Holland

#pragma once
#ifndef _POINT_H
#define _POINT_H

#include <string>
#include <sstream>

using namespace std;

class point {
public:
	point(); // Default constructor
	point(float x, float y); // Fill constructor

	// Member functions
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);

	string toString(); // to string function

private:
	float myX, myY;
};

point::point() {
	myX = 0.0;
	myY = 0.0;
}

point::point(float x, float y) {
	myX = x;
	myY = y;
}

float point::getX() {
	return myX;
}

void point::setX(float x) {
	myX = x;
}

float point::getY() {
	return myY;
}

void point::setY(float y) {
	myY = y;
}

string point::toString() {
	stringstream sout;

	sout << '(' << myX << ", " << myY << ')';
	return sout.str();
}

#endif // !_POINT_H
