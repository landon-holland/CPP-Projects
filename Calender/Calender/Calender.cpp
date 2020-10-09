// Calender.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 2/19/2019
// Use Zeller's Formula to output a calender for one month

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()
{
	char RunAgain; // Variable for looping the whole program
	RunAgain = ' ';
	do {
		char date[11]; // Input for date
		// Input variables
		int k, m, y;
		// Computation variables
		int C, D;
		int f; // Zeller variable
		int nd; // Number of days based on the month of the year
		int i; // Counter
		int am; // Actual month, not screwed up from Zeller's
		int dc; // Day counting
		bool startedCounting; // Boolean to determine whether or not we've started listing days in the output

		system("cls"); // Clear the screen
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Initialize hConsole for all statements of SetConsoleTextAttribute

		// Ask for day, month, and year
		cout << "Date [mm/dd/yyyy]: ";
		if (RunAgain != ' ') {
			cin.ignore();
		}
		cin.getline(date, 11);
		cin.ignore(0, '\n');
		// Convert characters to int using typecasting and ascii values (0 = 48)
		//cout << date << endl;
		m = (10 * (int(date[0]) - 48)) + (int(date[1]) - 48);
		k = (10 * (int(date[3]) - 48)) + (int(date[4]) - 48);
		y = (1000 * (int(date[6]) - 48)) + (100 * (int(date[7]) - 48)) + (10 * (int(date[8]) - 48)) + (int(date[9]) - 48);

		//cout << m << ' ' << k << ' ' << y << endl;
		// Seperate year into C and D
		C = y / 100;
		D = y % 100;

		// Figure out number of days before we screw up month for Zeller's
		switch (m) {
			case 2:
				if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
					nd = 29;
				}
				else {
					nd = 28;
				}
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				nd = 30;
				break;
			default:
				nd = 31;
		}

		// Store a non-messed up version of m cause I'm lazy
		am = m;

		// Adjust month, C and D for Zeller's
		if (m <= 2) {
			m += 10;
			D -= 1;
			if (D == -1) {
				D = 99;
				C -= 1;
			}
		}
		else {
			m -= 2;
		}

		// Plug and chug Zeller's
		f = 1 + int((13 * m - 1) / 5) + D + int(D / 4) + int(C / 4) - (2 * C);
		f = f % 7;

		// Logic to fix Zeller's
		if (f < 0) {
			do {
				f += 7;
			} while (f < 0);
		}

		// Outputting the calender
		// Weekday headers
		cout << endl;
		cout << "  Sunday     Monday   Tuesday  Wednesday  Thursday   Friday   Saturday " << endl;
		cout << setiosflags(ios::fixed | ios::adjustfield) << setw(72) << setfill('-') << ' ' << endl;

		// Main loop
		startedCounting = false;
		dc = 1;
		for (i = 1; i <= 42; i++) {
			SetConsoleTextAttribute(hConsole, 15); // Color white
			cout << setw(1) << '|';
			if (startedCounting == false) { // For the beginning of the calender when there are no days
				if (i - 1 == f) { // If we need to start, then we start
					startedCounting = true;
					if (dc == k) { // If it's today then we change the color
						SetConsoleTextAttribute(hConsole, 11); // Color aqua
					}
					if (am == 1 || am == 4) { // Holidays that appear on the first of the month (New Year's Day and April Fools' Day)
						cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
					}
					else {
						cout << setw(9) << setfill(' ') << dc;
					}
					dc++;
				}
				else {
					cout << setw(9) << setfill(' ') << ' ';
				}
			}
			else if (startedCounting == true) { // Now we're listing actual days
				if (dc <= nd) {
					if (dc == k) { // If it's today, we change the color so the user can see the date they chose
						SetConsoleTextAttribute(hConsole, 11); // Color aqua
					}
					// Holiday test
					if (am == 2) {
						if (dc == 14) { // Valentine's Day
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 3) { 
						if (dc == 17) { // St. Patrick's Day
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 5) {
						if (dc == 5) { // Cinco de Mayo
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 6) {
						if (dc == 14) { // Flag Day
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 7) {
						if (dc == 4) { // Indepdence Day
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 9) {
						if (dc == 30) { // My birthday
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 10) {
						if (dc == 31) { // Halloween
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else if (am == 12) {
						if (dc == 25) { // Christmas
							cout << setw(7) << setfill(' ') << "***" << setw(2) << dc;
						}
						else {
							cout << setw(9) << setfill(' ') << dc;
						}
					}
					else {
						cout << setw(9) << setfill(' ') << dc;
					}
					dc++;
				}
				else { // If we've ran out of days in the month, we go back to outputting blanks
					cout << setw(9) << setfill(' ') << ' ';
				}
			}
			if (i % 7 == 0) { // This finishes the current cell and adds a new line
				SetConsoleTextAttribute(hConsole, 15); // Color white
				cout << setw(1) << '|' << endl;
				cout << setw(72) << setfill('-') << ' ' << endl;
			}
		}
		
		// Legend output
		cout << "*** - ";
		switch (am) {
		case 1:
			cout << "New Year's Day" << endl;
			break;
		case 2:
			cout << "Valentine's Day" << endl;
			break;
		case 3:
			cout << "St. Patrick's Day" << endl;
			break;
		case 4:
			cout << "April Fools' Day" << endl;
			break;
		case 5:
			cout << "Cinco de Mayo" << endl;
			break;
		case 6:
			cout << "Flag Day" << endl;
			break;
		case 7:
			cout << "Independence Day" << endl;
			break;
		case 9:
			cout << "Landon's Birthday" << endl;
			break;
		case 10:
			cout << "Halloween" << endl;
			break;
		case 12:
			cout << "Christmas" << endl;
			break;
		default:
			cout << "N/A" << endl;
			break;
		}
		// Ask to run again
		cout << "Run Again? [Y/n] ";
		cin >> RunAgain;
	} while (RunAgain == 'Y' || RunAgain == 'y');
	return 0;
}