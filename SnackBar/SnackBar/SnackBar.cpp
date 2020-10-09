// SnackBar.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 3/4/2019
// 

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void DispMenu(float rt);
void GetInfo(char &c);
void AddItem(float &rt, char &ic);
void DispTotal(float rt);

int main()
{
	char LoopAns; // Answer for "Run Again"
	do {
		float RunningTotal;
		char MenuChoice;

		RunningTotal = 0.00; // Initialize this variable

		do {
			DispMenu(RunningTotal);
			GetInfo(MenuChoice);
			if (MenuChoice == 'X' || MenuChoice == 'x') {
				RunningTotal = 0.00; // Reset the sale
			}
			else if (MenuChoice == 'T' || MenuChoice == 't') {
				DispTotal(RunningTotal);
				break;
			}
			else {
				AddItem(RunningTotal, MenuChoice);
			}
		} while (true);

		// Ask user if they want to run again
		cout << "Run Again? [Y/n] ";
		cin >> LoopAns;
	} while (LoopAns == 'Y' || LoopAns == 'y');
	return 0;
}

void DispMenu(float rt)
{
	system("cls"); // We redisplay the menu, so we clear the screen to remove clutter.
	cout << setiosflags(ios::fixed | ios::showpoint | ios::left) << setprecision(2);
	cout << setw(25) << "Current Total" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << rt << endl; // Running total
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "S - Sandwich" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << 2.50 << endl; // Sandwich - 2.50
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "C - Chips" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << 0.75 << endl; // Chips - 0.75
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "B - Brownies" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << 1.00 << endl; // Brownies - 1.00
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "R - Regular Drink" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << 1.00 << endl; // Regular Drink - 1.00
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "L - Large Drink" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << 1.50 << endl; // Large Drink - 1.50
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "X - Cancel order and restart" << endl;
	cout << setw(25) << "T - Total the sale" << endl;
	cout << "Choice: ";
}

void GetInfo(char &c)
{
	cin >> c;
}

void AddItem(float &rt, char &ic)
{
	// Add totals for the menu items
	if (ic == 'S' || ic == 's') {
		rt += 2.50;
	}
	else if (ic == 'C' || ic == 'c') {
		rt += 0.75;
	}
	else if (ic == 'B' || ic == 'b' || ic == 'R' || ic == 'r') {
		rt += 1.00;
	}
	else if (ic == 'L' || ic == 'l') {
		rt += 1.50;
	}
}

void DispTotal(float rt)
{
	const float SALES_TAX = 0.07;
	float tax, total;

	tax = rt * SALES_TAX;
	total = tax + rt;

	cout << endl;
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Subtotal" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << rt << endl; // Subtotal
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Tax" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << tax << endl; // Tax
	cout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(25) << "Total" << setw(5) << setiosflags(ios::right) << '$' << setw(5) << total << endl; // Total
}