#include <string>
using namespace std;

class Animal{
public:
	Animal{string breed, string name, string colour, string earType, string height, string tailColour, string dadsName, string mumsName);
	void getBreed;
	void getName;
	void getColour;
	void getEarType;
	void getHeight;
	void getTailColour;
	void getDadsName;
	void getMumsName;
private:
	string breed;
	string name;
	string colour;
	string earType;
	string height;
	string tailColour;
	string dadsName;
	string mumsName;
};
