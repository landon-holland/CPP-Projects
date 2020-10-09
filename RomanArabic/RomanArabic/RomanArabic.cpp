// RomanArabic.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 2/11/2019
// Convert roman numbers to arabic and vice versa.

#include "pch.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int mainMenuChoice; // Store variable for either A to R or R to A.
	do {
		system("cls"); // Clear the screen

		// Output menu
		cout << "RomanArabic" << endl << endl;
		cout << "1 - Roman to Arabic" << endl;
		cout << "2 - Arabic to Roman" << endl;
		cout << "0 - Exit" << endl << endl;

		// User input to switch between the two modes
		cout << "Choice [0-2] ";
		cin >> mainMenuChoice;

		// If test between the two modes
		if (mainMenuChoice == 1) {
			// Roman to Arabic

			char roman[16]; // Roman input
			int arabic; // Arabic output
			int i; // Index variable

			system("cls"); // Clear the screen

			//Initialize
			arabic = 0;
			memset(roman, 0, sizeof roman);
			
			// Input the roman number
			cout << "Roman number: ";
			cin >> roman;

			// Loop through the roman char array
			for (i = 0; i <= 16; i++) {
				if (roman[i] == 'M') {
					// 1000
					arabic += 1000;
				}
				else if (roman[i] == 'D') {
					// 500
					arabic += 500;
				}
				else if (roman[i] == 'C') {
					// 100
					if (roman[i + 1] == 'M') {
						// 900
						arabic -= 100;
					}
					else if (roman[i + 1] == 'D') {
						// 400
						arabic -= 100;
					}
					else {
						// 100
						arabic += 100;
					}
				}
				else if (roman[i] == 'L') {
					// 50
					arabic += 50;
				}
				else if (roman[i] == 'X') {
					// 10
					if (roman[i + 1] == 'C') {
						// 90
						arabic -= 10;
					}
					else if (roman[i + 1] == 'L') {
						// 40
						arabic -= 10;
					}
					else {
						// 10
						arabic += 10;
					}
				}
				else if (roman[i] == 'V') {
					// 5
					arabic += 5;
				}
				else if (roman[i] == 'I') {
					// 1
					if (roman[i + 1] == 'X') {
						// 9
						arabic -= 1;
					}
					else if (roman[i + 1] == 'V') {
						// 4
						arabic -= 1;
					}
					else {
						// 1
						arabic += 1;
					}
				}
			}

			// Output the arabic number
			cout << "Your number is " << arabic << "." << endl;

			system("pause"); // Pause so reader can read output
		}
		else if (mainMenuChoice == 2) {
			// Arabic to Roman

			int arabic; // Arabic input
			char roman[20]; // Roman output
			char vbar[20]; // Char array for Vbar
			int i; // Counter variable
			int rc; // Roman counter

			// Variables for splitting up the arabic number
			int tenthou;
			int thou;
			int hun;
			int tens;
			int ones;

			system("cls"); // Clear the screen

			// Initialize variables
			memset(roman, 0, sizeof roman);
			memset(vbar, 0, sizeof vbar);
			rc = 0;

			// Input the arabic number
			cout << "Arabic number (0 for RNG): ";
			cin >> arabic;

			// RNG check
			if (arabic == 0) {
				srand((unsigned)time(NULL)); // Initialize RNG seed
				arabic = int((rand() % 39999) + 1);
				cout << arabic << endl;
			}

			// Split up arabic
			tenthou = arabic / 10000;
			thou = (arabic - (tenthou * 10000)) / 1000;
			hun = (arabic - ((tenthou * 10000) + (thou * 1000))) / 100;
			tens = (arabic - ((tenthou * 10000) + (thou * 1000) + (hun * 100))) / 10;
			ones = (arabic - ((tenthou * 10000) + (thou * 1000) + (hun * 100) + (tens * 10))) / 1;

			// Start looping through tenthou to add Xbar's
			for (i = 1; i <= tenthou; i++) { // Ten thousands
				roman[rc] = 'X';
				vbar[rc] = '_';
				rc++;
			}
			// Thousands
			if (thou >= 1 && thou <=3) { // 1000-3000
				for (i = 1; i <= thou; i++) {
					roman[rc] = 'M';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (thou == 4) { // 4000
				roman[rc] = 'M';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'V';
				vbar[rc] = '_';
				rc++;
			}
			else if (thou == 5) { // 5000
				roman[rc] = 'V';
				vbar[rc] = '_';
				rc++;
			}
			else if (thou >= 6 && thou <= 8) { // 6000-8000
				roman[rc] = 'V';
				vbar[rc] = '_';
				rc++;
				for (i = 6; i <= thou; i++) {
					roman[rc] = 'M';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (thou == 9) { // 9000
				roman[rc] = 'M';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'X';
				vbar[rc] = '_';
				rc++;
			}
			// Hundreds
			if (hun >= 1 && hun <= 3) { // 100-300
				for (i = 1; i <= hun; i++) {
					roman[rc] = 'C';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (hun == 4) { // 400
				roman[rc] = 'C';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'D';
				vbar[rc] = ' ';
				rc++;
			}
			else if (hun == 5) { // 500
				roman[rc] = 'D';
				vbar[rc] = ' ';
				rc++;
			}
			else if (hun >= 6 && hun <= 8) { // 600-800
				roman[rc] = 'D';
				vbar[rc] = ' ';
				rc++;
				for (i = 6; i <= hun; i++) {
					roman[rc] = 'C';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (hun == 9) { // 900
				roman[rc] = 'C';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'M';
				vbar[rc] = ' ';
				rc++;
			}
			// Tens
			if (tens >= 1 && tens <= 3) { // 10-30
				for (i = 1; i <= tens; i++) {
					roman[rc] = 'X';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (tens == 4) { // 40
				roman[rc] = 'X';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'L';
				vbar[rc] = ' ';
				rc++;
			}
			else if (tens == 5) { // 50
				roman[rc] = 'L';
				vbar[rc] = ' ';
				rc++;
			}
			else if (tens >= 6 && tens <= 8) { // 60-80
				roman[rc] = 'L';
				vbar[rc] = ' ';
				rc++;
				for (i = 6; i <= tens; i++) {
					roman[rc] = 'X';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (tens == 9) { // 90
				roman[rc] = 'X';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'C';
				vbar[rc] = ' ';
				rc++;
			}
			// Ones
			if (ones >= 1 && ones <= 3) { // 1-3
				for (i = 1; i <= ones; i++) {
					roman[rc] = 'I';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (ones == 4) { // 4
				roman[rc] = 'I';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'V';
				vbar[rc] = ' ';
				rc++;
			}
			else if (ones == 5) { // 5
				roman[rc] = 'V';
				vbar[rc] = ' ';
				rc++;
			}
			else if (ones >= 6 && ones <= 8) { // 6-8
				roman[rc] = 'V';
				vbar[rc] = ' ';
				rc++;
				for (i = 6; i <= ones; i++) {
					roman[rc] = 'I';
					vbar[rc] = ' ';
					rc++;
				}
			}
			else if (ones == 9) { // 9
				roman[rc] = 'I';
				vbar[rc] = ' ';
				rc++;
				roman[rc] = 'X';
				vbar[rc] = ' ';
				rc++;
			}
			// Output the roman number
			cout << "Roman number:" << endl << vbar << endl << roman << endl;

			system("pause"); // Pause so user can read output
		}
	} while (mainMenuChoice != 0);
	return 0;
}