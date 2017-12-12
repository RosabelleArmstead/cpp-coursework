#include "Animal.h"
#include <string>

class Horse : public Animal{
public:
	Horse(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *dad, std::string mumsName);
};
