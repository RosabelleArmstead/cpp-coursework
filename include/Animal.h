#include <string>

class Animal{
public:
	Animal{std::string breed, std::string name, Aesthetic aesthetics, std::string dadsName, std::string mumsName);
	std::string getBreed();
	std::string getName();
	Aesthetic getAesthetics();
	std::string getDadsName();
	std::string getMumsName();
private:
	std::string breed;
	std::string name;
	Aesthetics aesthetics;
	std::string dadsName;
	std::string mumsName;
};
