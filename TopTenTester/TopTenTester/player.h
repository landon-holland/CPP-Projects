// player.h
// Landon Holland - 4/17/2019

#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <sstream>

using namespace std;

class player {
private:
	// data
	string myName;
	int myScore;
public:
	player(); // default constructor
	player(string name, int score); // fill constructor

	// member functions
	string getName();
	void setName(string name);
	int getScore();
	void setScore(int score);

	string toString(); // Convert player to string
};

player::player() {
	myName = '';
	myScore = 0;
}

player::player(string name, int score) {
	myName = name;
	myScore = score;
}

string player::getName() {
	return myName;
}

void player::setName(string name) {
	myName = name;
}

int player::getScore() {
	return myScore;
}

void player::setScore(int score) {
	myScore = score;
}

string player::toString() {
	stringstream sout;

	sout << myName << " - " << myScore;
	return sout.str();
}

#endif // !_PLAYER_H
