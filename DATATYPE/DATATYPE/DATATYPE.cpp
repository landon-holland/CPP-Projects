// DATATYPE.cpp : Defines the entry point for the console application.
// Examples of variable declaration and initialization.
// Project 4.1

#include "stdafx.h"
#include <iostream> // Needed for cin and cout.
using namespace std;

int main()
{
	char ans;
	do {
		system("cls");
		const double SQUARE_ROOT_OF_TWO = 1.414214; // Declare constant for root 2.
		const double e = 2.7182818;
		const unsigned long speedoflight = 300000000;
		const double speedofsound = 340.292;

		int i;				// Declare i as an integer.
		long j;				// j as a long integer.
		unsigned long k;	// k as an unsigned long integer.
		float n;			// n as a floating point number.
		unsigned int l;
		int m;
		long z;
		unsigned long o;

		i = 3;				// Initialize i
		j = -2048111;		// j
		k = 4000000001;		// k
		n = 1.887;			// n
		l = 100;			// l
		m = -1000;			// m
		z = -40000;			// z
		o = 40000;			// o

		// Output constant and variables to screen.
		cout << SQUARE_ROOT_OF_TWO << '\n';
		cout << i << '\n';
		cout << j << '\n';
		cout << k << '\n';
		cout << n << '\n';
		cout << e << '\n';
		cout << l << '\n';
		cout << m << '\n';
		cout << z << '\n';
		cout << o << '\n';
		cout << speedoflight << '\n';
		cout << speedofsound << '\n';

		cout << "Run the program again? [Y/n] ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');
    return 0;
}