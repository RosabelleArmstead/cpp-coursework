/* Aesthetics.cpp */
#include <string>
#include "Aesthetics.h"
using namespace std;

/*
* Defines the behaviour of Aesthetics such as colour and ear type.
*/
Aesthetics::Aesthetics(string a_colour, string a_earType, string a_height, string a_tailColour)
{
colour = a_colour;
earType = a_earType;
height = a_height;
tailColour = a_tailColour;
}

string Aesthetics::getColour() {
	return colour;
}

string Aesthetics::getEarType() {
	return earType;
}

string Aesthetics::getHeight() {
	return height;
}

string Aesthetics::getTailColour() {
	return tailColour;
}
