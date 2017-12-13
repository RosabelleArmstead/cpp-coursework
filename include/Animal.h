/* Animal.h */
#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include "Aesthetics.h"

/*
* Defines the properties of an Animal object. Inherits from Aesthetics class.
*/

class Animal : public Aesthetics {
public:
	Animal(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *animal, std::string mumsName);
	std::string getBreed();
	std::string getName();
	Animal* getDad();
	std::string getMumsName();
private:
	std::string breed;
	std::string name;
	Animal *animal;
	std::string mumsName;
};

#endif /* ANIMAL_H */