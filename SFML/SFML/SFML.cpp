// SFML.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 3/10/2019 - Landon Holland
// SFML GUI project

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(2000, 750), "Pong");
	Clock time;
	Font font;

	if (!font.loadFromFile("UbuntuMono-R.ttf")) {
		std::cout << "Error loading font." << std::endl;
	}

	float dt, pt = 0.f;
	int gs = 0;
	ball b(Vector2f(1005, 330), Color::Blue, Vector2f(-1, 1), 350.f);
	paddle p1(Vector2f(50, 325), Color::Green, 0, 300.f, font);
	paddle ai(Vector2f(1900, 325), Color::Green, 0, 300.f, font);

	while (window.isOpen())
	{
		// code for delta t
		dt = time.getElapsedTime().asSeconds() - pt;
		pt = time.getElapsedTime().asSeconds();
		// if test just in case dt is way too big
		if (dt > .15) {
			dt = float(.15);
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		// display code
		window.clear();
		b.update(window, dt, gs);
		p1.update(window, event, dt, 1, b);
		ai.update(window, event, dt, 0, b);

		// gonna test for winners and probably display score text
		if (gs == 1) {
			if (b.getCircle().getPosition().x < 1000) {
				ai.plusScore();
			}
			else if (b.getCircle().getPosition().x > 1000) {
				p1.plusScore();
			}

			gs = 0;
			b.setPosition(Vector2f(1005, 335));
			b.setDir(Vector2f(-1, 1));
		}

		window.display();
	}

	return 0;
}