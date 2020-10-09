// Lineseg.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 4/16/2019
// Linseg and point class

#include "pch.h"
#include <iostream>
#include "point.h"
#include "lineseg.h"

using namespace std;

int main()
{
	point a(1, 2);
	point b;

	cout << a.toString() << endl << b.toString() << endl;

	lineseg l(a, b);

	cout << l.getEquation() << endl;

	cout << l.findDistance() << endl << l.findMidpoint().toString() << endl;

	system("pause");
}