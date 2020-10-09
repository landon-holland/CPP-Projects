// Jotto.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Landon Holland - 4/9/2019
// Word guessing game

#include "pch.h"
#include "randgen.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Player {
	string name;
	unsigned int score;
	int guesses;
};

struct Jotto {
	string words[3038];
	string jword;
	int jots;

	Player players[101];
	int playercount;
};

void getPlayerInfo(Player &p);
void fillPlayers(string path, int &pc, Player ps[]);
void savePlayers(string path, int pc, Player ps[]);
void addPlayer(Player cp, int &pc, Player ps[]);
void initPlayer(Player &p);
string getTopTen(Player ps[], int pc);
void fillJotto(string path, string w[]);
string getWordString(string w);
string getPlayerString(Player p);
string getRWord(string w[]);
int findJots(string j, string g);
int getScore(int g);
bool checkWinner(string j, string g);

int main()
{
	char Ans;
	do {
		Jotto j;
		string guess;
		Player CurrentPlayer;

		fillJotto("jotto.txt", j.words); // Populate the jotto array from the file using the function
		fillPlayers("players.txt", j.playercount, j.players); // Populate player array

		// Get a random word that the user has to guess
		j.jword = getRWord(j.words);
		// Initialize the score and guesses with a function
		initPlayer(CurrentPlayer);

		do {
			cout << j.jword << endl;
			cout << "Guess: ";
			cin >> guess;

			cout << "Jots: " << findJots(j.jword, guess) << endl;

			CurrentPlayer.guesses++;
		} while (checkWinner(j.jword, guess) == false);

		// Winner code
		getPlayerInfo(CurrentPlayer);
		CurrentPlayer.score = getScore(CurrentPlayer.guesses);

		// Now we add this current player to the array of players
		addPlayer(CurrentPlayer, j.playercount, j.players);

		// Now we save it to the txt file
		savePlayers("players.txt", j.playercount, j.players);

		// Now lets display the top ten
		system("cls");
		cout << getTopTen(j.players, j.playercount) << endl;

		// Loop code for running the program again
		cout << endl << "Run Again? [Y/n] ";
		cin >> Ans;
	} while (Ans == 'Y' || Ans == 'y');
}

void getPlayerInfo(Player &p)
{
	cout << "Name: ";
	cin >> p.name;
}

void fillPlayers(string path, int &pc, Player ps[])
{
	int i;
	ifstream playertxt(path);

	if (playertxt.is_open()) {
		playertxt >> pc; // First we get the player count; it's the first line in the file
		playertxt.ignore(); // necessary before getline
		for (i = 0; i <= pc; i++) {
			getline(playertxt, ps[i].name); // get the name of the person
			playertxt >> ps[i].score; // then the score
			playertxt.ignore(); // ignore again
		}
		playertxt.close();
	}
	else {
		cout << "Error." << endl;
	}
}

void savePlayers(string path, int pc, Player ps[])
{
	int i;
	ofstream playertxt(path);

	if (playertxt.is_open()) {
		playertxt << pc << endl; // First it's the playercount

		for (i = 0; i <= pc; i++) {
			playertxt << ps[i].name << endl << ps[i].score << endl;
		}

		playertxt.close();
	}
	else {
		cout << "Error." << endl;
	}
}

void addPlayer(Player cp, int &pc, Player ps[])
{
	pc++; //new player

	ps[pc] = cp; // Now we set the new array to the current player
}

void initPlayer(Player &p)
{
	p.score = 0;
	p.guesses = 0;
}

string getTopTen(Player ps[], int pc)
{
	stringstream sout;
	Player sp[101];
	Player temp;
	int tc;
	int i, j;

	// transfer the player array to a new temp one
	for (i = 0; i <= pc; i++) {
		sp[i] = ps[i];
	}

	// exchange sort
	for (i = 0; i < pc - 1; i++) {
		for (j = i + 1; j < pc; j++) {
			if (sp[i].score < sp[j].score) {
				temp = sp[i];
				sp[i] = sp[j];
				sp[j] = temp;
			}
		}
	}

	for (i = 0; i < pc - 1; i++) {
		for (j = i + 1; j < pc; j++) {
			if (sp[i].score < sp[j].score) {
				temp = sp[i];
				sp[i] = sp[j];
				sp[j] = temp;
			}
		}
	}

	if (pc <= 9) {
		tc = pc;
	}
	else {
		tc = 9;
	}

	for (i = 0; i <= tc; i++) {
		sout << setw(2) << i + 1 << setw(15) << sp[i].name << setw(5) << sp[i].score << endl;
	}

	return sout.str();
}

void fillJotto(string path, string w[]) {
	string line;
	int i;
	ifstream jottotxt(path);

	i = 0;

	// This is the loop that adds to the Jotto array
	if (jottotxt.is_open()) {
		while (getline(jottotxt, line)) {
			w[i] = line;
			i++;
		}
		jottotxt.close();
	}
	else {
		cout << "Error." << endl;
	}
}

string getWordString(string w)
{
	stringstream sout;

	for (int i = 0; i <= 4; i++) {
		sout << w[i] << ' ';
	}
	return sout.str();
}

string getPlayerString(Player p)
{
	stringstream sout;

	sout << p.name << ": " << p.score;
	return sout.str();
}

string getRWord(string w[])
{
	RandGen r;

	return w[r.RandInt(0, 3036)];
}

int findJots(string j, string g)
{
	int jots;
	bool matches[5];
	int i, k;

	// Initialize this array which helps with checking for jots properly
	for (i = 0; i <= 4; i++) {
		matches[i] = false;
	}
	jots = 0; // Initialize jots

	for (i = 0; i <= 4; i++) {
		for (k = 0; k <= 4; k++) {
			if (g[i] == j[k] && matches[k] == false) {
				matches[k] = true;
				jots++;
				break;
			}
		}
	}

	return jots;
}

int getScore(int g)
{
	return 10000 - (g * 100);
}

bool checkWinner(string j, string g)
{
	if (j == g) {
		return true;
	}
	else {
		return false;
	}
}