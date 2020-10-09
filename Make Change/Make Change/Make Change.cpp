// Make Change.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 1/22/2018 - Landon Holland
// Input money and output change it would make

#include "pch.h" // Everything
#include <iostream> // For cin and cout
#include <iomanip> // For manipulating all of the cout stuff
#include <Windows.h> // Console text color
#include <time.h> // RNG
using namespace std;

int main()
{
	char loopAnswer; // Declare variable for run again

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Initialize hConsole for all statements of SetConsoleTextAttribute

	do {
		const float TAX_RATE = 0.0575;
		int mainMenuOption; // Declare variable for main menu choice
		char name[20]; // Character array for name
		// Variables for change
		float purchase;
		unsigned int min;
		unsigned int max;
		float received;
		float tax;
		float total;
		float change;
		float remaining;
		int dollars50;
		int dollars20;
		int dollars10;
		int dollars5;
		int dollars;
		int quarters;
		int dimes;
		int nickels;
		int pennies;

		// Show menu
		system("cls"); // Clear the screen

		SetConsoleTextAttribute(hConsole, 6); // Color yellow
		cout << "McChange Menu" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "1 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- Big Mac ($5.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "2 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- Quarter Pounder ($7.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "3 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- Double Quarter Pounder ($8.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "4 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- McMuffin ($5.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "5 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- McNuggets ($6.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "6 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- 2 Snack Wraps ($3.50)" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "7 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- Custom Entry" << endl;
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "8 ";
		SetConsoleTextAttribute(hConsole, 5); // Color purple
		cout << "- RNG" << endl;
		
		// User input for the menu
		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << "Choice: ";
		cin >> mainMenuOption;

		cout << "Name: ";
		cin.ignore();
		cin.getline(name, 20);

		SetConsoleTextAttribute(hConsole, 15); // Color white
		cout << setfill('-') << setw(50) << "" << endl; // Line divider

		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		// If test for the option chosen on the menu
		if (mainMenuOption == 1)
		{
			purchase = 5.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 2)
		{
			purchase = 7.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 3)
		{
			purchase = 8.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 4)
		{
			purchase = 5.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 5)
		{
			purchase = 6.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 6)
		{
			purchase = 3.50;
			cout << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		else if (mainMenuOption == 7)
		{
			// Custom entry
			cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left | ios::fixed | ios::showpoint) << setprecision(2) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setw(1) << "";
			cin >> purchase;
		}
		else if (mainMenuOption == 8)
		{
			// RNG
			srand((unsigned) time(NULL)); // Set seed for RNG
			// Ask for min and max
			cout << "Min: ";
			cin >> min;
			cout << "Max: ";
			cin >> max;

			purchase = (rand() % (max - min + 1)) + min; // RNG for purchase

			cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left | ios::fixed | ios::showpoint) << setw(25) << setfill(' ') << "Enter purchase price:"
				<< setiosflags(ios::right) << setw(19) << "$" << setprecision(2) << setw(6) << purchase << endl;
		}
		// Calculate tax and total, then output it
		tax = purchase * TAX_RATE;
		total = purchase + tax;

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Tax:"
			<< setiosflags(ios::right) << setw(19) << "$" << setw(6) << tax << endl;
		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Total:"
			<< setiosflags(ios::right) << setw(19) << "$" << setw(6) << total << endl;

		// Ask for amount received
		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Enter amount received:"
			<< setiosflags(ios::right) << setw(19) << "$" << setw(1) << "";
		cin >> received;

		// Calculate change and output it
		change = received - total;
		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Change due:"
			<< setiosflags(ios::right) << setw(19) << "$" << setw(6) << change << endl;

		// Start calculations
		dollars50 = change / 50; // Do an integer divide for $50
		remaining = change - (dollars50 * 50); // Figure out the change remaining after taking out a certain amount of $50. We use the remaining variable as a running variable

		dollars20 = remaining / 20; // Do an integer divide for $20
		remaining = remaining - (dollars20 * 20); // Find remaining change after $20 bills taken out

		dollars10 = remaining / 10; // Do an integer divide for $10
		remaining = remaining - (dollars10 * 10); // Find remaining change after $10 bills taken out

		dollars5 = remaining / 5; // Do an integer divide for $5
		remaining = remaining - (dollars5 * 5); // Find remaining change after $5 bills taken out

		dollars = remaining / 1; // Do an integer divide for $1
		remaining = remaining - dollars; // Find remaining change after $1 bills taken out

		quarters = remaining / 0.25; // Do an integer divide for $0.25
		remaining = remaining - (quarters * 0.25); // Find remaining change after quarters taken out

		dimes = remaining / 0.10; // Do an integer divide for $0.10
		remaining = remaining - (dimes * 0.10); // Find remaining change after dimes taken out

		nickels = remaining / 0.05; // Do an integer divide for $0.05
		remaining = remaining - (nickels * 0.05); // Find remaining change after nickels taken out

		pennies = remaining / 0.01; // Do an integer divide for $0.01
		// remaining should = 0 now

		// Time to output all the change stuff
		SetConsoleTextAttribute(hConsole, 15); // Color white
		cout << setfill('-') << setw(50) << "" << endl; // Line divider

		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << resetiosflags(ios::adjustfield) << setfill(' ') << setiosflags(ios::left) << setw(15) << "$50 bills:" << setw(10) << dollars50 <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dollars50 * 50.0) << endl; // $50 bills output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "$20 bills:" << setw(10) << dollars20 <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dollars20 * 20.0) << endl; // $20 bills output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "$10 bills:" << setw(10) << dollars10 <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dollars10 * 10.0) << endl; // $10 bills output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "$5 bills:" << setw(10) << dollars5 <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dollars5 * 5.0) << endl; // $5 bills output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "$1 bills:" << setw(10) << dollars <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dollars * 1.0) << endl; // $1 bills output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "Quarters:" << setw(10) << quarters <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (quarters * 0.25) << endl; // Quarters output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "Dime:" << setw(10) << dimes <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (dimes * 0.10) << endl; // Dimes output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "Nickels:" << setw(10) << nickels <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (nickels * 0.05) << endl; // Nickels output

		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(15) << "Pennies:" << setw(10) << pennies <<
			setiosflags(ios::right) << setw(19) << "$" << setw(6) << (pennies * 0.01) << endl; // Pennies output

		SetConsoleTextAttribute(hConsole, 15); // Color white
		cout << setfill('-') << setw(50) << "" << endl; // Line divider

		SetConsoleTextAttribute(hConsole, 11); // Color aqua
		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setfill(' ') << setw(25) << "Total Change:"
			<< setiosflags(ios::right) << setw(19) << "$" << setw(6) << change << endl;
		
		cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Name:"
			<< setiosflags(ios::right) << setw(20) << name << endl << endl;

		// Ask to run again
		SetConsoleTextAttribute(hConsole, 15); // Color white
		cout << "Run again? [Y/n] ";
		cin >> loopAnswer;
	} while (loopAnswer == 'Y' || loopAnswer == 'y'); // While part of loop, loops if ans = Y or y
}