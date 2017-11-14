#include <string>

class Animal{
public:
	Animal{std::string breed, std::string name, std::string colour, std::string earType, std::string height, std::string tailColour, std::string dadsName, std::string mumsName);
	std::string getBreed();
	std::string getName();
	std::string getColour();
	std::string getEarType();
	std::string getHeight();
	std::string getTailColour();
	std::string getDadsName();
	std::string getMumsName();
private:
	std::string breed;
	std::string name;
	std::string colour;
	std::string earType;
	std::string height;
	std::string tailColour;
	std::string dadsName;
	std::string mumsName;
};
