#include "Animal.h"
#inlcude <string>
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

void Animal::getBreed() {
	return breed;
}

void Animal::getName() {
	return name;
}

void Animal::getColour() {
	return colour;
}

void Animal::getEarType() {
	return earType;
}

void Animal::getHeight() {
	return height;
}

void Animal::getTailColour() {
	return tailColour;
}

void Animal::getDadsName() {
	return dadsName;
}

void Animal::getMumsName() {
	return mumsName;
}
