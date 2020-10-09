// Checkbook.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 3/7/2019
// Use structures and functions to manage checking account

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string>
#include <sstream>

using namespace std;

struct service {
	char TransactionCode; // C = -Check, D = +Deposit, E = Exit, S = -ServiceCharge, X = Clear, A = ATM
	float Amount;
};

struct checkbook {
	service history[19];
	float bbalance;
	float balance;
	float checks;
	float atm;
	float deposits;
	float withdrawals;
	int transactions;
	int ndeposits;
	int nwithdrawals;
};

void GetInfo(checkbook &Input);
string GetHistory(checkbook &CBOutput);
string GetSummary(checkbook CBOutput);

int main()
{
	char LoopAns;
	do {
		checkbook Checkbook;

		system("cls"); // Clear the screen

		GetInfo(Checkbook);

		cout << GetHistory(Checkbook);

		cout << GetSummary(Checkbook);

		cout << endl << "Run Again [Y/n] ";
		cin >> LoopAns;
	} while (LoopAns == 'Y' || LoopAns == 'y');
	return 0;
}

void GetInfo(checkbook &Input)
{
	int i;
	i = 0;

	cout << "Welcome to landoserver: Bank!" << endl;
	cout << "Balance: ";
	cin >> Input.balance;
	Input.bbalance = Input.balance;

	do {
		cout << "Transaction: ";
		cin >> Input.history[i].TransactionCode;
		
		if (Input.history[i].TransactionCode == 'E') {
			Input.history[i].TransactionCode = 'S';
			Input.history[i].Amount = 5.00;
			i++;
			Input.history[i].TransactionCode = 'E';
			Input.history[i].Amount = 0.00;
			Input.transactions = i;
			break;
		}
		else if (Input.history[i].TransactionCode == 'X') {
			i = 0;
			system("cls"); // Clear the screen and get a new balance
			cout << "Welcome to landoserver: Bank!" << endl;
			cout << "Balance: ";
			cin >> Input.balance;
			Input.bbalance = Input.balance;
		}
		else {
			cout << "Amount: ";
			cin >> Input.history[i].Amount;
			i++;
		}
	} while (true);
}

string GetHistory(checkbook &CBOutput)
{
	stringstream sout;
	float insufficient;
	int itransactions;
	int i;

	// Set main flags for the stringstream
	sout << setiosflags(ios::fixed | ios::showpoint | ios::left) << setprecision(2) << setfill(' ') << endl;

	// Headers
	sout << setw(30) << "Transaction" << setw(8) << setiosflags(ios::right) << "Amount" << setw(15) << "Balance" << endl;
	// Beginning balance
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Beginning Balance" << setiosflags(ios::right) << setw(8) << CBOutput.balance << setw(15) << CBOutput.balance << endl;
	
	// Start parsing the history array and getting totals
	CBOutput.deposits = 0;
	CBOutput.checks = 0;
	CBOutput.atm = 0;
	CBOutput.withdrawals = 0;
	itransactions = 0;
	CBOutput.ndeposits = 0;
	CBOutput.nwithdrawals = 0;
	for (i = 0; i <= CBOutput.transactions; i++) {
		if (CBOutput.history[i].TransactionCode == 'D') {
			CBOutput.deposits += CBOutput.history[i].Amount;
			CBOutput.ndeposits++;
		}
		else if (CBOutput.history[i].TransactionCode == 'C' || CBOutput.history[i].TransactionCode == 'A') {
			if (CBOutput.history[i].Amount > (CBOutput.balance + CBOutput.deposits - CBOutput.checks)) { // If we are trying to take more money out than we have. Don't do it and add to the illegal transactions
				itransactions++;
				CBOutput.nwithdrawals++;
			}
			else {
				if (CBOutput.history[i].TransactionCode == 'C') {
					CBOutput.checks += CBOutput.history[i].Amount;
				}
				else if (CBOutput.history[i].TransactionCode == 'A') {
					CBOutput.atm += CBOutput.history[i].Amount;
				}
				CBOutput.nwithdrawals++;
			}
		}
	}
	
	// Checks
	CBOutput.balance -= CBOutput.checks;
	CBOutput.withdrawals += CBOutput.checks;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Check" << setiosflags(ios::right) << setw(8) << CBOutput.checks << setw(15) << CBOutput.balance << endl;

	// ATM Withdrawal
	CBOutput.balance -= CBOutput.atm;
	CBOutput.withdrawals += CBOutput.atm;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "ATM Withdrawal" << setiosflags(ios::right) << setw(8) << CBOutput.atm << setw(15) << CBOutput.balance << endl;

	// Deposits
	CBOutput.balance += CBOutput.deposits;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Deposit" << setiosflags(ios::right) << setw(8) << CBOutput.deposits << setw(15) << CBOutput.balance << endl;

	// Insufficient funds
	insufficient = 10.00 * itransactions;
	CBOutput.balance -= insufficient;
	CBOutput.withdrawals += insufficient;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Insufficient Funds" << setiosflags(ios::right) << setw(8) << insufficient << setw(15) << CBOutput.balance << endl;

	// Illegal Transaction COde
	sout << "Illegal Transaction Code" << endl;

	// Service charge
	CBOutput.balance -= 5.00;
	CBOutput.nwithdrawals++;
	CBOutput.withdrawals += 5.00;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Service Charge" << setiosflags(ios::right) << setw(8) << 5.00 << setw(15) << CBOutput.balance << endl;

	// Line
	sout << setw(54) << setfill('=') << ' ' << endl;

	return sout.str();
}

string GetSummary(checkbook CBOutput)
{
	stringstream sout;

	sout << setiosflags(ios::fixed | ios::showpoint | ios::right) << setprecision(2) << setfill(' ');
	
	sout << "Account Summary" << endl;
	sout << setw(30) << ' ' << setw(8) << "Number" << setw(15) << "Amount" << endl;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Beginning Balance" << setiosflags(ios::right) << setw(8) << ' ' << setw(15) << CBOutput.bbalance << endl;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Plus Deposits" << setiosflags(ios::right) << setw(8) << CBOutput.ndeposits << setw(15) << CBOutput.deposits << endl;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Less Withdrawals" << setiosflags(ios::right) << setw(8) << CBOutput.nwithdrawals << setw(15) << CBOutput.withdrawals << endl;
	sout << resetiosflags(ios::adjustfield) << setiosflags(ios::left) << setw(30) << "Ending Balance" << setiosflags(ios::right) << setw(8) << ' ' << setw(15) << CBOutput.balance << endl;
	sout << setw(54) << setfill('=') << ' ' << endl;

	return sout.str();
}