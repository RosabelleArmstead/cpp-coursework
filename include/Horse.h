/* Horse.h */
#ifndef HORSE_H
#define HORSE_H
#include "Animal.h"
#include <string>

/*
* Defines the properties of a Horse object. Inherits from Animal class.
*/
class Horse : public Animal{
public:
	Horse(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *dad, std::string mumsName);
};

#endif /* HORSE_H */