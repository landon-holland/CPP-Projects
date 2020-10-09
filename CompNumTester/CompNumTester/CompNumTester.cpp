// CompNumTester.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 4/26/2019 - Landon Holland
// Test compnum.h

#include "pch.h"
#include "compnum.h"
#include <iostream>

using namespace std;

int main()
{
	compnum cn1(1, 1);
	compnum cn2(1, 1);

	cout << cn1.toString() << endl << cn2.toString() << endl << endl;

	cout << (cn1 + cn2).toString() << endl;
	cout << (cn1 - cn2).toString() << endl;
	cout << (cn1 * cn2).toString() << endl;
	cout << (cn2 ^ 3).toString() << endl << endl;
	cout << (cn2 / cn1).toString() << endl;

	compnum stringtest("5+377i");
	cout << stringtest.toString() << endl;

	system("pause");
}
