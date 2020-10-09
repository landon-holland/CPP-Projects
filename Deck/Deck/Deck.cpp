// Deck.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 3/20/2019
// Structures for a card and a deck and functions to shuffle

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "randgen.h"

using namespace std;

struct card {
	int val;
	int suit; // 3-6 are suits (h, d, c, s)
};

struct deck {
	card arrcards[52];
};

string getCardString(card c);
string getDeckString(deck d);
void FillDeck(deck &d);
card FillCard(int val, int suit);
void ShuffleDeck(deck &d);

int main()
{
	deck d;

	FillDeck(d);
	cout << getDeckString(d) << endl;

	system("pause");

	ShuffleDeck(d);
	cout << getDeckString(d) << endl;

	system("pause");
}

string getCardString(card c)
{
	string outputString;

	// Convert the value to actual value (Ace, or Jack, etc)
	switch (c.val) {
	case 1:
		outputString = 'A';
		break;
	case 10:
		outputString = "10";
		break;
	case 11:
		outputString = 'J';
		break;
	case 12:
		outputString = 'Q';
		break;
	case 13:
		outputString = 'K';
		break;
	default:
		outputString = c.val + 48;
		break;
	}

	// Convert the numbers to the symbol in Raster Fonts
	outputString += char(c.suit);

	return outputString;
}

string getDeckString(deck d)
{
	stringstream sout;

	// Loop the getCardString for every card in the deck
	for (int i = 0; i <= 51; i++) {
		sout << getCardString(d.arrcards[i]) << endl;
	}

	return sout.str();
}

void FillDeck(deck &d)
{
	int i, j, k;

	k = 0;

	// Two loops: one for the val, one for the suit
	for (i = 3; i <= 6; i++) { // suit
		for (j = 1; j <= 13; j++) { // val
			d.arrcards[k] = FillCard(j, i);
			k++;
		}
	}
}

card FillCard(int val, int suit)
{
	// Make a card and use the passed parameters to return the card with the filled values
	card c;
	c.val = val;
	c.suit = suit;

	return c;
}


void ShuffleDeck(deck &d)
{
	RandGen r;
	card tempcard;
	int i, rnum;

	for (i = 0; i <= 51; i++) {
		// Randomly generate an index and swap
		rnum = r.RandInt(52);
		tempcard = d.arrcards[i];
		d.arrcards[i] = d.arrcards[rnum];
		d.arrcards[rnum] = tempcard;
	}
}