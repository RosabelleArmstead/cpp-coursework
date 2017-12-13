#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include <string>

class Cat: public  Animal{
public:
	Cat(std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, Animal *dad, std::string mumsName);
};

#endif /* CAT_H */