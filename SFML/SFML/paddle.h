// paddle.h - paddle to hit the ball in pong
// Landon Holland - 3/17/2019

#pragma once
#ifndef _PADDLE_H
#define _PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "pch.h"
#include "ball.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace sf;

class paddle {
public:
	paddle(); // default constructor
	paddle(Vector2f position, Color c, int dir, float v, Font f); // fill constructor

	void setRectangle(RectangleShape r);
	RectangleShape getRectangle();

	void setColor(Color c);
	Color getColor();

	void setDir(int dir);
	int getDir();

	void setVelocity(float v);
	float getVelocity();

	void setScore(int s);
	int getScore();
	void plusScore();

	void setScoreText(Text st);
	Text getScoreText();

	void update(RenderWindow &w, Event e, float dt, int ct, ball &b);

private:
	RectangleShape myRectangle;
	Color myCol;
	int myDir;
	float myV;
	int myScore;
	Text myScoreText;
	SoundBuffer buffer;
	Sound sound;
};

paddle::paddle() {
	myCol = Color::Green;

	myRectangle.setSize(Vector2f(25, 100));
	myRectangle.setFillColor(myCol);
	myRectangle.setPosition(Vector2f(100, 1000));

	myScore = 0;

	myScoreText.setString("");
	myScoreText.setFont(Font());
	myScoreText.setFillColor(myCol);
	myScoreText.setPosition(Vector2f(0, 0));
	myScoreText.setCharacterSize(30);
}

paddle::paddle(Vector2f position, Color c, int dir, float v, Font f) {
	myCol = c;

	myRectangle.setSize(Vector2f(25, 100));
	myRectangle.setFillColor(myCol);
	myRectangle.setPosition(position);

	myDir = dir;

	myV = v;

	myScore = 0;

	myScoreText.setString(std::to_string(myScore));
	myScoreText.setFont(f);
	myScoreText.setFillColor(myCol);
	myScoreText.setPosition(Vector2f(position.x + 200, position.y));
	myScoreText.setCharacterSize(30);
}

void paddle::setRectangle(RectangleShape r) {
	myRectangle = r;
}

RectangleShape paddle::getRectangle() {
	return myRectangle;
}

void paddle::setColor(Color c) {
	myCol = c;
}

Color paddle::getColor() {
	return myCol;
}

void paddle::setDir(int dir) {
	myDir = dir;
}

int paddle::getDir() {
	return myDir;
}

void paddle::setVelocity(float v) {
	myV = v;
}

float paddle::getVelocity() {
	return myV;
}

void paddle::setScore(int s) {
	myScore = s;
}

int paddle::getScore() {
	return myScore;
}

void paddle::plusScore() {
	myScore++;
}

void paddle::setScoreText(Text st) {
	myScoreText = st;
}

Text paddle::getScoreText() {
	return myScoreText;
}

void paddle::update(RenderWindow &w, Event e, float dt, int ct, ball &b) {
	int upk, dwk;


	// We need to check what control scheme they want to use, maybe ai too.
	// different stuff for ai or regular
	if (ct == 0) { // ai
		
		// collision code but reversed for ai
		if (b.getCircle().getPosition().y + (b.getCircle().getRadius() * 2) >= myRectangle.getPosition().y && b.getCircle().getPosition().y && myRectangle.getPosition().y + myRectangle.getSize().y
			&& b.getCircle().getPosition().x + (b.getCircle().getRadius() * 2) >= myRectangle.getPosition().x && b.getDir().x == 1) {

			buffer.loadFromFile("Beep1.wav");
			sound.setBuffer(buffer);
			sound.play();

			b.setDir(Vector2f(b.getDir().x * -1, b.getDir().y));
			std::cout << "a" << std::endl;
		}

		// animation code - we're just going to match whatever the y coordinate of the ball is lol
		// actually, we'll make it so that it might actually be beatable

		// if the ball is above it, then move the paddle up, if otherwise, then move it down
		if (b.getCircle().getPosition().y + b.getCircle().getRadius() > myRectangle.getPosition().y + (myRectangle.getSize().y / 2)) {
			myDir = 1;
		}
		else if (b.getCircle().getPosition().y + b.getCircle().getRadius() < myRectangle.getPosition().y + (myRectangle.getSize().y / 2)) {
			myDir = -1;
		}

		myRectangle.setPosition(Vector2f(myRectangle.getPosition().x, myRectangle.getPosition().y + (myDir * (myV * dt))));
	}
	else if (ct == 1) { // up and down - 73 and 74
		upk = Keyboard::Up;
		dwk = Keyboard::Down;

		// Now we test if a key is pressed
		if (e.type == Event::KeyPressed) {
			if (e.key.code == upk) {
				myDir = -1;
			}
			else if (e.key.code == dwk) {
				myDir = 1;
			}
		}
		else if (e.type == Event::KeyReleased) { // if the key is released, we want to stop moving
			myDir = 0;
		}

		// Now we're going to try to do some hitbox stuff with the ball
		if (b.getCircle().getPosition().y + (b.getCircle().getRadius() * 2) >= myRectangle.getPosition().y && b.getCircle().getPosition().y <= myRectangle.getPosition().y + myRectangle.getSize().y
			&& b.getCircle().getPosition().x <= myRectangle.getPosition().x + myRectangle.getSize().x && b.getDir().x == -1) {

			buffer.loadFromFile("Beep1.wav");
			sound.setBuffer(buffer);
			sound.play();

			b.setDir(Vector2f(b.getDir().x * -1, b.getDir().y));
			std::cout << "p" << std::endl;
		}

		// Now we animate based on myDir
		myRectangle.setPosition(Vector2f(myRectangle.getPosition().x, myRectangle.getPosition().y + (myDir * (myV * dt))));

	}

	// draw the paddle
	w.draw(myRectangle);
	// draw the text
	//w.draw(myScoreText);
}

#endif // !_PADDLE_H
