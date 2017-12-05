#include "Animal.h"
#include <string>
using namespace std;

Animal::Animal(string a_breed, string a_name, Aesthetic a_aesthetics, string a_dadsName, string a_mumsName)
{
	breed = a_breed;
	name = a_name;
	aesthetics = a_aesthetics;
	dadsName = a_dadsName;
	mumsName = a_mumsName;
}

string Animal::getBreed() {
	return breed;
}

string Animal::getName() {
	return name;
}

Aesthetics Animal::getAesthetics() {
	return aesthetics;
}

string Animal::getDadsName() {
	return dadsName;
}

string Animal::getMumsName() {
	return mumsName;
}
