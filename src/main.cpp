#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
//#include "Aesthetics.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

//function declarations - map template? key = name
//map<string, Dog> readDogs(string filename);
string ltrim(string s, const char* t);
void processInput();
//void processDog (string inputAnimal, string file);
//void processCat (string inputAnimal, string file);
//void processHorse (string inputAnimal, string file);
void processAnimal(string inputAnimal, T animal, map<string, T> map);
string chooseFile(string inputAnimal);

map<string, Dog> globalDogMap;
map<string, Cat> globalCatMap;
map<string, Horse> globalHorseMap;

template <class T> map<string,T> readT(string fileName);

template <class T> map<string,T> readT(string fileName){

	string param[8];
	map<string, T> tMap;
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
			if (tMap.find(param[6]) == tMap.end())
			{
				T newT(param[0], param[1], param[2], param[3], param[4], param[5], NULL, param[7]);
				tMap.insert(pair<string, T> (param[1], newT));
			}
			else
			{
				Animal *fatherPointer = &tMap.at(param[6]);

				T newT(param[0], param[1], param[2], param[3], param[4], param[5], fatherPointer, param[7]);
				tMap.insert(pair<string, T> (param[1], newT));
			}							
		}
		
	}

	return tMap;

}

//produce formatted output
void display()
{

}
//trim for processing input
string ltrim(string s, const char* t = "dch \t\n\r\f\v") {
	return s.erase(0, s.find_first_not_of(t));
}

//process user input to find paternal family tree
void processInput()
{
	string inputAnimal = "";
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	getline(cin, inputAnimal);
	
	if (inputAnimal[0] == 'd')
	{
		processAnimal<Dog>(inputAnimal, Dog, globalDogMap);
	}
	else if (inputAnimal[0] == 'c')
	{
		processAnimal<Cat>(inputAnimal, Cat, globalCatMap);
	}
	else if (inputAnimal[0] == 'h')
	{
		processAnimal<Horse>(inputAnimal, Horse, globalHorseMap);
	}
	else
	{
		return "Not an animal!";
	}
	
	inputAnimal = ltrim(inputAnimal);
	
	
	//TODO: try catch for if animal not existing
}


template <class T> void processAnimal(string inputAnimal, T animal, map<string,T> tMap) {
	
	animal = tMap.at(inputAnimal);
	cout << "Paternal tree of " << inputAnimal << ":" << endl;
	cout << inputAnimal << " <-- ";
	while(tMap.at(tmp.getName()).getDad()!=0) {
		cout << tmp.getDad()->getName() << " <-- ";
		tmp = tMap.at(tmp.getDad()->getName());
	}
	cout << "[END]" << endl;
	
}


//main method - run read functions, run output function, take input, run input processing function 
int main()
{
	globalDogMap = readT<Dog>("dogs.csv");
	globalCatMap = readT<Cat>("cats.csv");
	globalHorseMap = readT<Horse>("horses.csv");
	while (true){
		processInput();
	}
}
