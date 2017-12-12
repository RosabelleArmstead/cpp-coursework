#include "Animal.h"
#include <string>

class Dog: public Animal{
public:
	Dog(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *dad, std::string mumsName);
};
