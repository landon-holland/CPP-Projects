// quad.h
// Landon Holland

#pragma once
#ifndef _QUAD_H
#define _QUAD_H

#include <string>
#include <sstream>
#include <cmath>
#include "lineseg.h"

using namespace std;

class quad {
public:
	quad(); // default constructor
	quad(point p1, point p2, point p3, point p4); // point fill constructor
	quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4); // lineseg fill constructor

	// member functions
	lineseg getLS(int index);
	void setLS(int index, lineseg l);

	string toString();

	bool isPar();
	bool isRhombus();
	bool isRect();
	bool isSquare();

	//float findArea();
private:
	// data
	lineseg myLS[4];
};

quad::quad() {
	for (int i = 0; i <= 3; i++) {
		myLS[i] = lineseg();
	}
}

quad::quad(point p1, point p2, point p3, point p4) {
	myLS[0] = lineseg(p1, p2);
	myLS[1] = lineseg(p2, p3);
	myLS[2] = lineseg(p3, p4);
	myLS[3] = lineseg(p4, p1);
}

quad::quad(lineseg l1, lineseg l2, lineseg l3, lineseg l4) {
	myLS[0] = l1;
	myLS[1] = l2;
	myLS[2] = l3;
	myLS[3] = l4;
}

lineseg quad::getLS(int index) {
	return myLS[index];
}

void quad::setLS(int index, lineseg l) {
	myLS[index] = l;
}

string quad::toString() {
	stringstream sout;

	for (int i = 0; i <= 3; i++) {
		sout << myLS[i].toString() << endl;
	}

	return sout.str();
}

bool quad::isPar() {
	return (myLS[0].findSlope() == myLS[2].findSlope() && myLS[1].findSlope() == myLS[3].findSlope());
}

bool quad::isRhombus() {
	return (isPar() && myLS[0].findDistance() == myLS[1].findDistance() && myLS[1].findDistance() == myLS[2].findDistance() && myLS[2].findDistance() == myLS[3].findDistance() && myLS[3].findDistance() == myLS[0].findDistance());
}

bool quad::isRect() {
	return (isPar() && myLS[0].findSlope() == -1 / myLS[1].findSlope());
}

bool quad::isSquare() {
	return (isRect() && isRhombus());
}

#endif // !_QUAD_H
