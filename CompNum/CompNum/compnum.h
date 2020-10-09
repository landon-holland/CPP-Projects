// compnum.h
// Landon Holland

#pragma once
#ifndef _COMPNUM_H
#define _COMPNUM_H

#include <string>
#include <math.h>
#include <sstream>
#include <iostream>

using namespace std;

class compnum {
private:
	double myR, myI; // R is the real part. I is the imaginary part

public:
	compnum(); // default constructor
	compnum(double r, double i); // fill constructor
	compnum(string c);

	// member functions
	double getR();
	void setR(double r);
	double getI();
	void setI(double i);

	string toString(); // to string function

	compnum findConj();
	compnum add(compnum c);
	compnum sub(compnum c);
	compnum mult(compnum c);
	compnum div(compnum c);
	compnum power(int p);

	compnum operator +(compnum c);
	compnum operator -(compnum c);
	compnum operator *(compnum c);
	compnum operator /(compnum c);
	compnum operator ^(int p);

};

compnum::compnum() {
	myR = 0.0;
	myI = 0.0;
}

compnum::compnum(double r, double i) {
	myR = r;
	myI = i;
}

compnum::compnum(string c) {
	int plusi, ii;
	bool iPosi, rPosi;
	stringstream rss, iss;

	// Actually before the first thing, we need to check if the real number is negative, or else it will screw with out other code.
	if (c[0] == '-') {
		rPosi = false;
	}
	else {
		rPosi = true;
	}

	// First we're gonna figure out where the plus index is. (or minus)
	for (int i = 1; i <= c.length(); i++) {
		if (c[i] == '+' || c[i] == '-') {
			plusi = i; // Set the index

			if (c[i] == '+') {
				iPosi = true;
			}
			else if (c[i] == '-') {
				iPosi = false;
			}

			break; // Then yeet out of the loop
		}
	}

	// Now lets figure out the i index
	ii = c.length() - 1;

	// Now that we know where things are, lets transfer it to the two different variables
	// We're gonna use stringstream to make two strings and then use the .str() function and then a string to double function

	// rss is first
	if (rPosi == false) {
		rss << '-';
		for (int i = 1; i <= plusi - 1; i++) {
			rss << c[i];
		}
	}
	else if (rPosi == true) {
		for (int i = 0; i <= plusi - 1; i++) {
			rss << c[i];
		}
	}

	// iss is next
	if (iPosi == false) {
		iss << '-';
	}
	
	for (int i = plusi + 1; i <= ii - 1; i++) {
		iss << c[i];
	}

	// now we have to go from stringstream to string to double
	rss >> myR;
	iss >> myI;
}

double compnum::getR() {
	return myR;
}

void compnum::setR(double r) {
	myR = r;
}

double compnum::getI() {
	return myI;
}

void compnum::setI(double i) {
	myI = i;
}

string compnum::toString() {
	stringstream sout;

	if (myI > 0) {
		sout << myR << " + " << myI << 'i';
	}
	else {
		sout << myR << " - " << (myI * -1) << 'i';
	}

	return sout.str();
}

compnum compnum::findConj() {
	return compnum(myR, (myI * -1));
}

compnum compnum::add(compnum c) {
	return compnum((myR + c.getR()), (myI + c.getI()));
}

compnum compnum::sub(compnum c) {
	return compnum((myR - c.getR()), (myI - c.getI()));
}

compnum compnum::mult(compnum c) {
	return compnum((myR * c.getR()) + (-1 * myI * c.getI()), (myR * c.getI()) + (myI * c.getR()));
}

compnum compnum::div(compnum c) {
	return compnum((compnum(myR, myI) * c.findConj()).getR() / (c * c.findConj()).getR(),
				   (compnum(myR, myI) * c.findConj()).getI() / (c * c.findConj()).getR());

}

compnum compnum::power(int p) {
	compnum a(myR, myI);
	compnum b;

	if (p == 0) {
		return compnum(1, 0);
	}

	else if (p == 1) {
		return compnum(myR, myI);
	}

	else if (p == 2) {
		b = a * a;

		return b;
	}

	else {
		b = a * a;
		for (int i = 1; i <= p - 2; i++) {
			b = b * a;
		}

		return b;
	}
}

compnum compnum::operator +(compnum c) {
	return add(c);
}

compnum compnum::operator -(compnum c) {
	return sub(c);
}

compnum compnum::operator *(compnum c) {
	return mult(c);
}

compnum compnum::operator /(compnum c) {
	return div(c);
}

compnum compnum::operator ^(int r) {
	return power(r);
}

#endif // !_COMPNUM_H
