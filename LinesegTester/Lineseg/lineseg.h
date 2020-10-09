// lineseg.h
// Landon Holland

#pragma once
#ifndef _LINESEG_H
#define _LINESEG_H

#include <string>
#include <cmath>
#include <sstream>
#include "point.h"

using namespace std;

class lineseg {
public:
	lineseg(); // default constructor
	lineseg(point bp, point ep); // fill constructor

	// member functions
	point getBP();
	void setBP(point bp);
	point getEP();
	void setEP(point ep);

	string toString();

	float findDistance();
	float findSlope();
	float findYint();
	point findMidpoint();
	string getEquation();

private:
	point myBP, myEP;
};

lineseg::lineseg() {}

lineseg::lineseg(point bp, point ep) {
	myBP = bp;
	myEP = ep;
}

point lineseg::getBP() {
	return myBP;
}

void lineseg::setBP(point bp) {
	myBP = bp;
}

point lineseg::getEP() {
	return myEP;
}

void lineseg::setEP(point ep) {
	myEP = ep;
}

string lineseg::toString() {
	stringstream sout;

	sout << myBP.toString() << ' ' << myEP.toString();
	return sout.str();
}

float lineseg::findDistance() {
	return sqrt(pow(myBP.getX() - myEP.getX(), 2) + pow(myBP.getY() - myEP.getY(), 2));
}

float lineseg::findSlope() {
	return (myBP.getY() - myEP.getY()) / (myBP.getX() - myEP.getY());
}

float lineseg::findYint() {
	return myBP.getY() - (myBP.getX() * findSlope());
}

point lineseg::findMidpoint() {
	return point((myBP.getX() + myEP.getX()) / 2, (myBP.getY() + myEP.getY()) / 2);
}

string lineseg::getEquation() {
	stringstream sout;

	sout << "y = " << findSlope() << "x + " << findYint();
	return sout.str();
}

#endif // !_LINESEG_H
