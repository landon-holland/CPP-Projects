// RNGCharArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 2/6/2019
// Output a character array of 7 random characters

#include "pch.h"
#include <iostream>
#include <time.h> // Needed for RNG
using namespace std;

int main()
{
	char rngletters[8]; // Declare the character array with the random letters. 7 letters but 1 more with null terminator.
	int i; // Index variable for loop

	srand((unsigned)time(NULL)); // Initialize RNG seed

	for (i = 0; i <= 6; i++) // Loop for 7 times to fill array
	{
		rngletters[i] = int((rand() % (90 - 66)) + 65); // Set array to random ascii value
	}

	rngletters[7] = '\0';

	cout << rngletters << endl; // Output character array

	system("pause"); // Pause so user can read output

	return 0;
}