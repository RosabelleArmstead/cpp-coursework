#include "Animal.h"
#include <string>
using namespace std;

Animal::Animal(string a_breed, string a_name, string a_colour, string a_earType, string a_height, string a_tailColour, string a_dadsName, string a_mumsName)
{
	breed = a_breed;
	name = a_name;
	colour = a_colour;
	earType = a_earType;
	height = a_height;
	tailColour = a_tailColour;
	dadsName = a_dadsName;
	mumsName = a_mumsName;
}

string Animal::getBreed() {
	return breed;
}

string Animal::getName() {
	return name;
}

string Animal::getColour() {
	return colour;
}

string Animal::getEarType() {
	return earType;
}

string Animal::getHeight() {
	return height;
}

string Animal::getTailColour() {
	return tailColour;
}

string Animal::getDadsName() {
	return dadsName;
}

string Animal::getMumsName() {
	return mumsName;
}
