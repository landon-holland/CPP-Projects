// CrazyEights.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 3/22/2019
// Crazy Eights game using lots of structures!

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "randgen.h"

using namespace std;

struct card {
	int val; // 8 = wild, q = draw 2, king = draw 4
	int suit; // 3-6 are suits (h, d, c, s)
};

struct deck {
	card arrcards[52];
	int numcards;
};

struct player {
	string name;
	unsigned int score;
};

string getCardString(card c);
string getASCIICard(card c);
string getDeckString(deck d);
string getPlayerString(player p);
string getGameString(deck h, deck d, deck dh, int prevturn);
void FillDeck(deck &d);
void InitDraw(deck &d, deck &draw);
void FixHand(deck &h);
card FillCard(int val, int suit);
void DestroyCard(card &c);
void ShuffleDeck(deck &d);
void DrawCards(deck &h, deck &d, int numdraw, deck &di);
bool TestPlacement(card p, card a);
void PlaceCards(deck &h, deck &d, int cardnum, bool ai, deck &eh, deck &dr, int &prevturn);
void Wild(deck &d, bool ai);
bool TestWin(deck d);
void Reshuffle(deck &dr, deck &di);
void GetPlayerInfo(player &p);

int main()
{
	char Ans;
	do
	{
		deck PlayerHand, DealerHand, Discard, Draw;
		player Player1;
		bool EndGame, AICardPlayed;
		int CardNum;
		int i;
		int PrevTurn = 0; // Helps the game string function tell the user what happened to them on the previous turn. 0 = nothing, 1 = they drew, 2 = you drew 2, 3 = you drew 4, 4 = you were skipped, 5 = you skipped them, 6 = wild
		int WhoWon; // Who won?

		// Get player's name and hopefully fill in his score and eventually save it
		GetPlayerInfo(Player1);

		// Make the master deck, we will draw the dealer and player's hands from this deck
		FillDeck(Draw);
		ShuffleDeck(Draw);

		// Fill the dealer hand and player hand
		DrawCards(PlayerHand, Draw, 7, Discard);
		DrawCards(DealerHand, Draw, 7, Discard);

		// Move the latest card from Draw to Discard so that we know the first card that we're playing with
		InitDraw(Discard, Draw);

		// Do while test to play the game until somebody wins
		EndGame = false; //probably a temp variable
		do {
			//system("cls"); // Since we're looping a lot, we start off with clearing the screen

			cout << getGameString(PlayerHand, Discard, DealerHand, PrevTurn); // This will display the deck with the active card

			if (PrevTurn != 4) { // If ai skipped, then we don't run this code
				bool FirstTestLoop = true; // So that the error message can know when to come up
				// We have to do another do while just incase the card they chose to play is illegal
				do {
					// If the previous loop iteration didn't work, then we're gonna give a friendly reminder to choose a valid card
					if (FirstTestLoop == false) {
						cout << endl << "Invalid card." << endl;
					}

					FirstTestLoop = false; // We are no longer virgins

					// Now we're gonna ask for what card to place
					cout << endl << "What card would you like to place? ";
					cin >> CardNum;
					CardNum--; // Because we count from 0
					if (CardNum == -1) { // If they input 0, then we know what to do, so we just skrt from the loop
						break;
					}
				} while (TestPlacement(PlayerHand.arrcards[CardNum], Discard.arrcards[Discard.numcards]) == false);

				if (CardNum == -1) {
					// So now we have to draw, instead of placing a card, this will naturally skip the turn
					DrawCards(PlayerHand, Draw, 0, Discard);
				}
				else {
					// Now we should have a valid card to place in CardNum, so lets use the function to place it
					PlaceCards(PlayerHand, Discard, CardNum, false, DealerHand, Draw, PrevTurn);
				}

				if (TestWin(PlayerHand)) { // We're going to check if we won the game.
					EndGame = true;
					WhoWon = 0;
					break; // This will skip the AI's turn, we won so it doesn't matter.
				}

			}

			if (PrevTurn != 5) { // test for skip
				// Now it's the AI's turn
				// Let's loop through every card in DealerHand and then once we find one that works, we'll just place #goodai
				AICardPlayed = false;
				for (i = 0; i <= DealerHand.numcards; i++) {
					if (TestPlacement(DealerHand.arrcards[i], Discard.arrcards[Discard.numcards])) { // If we can place it..
						PlaceCards(DealerHand, Discard, i, true, PlayerHand, Draw, PrevTurn);
						AICardPlayed = true; // They placed something so we don't need to draw one
						break; // Kill the loop
					}
				}

				if (AICardPlayed == false) {
					DrawCards(DealerHand, Draw, 0, Discard); // Draw
					PrevTurn = 1;
				}

				if (TestWin(DealerHand)) { // Did the dealer win?
					EndGame = true;
					WhoWon = 1;
				}
			}
		} while (EndGame == false);

		// Now we're out of the game
		if (WhoWon == 0) {
			cout << endl << "You won!!!!!!" << endl;
		}
		else {
			cout << endl << "You lost!!!!!!" << endl;
		}

		// Ask for looping
		cout << endl << "Play Again? [Y/n] ";
		cin >> Ans;
	} while (Ans == 'Y' || Ans == 'y');
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

string getASCIICard(card c)
{
	stringstream sout;

	sout << setw(8) << setfill('-') << ' ' << endl;
	sout << setw(1) << '|' << setw(5) << setfill(' ') << getCardString(c) << setw(1) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(1) << '|' << setw(6) << '|' << endl;
	sout << setw(8) << setfill('-') << ' ' << endl;

	return sout.str();
}

string getDeckString(deck d)
{
	stringstream sout;

	// Loop the getCardString for every card in the deck
	sout << d.numcards << endl;
	for (int i = 0; i <= d.numcards; i++) {
		sout << getCardString(d.arrcards[i]) << endl;
	}

	return sout.str();
}

string getPlayerString(player p)
{
	stringstream sout;

	sout << p.name << " - " << p.score;

	return sout.str();
}

string getGameString(deck h, deck d, deck dh, int prevturn)
{
	stringstream sout;

	// Display your deck
	sout << "Your deck:" << endl;
	for (int i = 0; i <= h.numcards; i++) {
		sout << i + 1 << ": " << getCardString(h.arrcards[i]) << endl;
	}

	// Display what happened the previous turn. 0 = nothing, 1 = they drew, 2 = you drew 1, 3 = you drew 2, 4 = you were skipped, 5 = you skipped them, 6 = wild
	switch (prevturn) {
	case 1:
		sout << endl << "The Dealer drew a card." << endl;
		break;
	case 2:
		sout << endl << "You were forced to draw 2." << endl;
		break;
	case 3:
		sout << endl << "You were forced to draw 4." << endl;
		break;
	case 4:
		sout << endl << "You were skipped." << endl;
		break;
	case 5:
		sout << endl << "You skipped the Dealer." << endl;
		break;
	case 6:
		sout << endl << "A wild card was placed." << endl;
		break;
	}

	// Display the top card of the pile
	sout << endl << "Active card: " << endl << getASCIICard(d.arrcards[d.numcards]) << endl;

	// Display number of cards in the enemy's deck
	sout << endl << "The Dealer has " << dh.numcards + 1 << " card(s) in his hand." << endl;

	// Display information to draw a card by inputting 0
	sout << endl << "Draw a card by entering 0." << endl;

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

	// Set number of cards to 52
	d.numcards = 51;
}

void InitDraw(deck &d, deck &draw)
{
	// Set the first card out before the game
	int i;
	for (i = 0; i <= 51; i++) {
		d.arrcards[i] = FillCard(0, 0);
	}
	d.numcards = 0;

	d.arrcards[0] = draw.arrcards[draw.numcards];
	DestroyCard(draw.arrcards[draw.numcards]);
	draw.numcards--;
}

void FixHand(deck &h)
{
	for (int i = 0; i <= h.numcards; i++) { // Loop through the hand
		if (h.arrcards[i].suit == 0 && h.arrcards[i].val == 0) { // If the card is destroyed then we need to move everything after this up one
			for (int j = i; j <= h.numcards - 1; j++) {
				h.arrcards[j] = h.arrcards[j + 1]; // Shift the things
			}
			h.numcards--; // We lost a card boys
			break; // Now we skrt from the loop
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

void DestroyCard(card &c)
{
	c.suit = 0;
	c.val = 0;
}

void ShuffleDeck(deck &d)
{
	RandGen r;
	card tempcard;
	int i, rnum;

	for (i = 0; i <= d.numcards; i++) {
		// Randomly generate an index and swap
		rnum = r.RandInt(0, d.numcards);
		tempcard = d.arrcards[i];
		d.arrcards[i] = d.arrcards[rnum];
		d.arrcards[rnum] = tempcard;
	}
}

void DrawCards(deck &h, deck &d, int numdraw, deck &di)
{
	// General function to completely fill a hand from the Draw deck when a card is played or right from the beginning
	if (numdraw == 7) { // If the function is called to draw 7 cards then that means we are intializing these hands
		for (h.numcards = 0; h.numcards <= 6; h.numcards++) {
			h.arrcards[h.numcards] = d.arrcards[d.numcards];
			DestroyCard(d.arrcards[d.numcards]);
			d.numcards--;
		}
		h.numcards--;
	}
	else if (numdraw == 0) {
		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);
	}
	else if (numdraw == 1) {
		// i think we're just going to do seperate if tests for 1, 2, and 7 to make it easier for me
		// We don't need a for loop because it's just one card
		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);

		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);
	}
	else {
		// draw 2
		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);

		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);

		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);

		h.arrcards[h.numcards + 1] = d.arrcards[d.numcards];
		DestroyCard(d.arrcards[d.numcards]);
		d.numcards--;
		h.numcards++;
		Reshuffle(d, di);
	}
}

bool TestPlacement(card p, card a)
{
	// If the suit matches or the val matches, then we return true. Otherwise, false.
	bool legal;
	if (p.suit == a.suit) {
		legal = true;
	}
	else if (p.val == a.val) {
		legal = true;
	}
	else if (p.val == 8) {
		legal = true;
	}
	else {
		legal = false;
	}

	return legal;
}

void PlaceCards(deck &h, deck &d, int cardnum, bool ai, deck &eh, deck &dr, int &prevturn)
{
	// First we add the card to the discard at the latest position
	d.arrcards[d.numcards + 1] = h.arrcards[cardnum];
	d.numcards++;

	DestroyCard(h.arrcards[cardnum]); // We're gonna destroy the card so FixHand knows how to fix the deck

	// Now we need to shift the player hand so that it fills from 0-numcard
	FixHand(h);

	// Now we're going to figure out what's up with special cards
	switch (d.arrcards[d.numcards].val) { // Instead of looking at the hand we're going to look at the discard deck
	case 8:
		// wild
		Wild(dr, ai);
		prevturn = 6;
		break;
	case 11:
		// skip
		if (ai == true) {
			prevturn = 4;
		}
		else {
			prevturn = 5;
		}
		break;
	case 12:
		// draw 1
		DrawCards(eh, dr, 1, d);
		if (ai == true) {
			prevturn = 2;
		}
		else {
			prevturn = 0;
		}
		break;
	case 13:
		// draw 2
		DrawCards(eh, dr, 2, d);
		if (ai == true) {
			prevturn = 3;
		}
		else {
			prevturn = 0;
		}
		break;
	default:
		prevturn = 0;
		break;
	}
}

void Wild(deck &d, bool ai)
{
	int newsuit;
	RandGen r;

	if (ai == false) {
		cout << endl << "Which suit would you like to change the play to?" << endl;
		cout << endl << "1 - Hearts" << endl << "2 - Diamonds" << endl << "3 - Clubs" << endl << "4 - Spades" << endl;
		cout << endl << "Suit: ";
		cin >> newsuit;
		newsuit += 2; // This makes sure it is in the correct form
	}
	else {
		newsuit = r.RandInt(3, 6);
	}

	// Now we're going to just set the latest card to newsuit
	d.arrcards[d.numcards].suit = newsuit;
}

bool TestWin(deck d)
{
	if (d.numcards == -1) {
		return true;
	}
	else {
		return false;
	}
}

void Reshuffle(deck &dr, deck &di)
{
	// First we gotta check if we even need to do this
	if (dr.numcards == -1) {
		system("pause");
		// first we just turn the discard deck into the draw deck
		//dr = di;
		for (int i = 0; i <= di.numcards; i++) {
			dr.arrcards[i] = di.arrcards[i];
		}
		dr.numcards = di.numcards;

		// we're gonna shuffle our new deck so that the cards aren't in a predictable order
		ShuffleDeck(dr);

		// we need to make sure we keep one card left over
		InitDraw(di, dr);
	}
}

void GetPlayerInfo(player &p)
{
	system("cls"); // Assume that there is something already on the screen just in case

	cout << "Welcome to Crazy Eights!" << endl;
	cout << "Please enter your name: ";
	cin >> p.name;

	// Code for reading files and matching the score with the name....
}