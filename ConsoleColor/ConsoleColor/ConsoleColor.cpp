// ConsoleColor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	for(int k = 0; k < 255; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cout << k << " Color is this" << endl;
	};
	system("pause");
}