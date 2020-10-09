// QuadTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 4/23/2019
// Test the quad class along with point and lineseg

#include "pch.h"
#include "point.h"
#include "lineseg.h"
#include "quad.h"
#include <iostream>

using namespace std;

int main()
{
	point a;
	a.setX(0);
	a.setY(1);

	lineseg l(a, point(2, 2));

	cout << a.toString() << endl << endl;
	cout << l.toString() << endl;
	cout << l.findDistance() << endl;
	cout << l.findSlope() << endl;
	cout << l.findMidpoint().toString() << endl;
	cout << l.getEquation() << endl << endl;

	quad q(a, point(2, 1), point(2, 3), point(0, 3));

	cout << q.toString() << endl;

	if (q.isPar()) {
		cout << "Para" << endl;
	}
	if (q.isRhombus()) {
		cout << "Rhombus" << endl;
	}
	if (q.isRect()) {
		cout << "Rect" << endl;
	}
	if (q.isSquare()) {
		cout << "Square" << endl << endl;
	}

	system("pause");
}