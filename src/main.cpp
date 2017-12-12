#include "Dog.h"
//#include "Cat.h"
//#include "Horse.h"
//#include "Aesthetics.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

//function declarations - map template? key = name
map<string, Dog> readDogs(string filename);
string ltrim(string s, const char* t);
processInput();
processDog (string inputAnimal, string file);
chooseFile(string inputAnimal);
//read dogs csv into data structure


map<string, Dog> readDogs(string fileName)
{
	string param[8];
	map<string, Dog> dogMap;
	ifstream infile("files/" + fileName);
	if (infile.is_open()) {
		
		string line;
		while(getline(infile, line)) {
			
			stringstream ss(line);
			string item;
			int i = 0;
			while(getline(ss,item, ',')) {

				param[i] = item;

				i++;
			}
			if (dogMap.find(param[6]) == dogMap.end())
			{
				Dog newDog(param[0], param[1], param[2], param[3], param[4], param[5], NULL, param[7]);
				dogMap.insert(pair<string, Dog> (param[1], newDog));
			}
			else
			{
				Animal *fatherPointer = &dogMap.at(param[6]);

				Dog newDog(param[0], param[1], param[2], param[3], param[4], param[5], fatherPointer, param[7]);
				dogMap.insert(pair<string, Dog> (param[1], newDog));
			}							
		}
		
	}

	return dogMap;

}

//read cats csv into data structure
void readCats()
{

}
//read horses csv into data structure
void readHorses()
{

}
//produce formatted output
void display()
{

}
//trim for processing input
string ltrim(string s, const char* t = " \t\n\r\f\v") {
	return s.erase(0, s.find_first_not_of(t));
}

//process user input to find paternal family tree
int processInput()
{
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	string inputAnimal = "";
	cin >> inputAnimal;
	string file = chooseFile(inputAnimal);
	inputAnimal = ltrim(inputAnimal);
	
	if (file == "dogs.csv")
	{
		processDog(inputAnimal, file);
	}
	else
	{
		cout << file << endl;
	}
		/* case "cats.csv": processCat(inputAnimal, file);
		case "horses.csv": processHorse(inputAnimal, file); */
		//try catch for if animal not existing
	return 0;
}

string chooseFile(string inputAnimal)
{
	if (inputAnimal.at(1) == "d")
	{
		return "dogs.csv";
	}
	else if (inputAnimal.at(1) == "c")
	{
		return "cats.csv";
	}
	else if (inputAnimal.at(1) == "h")
	{
		return "horses.csv";
	}
	else
	{
		return "Not an animal!";
	}
}

//methods to process animals - use template and pass classes?
void processDog (string inputAnimal, string file)
{
	map<string, Dog> dogs = readDogs(file);
	Dog tmp = dogs.at(inputAnimal);
	cout << "Paternal tree of " << inputAnimal << ":" << endl;
	cout << inputAnimal << " <-- ";
	while(dogs.at(tmp.getName()).getDad()!=0) {
		cout << tmp.getDad()->getName() << " <-- ";
		tmp = dogs.at(tmp.getDad()->getName());
	}
	cout << "[END]" << endl;
}
/* void processCat (string inputAnimal, string file)
{
	map<string, Cat> cats = readCats(file);
	Cat tmp cats.at(inputAnimal);
	cout << "Paternal tree of " << inputAnimal << ":" << endl;
	cout << inputAnimal << " <-- ";
	while(cats.at(tmp.getName()).getDad()!=0) {
		cout << tmp.getDad()->getName() << " <-- ";
		tmp = cats.at(tmp.getDad()->getName());
	}
	cout << "[END]" << endl;
}
void processHorse (string inputAnimal, string file)
{
	map<string, Horse> horses = readhorses(file);
	Horse tmp horses.at(inputAnimal);
	cout << "Paternal tree of " << inputAnimal << ":" << endl;
	cout << inputAnimal << " <-- ";
	while(horses.at(tmp.getName()).getDad()!=0) {
		cout << tmp.getDad()->getName() << " <-- ";
		tmp = horses.at(tmp.getDad()->getName());
	}
	cout << "[END]" << endl;
}
*/
//main method - run read functions, run output function, take input, run input processing function 
int main()
{
	processInput();
}
