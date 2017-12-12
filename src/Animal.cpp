#include "Animal.h"
#include <string>

using namespace std;

Animal::Animal(string a_breed, string a_name, string a_colour, string a_earType, string a_height, string a_tailColour, Animal *a_animal,string a_mumsName) : Aesthetics(a_colour, a_earType, a_height, a_tailColour)
{
	breed = a_breed;
	name = a_name;
	animal = a_animal;
	mumsName = a_mumsName;
}

string Animal::getBreed() {
	return breed;
}

string Animal::getName() {
	return name;
}

Animal* Animal::getDad() {
	return animal;
}

string Animal::getMumsName() {
	return mumsName;
}
