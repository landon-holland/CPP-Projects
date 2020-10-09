// topten.h
// Landon Holland - 4/17/2019

#pragma once
#ifndef _TOPTEN_H
#define _TOPTEN_H

#include <string>
#include <sstream>
#include <fstream>
#include "player.h"

using namespace std;

class topten {
private:
	// data
	player myPlayers[101];
	int myPlayerCount;
	string myPath;

public:
	topten(); //default constructor
	topten(string path); // fill constructor

	// member functions
	int getPlayerCount();
	void setPlayerCount(int pc);
	string getPath();
	void setPath(string pc);
	player getPlayer(string name); // returns player by name
	void setPlayer(player p); // set player by name inside of player
	void addPlayer(player p);

	void sortPlayers();
	string toString();
	void savePlayers();
};

topten::topten() {
	myPlayerCount = -1;
	myPath = '';
}

topten::topten(string path) {
	ifstream txt(path);
	string line;
	int tscore;

	if (txt.is_open()) {
		txt >> myPlayerCount; // first thing in file is the playercount
		txt.ignore(); // necessary after every input

		// loop through players with playercount
		for (int i = 0; i <= myPlayerCount; i++) {
			getline(txt, line);
			myPlayers[i].setName(line); // name
			txt >> tscore;
			txt.ignore();
			myPlayers[i].setScore(tscore); // score
		}
		txt.close();
	}
}

#endif // !_TOPTEN_H
