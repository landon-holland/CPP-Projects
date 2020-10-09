// Chapter5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1/15/2019 - Landon Holland
// Arithmetic operations

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int mainMenuAnswer; // For program loop and main menu
	do {
		system("cls"); // Clear the screen

		// Display title and options for main menu
		cout << "Chapter 5 Projects" << endl << endl;
		cout << "1  - Transportation" << endl;
		cout << "2  - Ellipse" << endl;
		cout << "3  - Degrees to Radians" << endl;
		cout << "4  - Speed" << endl;
		cout << "5  - Finance" << endl;
		cout << "6  - Electricity" << endl;
		cout << "7  - Force" << endl;
		cout << "8  - Einstein" << endl;
		cout << "9  - Law Enforcement" << endl;
		cout << "10 - Surveying" << endl;
		cout << "0  - Exit program" << endl << endl;

		// Ask for choice and store to variable
		cout << "Choice [0-10] ";
		cin >> mainMenuAnswer;

		// If test for the choice from the main menu
		if (mainMenuAnswer == 1) {
			// Transportation
			unsigned int people; // Declare variable to store the number of people
			unsigned int busses; // to store the number of busses
			unsigned int leftoverpeople; // to store the number of leftover people

			system("cls"); // Clear the screen

			// Ask for and input number of people
			cout << "Number of people: ";
			cin >> people;

			// Do math to find number of busses and leftover people
			busses = people / 50;
			leftoverpeople = people % 50;

			// Output answer to screen
			cout << endl << "Busses: " << busses << endl;
			cout << "Leftover people: " << leftoverpeople << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 2) {
			// Ellipse
			const double pi = 3.141592653589793238463; // pi constant
			double segmentA; // A
			double segmentB; // and B segments
			double areaOfEllipse; // Final answer of the area

			system("cls"); // Clear the screen

			// Ask for sides A and B
			cout << "Length of segment A: ";
			cin >> segmentA;
			cout << "Length of segment B: ";
			cin >> segmentB;

			// Do math to find area of the ellipse
			areaOfEllipse = pi * segmentA * segmentB;

			// Output answer to screen
			cout << endl << "Area of Ellipse: " << areaOfEllipse << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 3) {
			// Degrees to radians
			double degrees;
			double radians;

			system("cls"); // Clear the screen

			// Ask for degrees and store
			cout << "Degrees: ";
			cin >> degrees;

			// Do math to find radians from degrees
			radians = degrees / 57.3;

			// Output answer to screen
			cout << endl << "Radians: " << radians << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 4) {
			// Speed
			double mph;
			double fps;

			system("cls"); // Clear the screen

			// Ask for MPH to convert to FPS
			cout << "Miles per hour: ";
			cin >> mph;

			// Do math to convert MPH to FPS
			fps = mph * 1.46667;

			// Output answer to screen
			cout << endl << "Feet per second: " << fps << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 5) {
			// Finance
			double principal;
			double rate;
			double time;
			double interest;

			system("cls"); // Clear the screen

			// Ask for principal, interest rate, and period; then store to variables
			cout << "Principal: ";
			cin >> principal;

			cout << "Interest rate: ";
			cin >> rate;

			cout << "Time: ";
			cin >> time;

			// Calculate simple interest
			interest = principal * rate * time;

			// Output simple interest
			cout << endl << "Simple interest: " << interest << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 6) {
			// Electricity
			double voltage;
			double resistance;
			double current;

			system("cls"); // Clear the screen

			// Ask for voltage drop and resistance
			cout << "Voltage drop: ";
			cin >> voltage;

			cout << "Resistance (ohms): ";
			cin >> resistance;

			// Calculate the current going through the resistor
			current = voltage / resistance;

			// Output the current to user
			cout << endl << "Current (amps): " << current << endl << endl;

			// Pause so that the user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 7) {
			// Force
			double mass;
			double acceleration;
			double force;

			system("cls"); // Clear the screen

			// Ask for mass and acceleration
			cout << "Mass (kg): ";
			cin >> mass;

			cout << "Acceleration (m/s^2): ";
			cin >> acceleration;

			// Calculate force with mass and acceleration
			force = mass * acceleration;

			// Output the force to user
			cout << endl << "Force (newtons): " << force << endl << endl;

			// Pause so that the user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 8) {
			// Einstein
			double mass;
			long double energy;
			const unsigned long long c2 = 89875517873681800; // This is big

			system("cls"); // Clear the screen

			// Ask for mass
			cout << "Mass: ";
			cin >> mass;

			// Calculate energy (this is gonna create some errors)
			energy = mass * c2;

			// Output this mess
			cout << endl << "Energy: " << energy << endl << endl;

			// Pause so that user can read output
			system("pause");
		}
		else if (mainMenuAnswer == 9) {
			// Law Enforcement
			const double baseFine = 50; // $50 base fine
			const double fineRate = 1; // $2 per mph over
			double totalFine;
			int speedLimit;
			int speed;

			system("cls"); // Clear the screen

			// Ask for speed limit and actual speed
			cout << "Speed limit: ";
			cin >> speedLimit;

			cout << "Speed: ";
			cin >> speed;

			// Calculate total fine
			totalFine = baseFine + ((speed - speedLimit) * 2);

			// Output total fine
			cout << endl << "Fine: " << totalFine << endl << endl;

			// Pause so that the user can read output
			system("pause");

		}
		else if (mainMenuAnswer == 10) {
			// Surveying
			float temperature;
			double measuredLength;
			double finalLength;

			system("cls"); // Clear the screen

			// Ask for temperature in Celsius and what they measured
			cout << "Measured length: ";
			cin >> measuredLength;

			cout << "Temperautre (C): ";
			cin >> temperature;

			// Calculate final length
			finalLength = measuredLength + ((temperature - 20) * 0.0000116 * measuredLength);

			// Output final length
			cout << endl << "Adjusted length: " << finalLength << endl << endl;

			// Pause to read output
			system("pause");
		}
	} while (mainMenuAnswer != 0);
}