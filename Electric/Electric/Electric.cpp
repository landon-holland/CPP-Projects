// Electric.cpp : Defines the entry point for the console application.
// 1/10/2019 - Landon Holland
// Input and output

#include "stdafx.h"
#include <iostream> // cin and cout
#include <iomanip> // setfill, setw, setprecision
#include <time.h> // date and time stuff
#include <ctime> // more date and time stuff
using namespace std;

int main()
{
	char ans;
	do {
		// Declare variables and constants for calculations
		int kwh;
		char name[15];
		float baseCost;
		float surcharge;
		float tax;
		float payment;
		float latePayment;
		const float taxRate = 0.03; // 3% tax
		const float surchargeRate = 0.1; // 10% surcharge
		const float electricityRate = 0.0475; // $0.0475 per kwh
		const float latePaymentRate = 0.04; // 4% late charge

		system("cls"); // Clear the screen
		system("color 17"); // Set color

		// Get KWH used from user and store it to kwh
		cout << "Enter KWH used: ";
		cin >> kwh;

		// Get name from user and store it
		cout << "Name: ";
		cin >> name;

		// Calculate all of the outputs
		baseCost = kwh * electricityRate;
		surcharge = baseCost * surchargeRate;
		tax = baseCost * taxRate;
		payment = baseCost + surcharge + tax;
		latePayment = payment + (payment * latePaymentRate);

		// Date commands
		char sdate[9];
		_strdate_s(sdate); // Put current date into sdate (string)

		time_t rawTime; // Declare place for now time
		struct tm lateTime; // Declare place for late time
		time(&rawTime); // Store now time into the delcared place
		localtime_s(&lateTime, &rawTime); // Use this now time to move it into the late time
		lateTime.tm_mday += 10; // Add ten days to the late time
		mktime(&lateTime); // Fix up the days (so it's not 1/41/19, but rather 2/10/19)

		// Header output
		cout << endl; // New line
		cout << setfill('-') << setw(50) << "" << endl; // ----------
		cout << setfill(' ') << setw(37) << setiosflags(ios::right | ios::fixed | ios::showpoint)
			<< "CompSci Electric Company" << endl; // CompSci Electric Company
		cout << setw(29) << sdate << endl;
		cout << setfill('-') << setw(50) << "" << endl; // ----------
		cout << setfill(' ') << resetiosflags(ios::left) << setw(15) << "Killowatts used" <<
			resetiosflags(ios::right) << setw(35) << kwh << endl; // Display the original killowatts used
		cout << setw(50) << name << endl; // Name output
		cout << setfill('-') << setw(50) << "" << endl; // ----------

		// Body output
		cout << endl; // New line
		cout << setfill(' ') << setw(10) << resetiosflags(ios::left) << "Base Rate:" << setw(13) << kwh << " @ $0.0475"
			<< setw(11) << resetiosflags(ios::right) << setprecision(2) << "$" << setw(6) << baseCost << endl; // Base Rate

		cout << setw(10) << resetiosflags(ios::left) << "Surcharge:" <<
			resetiosflags(ios::right) << setw(34) << "$" << setw(6) << surcharge << endl; // Surcharge

		cout << setw(10) << setiosflags(ios::left) << "Tax:" <<
			setiosflags(ios::right) << setw(34) << "$" << setw(6) << tax << endl; // Tax

		cout << setw(50) << "_______" << endl << endl; // Dividing line

		cout << setw(12) << setiosflags(ios::left) << "Payment due:" <<
			setiosflags(ios::right) << setw(32) << "$" << setw(6) << payment << endl; // Payment due

		cout << setw(15) << setiosflags(ios::left) << "Late payment @ " << (lateTime.tm_mon + 1) << "/" << lateTime.tm_mday << "/" << (lateTime.tm_year - 100) <<
			setiosflags(ios::right) << setw(22) << "$" << setw(6) << latePayment << endl; // Late payment

		// ASCII art output
		cout << " ___                        __            \n"
			"/\\_ \\                      /\\ \\           \n"
			"\\//\\ \\      __      ___    \\_\\ \\    ___   \n"
			"  \\ \\ \\   /'__`\\  /' _ `\\  /'_` \\  / __`\\ \n"
			"   \\_\\ \\_/\\ \\L\\.\\_/\\ \\/\\ \\/\\ \\L\\ \\/\\ \\L\\ \\\n"
			"   /\\____\\ \\__/.\\_\\ \\_\\ \\_\\ \\___,_\\ \\____/\n"
			"   \\/____/\\/__/\\/_/\\/_/\\/_/\\/__,_ /\\/___/ " << endl << endl;

		// Check to see if if we want to run again
		cout << "Run again [Y/n] ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');
	return 0;
}