// CompNum.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 3/7/2019 - Landon Holland
// SFML CompNum


#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "compnum.h"

using namespace std;

int main()
{
	char Ans;
	do {
		string si1, si2;
		compnum c1, c2;
		char MenuChoice;
		int power;

		cout << "Enter your operation (+,-,*,/,^): ";
		cin >> MenuChoice;

		if (MenuChoice == '^') {
			cout << "Enter the first complex number: ";
			cin >> si1;
			compnum i1(si1);
			c1.setR(i1.getR());
			c1.setI(i1.getI());
			cout << "Enter the power: ";
			cin >> power;
		}
		else {
			cout << "Enter the first complex number: ";
			cin >> si1;
			compnum i1(si1);
			c1.setR(i1.getR());
			c1.setI(i1.getI());
			cout << "Enter the second complex number: ";
			cin >> si2;
			compnum i2(si2);
			c2.setR(i2.getR());
			c2.setI(i2.getI());
		}

		sf::RenderWindow window(sf::VideoMode(1000, 1000), "CompNum");

		sf::Font font;
		if (!font.loadFromFile("UbuntuMono-R.ttf")) {
			cout << "Error loading font." << endl;
		}

		sf::Text text;
		text.setFont(font);
		if (MenuChoice == '+') {
			text.setString((c1 + c2).toString());
		}
		else if (MenuChoice == '-') {
			text.setString((c1 - c2).toString());
		}
		else if (MenuChoice == '*') {
			text.setString((c1 * c2).toString());
		}
		else if (MenuChoice == '/') {
			text.setString((c1 / c2).toString());
		}
		else if (MenuChoice == '^') {
			text.setString((c1 ^ power).toString());
		}
		text.setCharacterSize(150);
		text.setFillColor(sf::Color::Blue);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(text);
			window.display();
		}

		cout << "Run Again? [Y/n]: ";
		cin >> Ans;
	} while (Ans == 'Y' || Ans == 'y');
	return 0;
}
