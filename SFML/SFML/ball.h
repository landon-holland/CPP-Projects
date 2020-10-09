// ball.h - moving ball for pong
// Landon Holland - 3/15/2019

#pragma once
#ifndef _BALL_H
#define _BALL_H

#include <SFML/Graphics.hpp>

using namespace sf;

class ball {
public:
	ball(); // default constructor
	ball(Vector2f position, Color c, Vector2f dir, float v); // fill constructor

	// member functions
	void setCircle(CircleShape c);
	CircleShape getCircle();

	void setColor(Color c);
	Color getColor();

	void setDir(Vector2f dir);
	Vector2f getDir();

	void setVelocity(float v);
	float getVelocity();

	void setPosition(Vector2f pos);

	void update(RenderWindow &w, float dt, int &gs);
private:
	CircleShape myCircle;
	Color myCol;
	Vector2f myDir;
	float myV;
};

ball::ball() {
	myCol = Color::Blue;

	myCircle = CircleShape(10.f);
	myCircle.setPosition(0, 0);
	myCircle.setFillColor(myCol);

	myDir = Vector2f(1, 1);

	myV = 100;
}

ball::ball(Vector2f position, Color c, Vector2f dir, float v) {
	myCol = c;

	myCircle = CircleShape(10.f);
	myCircle.setPosition(position);
	myCircle.setFillColor(myCol);

	myDir = dir;

	myV = v;
}

void ball::setCircle(CircleShape c) {
	myCircle = c;
}

CircleShape ball::getCircle() {
	return myCircle;
}

void ball::setColor(Color c) {
	myCol = c;
}

Color ball::getColor() {
	return myCol;
}

void ball::setDir(Vector2f dir) {
	myDir = dir;
}

Vector2f ball::getDir() {
	return myDir;
}

void ball::setVelocity(float v) {
	myV = v;
}

float ball::getVelocity() {
	return myV;
}

void ball::setPosition(Vector2f pos) {
	myCircle.setPosition(pos);
}

void ball::update(RenderWindow &w, float dt, int &gs) {
	// win or loss return variable is gs. 0 = no win, 1 = left won, 2 = right won
	if (gs == 0) {

		// Animation code
		myCircle.setPosition(Vector2f(myCircle.getPosition().x + (myDir.x * (myV * dt)), myCircle.getPosition().y + (myDir.y * (myV * dt))));

		// Top and bottom walls hitboxes
		if (myCircle.getPosition().y > (750 - (myCircle.getRadius() * 2))) {
			myDir.y *= -1;
		}
		else if (myCircle.getPosition().y < (0 + (myCircle.getRadius() * 2))) {
			myDir.y *= -1;
		}

		// Left and right winner hitboxes
		if (myCircle.getPosition().x > (2000 - (myCircle.getRadius() * 2))) {
			gs = 1;
		}
		else if (myCircle.getPosition().x < (0 + (myCircle.getRadius() * 2))) {
			gs = 1;
		}
	}
	// Finish by telling SFML to draw it
	w.draw(myCircle);
}

#endif
