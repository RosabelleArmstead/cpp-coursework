/* Dog.h */
#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include <string>

/*
* Defines the properties of a Dog object. Inherits from Animal class.
*/

class Dog: public Animal{
public:
	Dog(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *dad, std::string mumsName);
};

#endif /* DOG_H */
