// MilitaryTime_Parabola.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 2/6/2018
// Find difference between military time eand solve quadratic forumla and linear equation

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int mainMenuChoice; // Choice between military and parabola
	do {
		system("cls"); // Clear the screen

		// Output menu options
		cout << "1) Military Time" << endl;
		cout << "2) Parabola" << endl;
		cout << "0) Exit Program" << endl;

		// Ask for input of main menu choice
		cout << "Choice [0-2] ";
		cin >> mainMenuChoice;

		// If test between the two programs
		if (mainMenuChoice == 1) {
			// Military time

			// Time inputs
			int time1;
			int time2;

			// Variables for intermediate math
			int hrs1;
			int hrs2;
			int min1;
			int min2;

			// Time outputs
			int hrsDifference;
			int minDifference;

			system("cls"); // Clear the screen

			// Input the military times
			cout << "Enter the first time: ";
			cin >> time1;
			cout << "Enter the second time: ";
			cin >> time2;

			// Calculations
			// Seperate hours and minutes from the time
			hrs1 = time1 / 100;
			hrs2 = time2 / 100;
			min1 = time1 % 100;
			min2 = time2 % 100;

			// If tests to do the right math to find the difference
			if (hrs1 <= hrs2) {
				if (min1 <= min2) {
					hrsDifference = hrs2 - hrs1;
					minDifference = min2 - min1;
				}
				else if (min1 > min2) {
					hrsDifference = hrs2 - hrs1 - 1;
					minDifference = min2 - min1 + 60;
				}
			}
			else if (hrs1 > hrs2) {
				if (min1 <= min2) {
					hrsDifference = 24 + hrs2 - hrs1;
					minDifference = min2 - min1;
				}
				else if (min1 > min2) {
					hrsDifference = 23 + hrs2 - hrs1;
					minDifference = min2 - min1 + 60;
				}
			}
			// Output the answer
			cout << endl << hrsDifference << " hours and " << minDifference << " minutes." << endl;

			system("pause"); // Pause so user can read output
		}
		else if (mainMenuChoice == 2)
		{
			// Parabola

			// Declare inputs
			double a, b, c;
			double x1, x2, y1, y2;

			// Declare outputs
			double r1, r2;
			double m;
			double yint;
			double xi1, xi2, yi1, yi2;

			// Declare intermediate variables
			double discriminant;
			double newb;
			double newc;
			double discriminant2;

			system("cls"); // Clear the screen

			// Ask for and input a, b, and c
			cout << "A: ";
			cin >> a;
			cout << "B: ";
			cin >> b;
			cout << "C: ";
			cin >> c;

			// Calculatations for the roots
			discriminant = (b * b) - (4 * a * c);

			if (discriminant == 0) {
				// One root
				r1 = -b / (2 * a);
				cout << "The root is: " << r1 << endl << endl;
			}
			else if (discriminant < 0) {
				// Imaginary roots
				r1 = (-b + sqrt(-(b * b - (4 * a * c)))) / (2 * a);
				r2 = (-b - sqrt(-(b * b - (4 * a * c)))) / (2 * a);
				cout << "The roots are: " << r1 << "i and " << r2 << "i" << endl << endl;
			}
			else {
				// Two roots
				r1 = (-b + sqrt(b * b - (4 * a * c))) / (2 * a);
				r2 = (-b - sqrt(b * b - (4 * a * c))) / (2 * a);
				cout << "The roots are: " << r1 << " and " << r2 << endl << endl;
			}

			// Ask for X1, X2, Y1, Y2
			cout << "X1: ";
			cin >> x1;
			cout << "Y1: ";
			cin >> y1;
			cout << "X2: ";
			cin >> x2;
			cout << "Y2: ";
			cin >> y2;

			// Calculations for m and b
			m = (y2 - y1) / (x2 - x1);
			yint = (m * -x1) + y1;
			cout << "Slope: " << m << endl;
			cout << "Y-Interecpt: " << yint << endl << endl;

			// Intersection point calculations
			newb = b - m;
			newc = c - yint;

			discriminant2 = (newb * newb) - (4 * a * newc);

			if (discriminant2 == 0) {
				// One root
				xi1 = -newb / (2 * a);
				yi1 = m * xi1 + yint;

				cout << "The point of intersection is: (" << xi1 << ", " << yi1 << ")" << endl << endl;
			}
			else if (discriminant2 < 0) {
				cout << "No intersection" << endl << endl;
			}
			else {
				// Two roots
				xi1 = (-newb + sqrt(newb * newb - (4 * a * newc))) / (2 * a);
				xi2 = (-newb - sqrt(newb * newb - (4 * a * newc))) / (2 * a);
				yi1 = m * xi1 + yint;
				yi2 = m * xi2 + yint;

				cout << "The points of intersection are: (" << xi1 << ", " << yi1 << ") and (" << xi2 << ", " << yi2 << ")" << endl << endl;
			}
			system("pause"); // Pause so user can read output
		}
	} while (mainMenuChoice != 0);
	return 0;
}