#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
//#include "Aesthetics.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

//function declarations - map template? key = name
//map<string, Dog> readDogs(string filename);
string ltrim(string s, const char* t);
void processInput();
//void processDog (string inputAnimal, string file);
//void processCat (string inputAnimal, string file);
//void processHorse (string inputAnimal, string file);
template <class T> void processAnimal(string inputAnimal, map<string, T> map);
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
string ltrim(string s) {
	return s.erase(0, 2);
}

//process user input to find paternal family tree
void processInput()
{
	string inputAnimal = "";
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	getline(cin, inputAnimal);
	
	if (inputAnimal[0] == 'd')
	{
		inputAnimal = ltrim(inputAnimal);
		processAnimal<Dog>(inputAnimal, globalDogMap);
	}
	else if (inputAnimal[0] == 'c')
	{
		inputAnimal = ltrim(inputAnimal);
		processAnimal<Cat>(inputAnimal, globalCatMap);
	}
	else if (inputAnimal[0] == 'h')
	{
		inputAnimal = ltrim(inputAnimal);
		processAnimal<Horse>(inputAnimal, globalHorseMap);
	}
	else
	{
		cout << "Not an animal!";
	}
	
	
	//TODO: try catch for if animal not existing
}


template <class T> void processAnimal(string inputAnimal, map<string,T> tMap) {
	
	try {
		Animal animal = tMap.at(inputAnimal);
		cout << "Paternal tree of " << inputAnimal << ":" << endl;
		cout << inputAnimal << " <-- ";
		while(tMap.at(animal.getName()).getDad()!=0) {
			cout << animal.getDad()->getName() << " <-- ";
			animal = tMap.at(animal.getDad()->getName());
		}
	} catch (const out_of_range& e) {
		cout << inputAnimal << "<--";
	}
	cout << "[END]" << endl;
	
}

//Displays the entire inventory
void displayInventory() 
{
	cout << "There are " << globalDogMap.size() << " dog(s), " << globalCatMap.size() << " cat(s) and " << globalHorseMap.size() << " horse(s) in the inventory, which are:" << endl;
	//dogs
	int widthCounter = 91;
		
	cout << left;
	cout << setw(10) << "Name" << setw(10) << "Group" << setw(10) << "Breed" << setw(10) 
	<< "Colour" << setw(12) << "Ear Type" << setw(10) << "Height" << setw(16) << "Tail Colour" << setw(10) << "Dad" << setw(3) << "Mum" << endl;	


	for (int i = 0; i <= widthCounter; i++ )	
	{
 		cout << "-";	
	}

	cout << endl;
	
	map<std::string, Dog>::iterator dogIt;
	for (dogIt = globalDogMap.begin(); dogIt != globalDogMap.end(); dogIt++) {
		Dog currentDog = dogIt->second;
		string currentDogMum = "N/A";
		string currentDogDad = "N/A";
		
		if (currentDog.getDad() != 0) {
			currentDogMum = currentDog.getMumsName();
			currentDogDad = currentDog.getDad()->getName();
		}
		
		cout << left;
		cout << setw(10) << currentDog.getName() << setw(10) << "Dog" << setw(10) << 
		currentDog.getBreed() << setw(10) << currentDog.getColour() << setw(12) << currentDog.getEarType() << setw(10) << currentDog.getHeight() << setw(16) << 
		currentDog.getTailColour() << setw(10) << currentDogDad << currentDogMum << endl;
	}
	cout << endl;
	//cats
	map<std::string, Cat>::iterator catIt;
	for (catIt = globalCatMap.begin(); catIt != globalCatMap.end(); catIt++) {
		Cat currentCat = catIt->second;
		string currentCatMum = "N/A";
		string currentCatDad = "N/A";
		
		if (currentCat.getDad() != 0) {
			currentCatMum = currentCat.getMumsName();
			currentCatDad = currentCat.getDad()->getName();
		}
		
		cout << left;
		cout << setw(10) << currentCat.getName() << setw(10) << "Cat" << setw(10) << 
		currentCat.getBreed() << setw(10) << currentCat.getColour() << setw(12) << currentCat.getEarType() << setw(10) << currentCat.getHeight() << setw(16) << 
		currentCat.getTailColour() << setw(10) << currentCatDad << currentCatMum << endl;
	}
	
	cout << endl;
	//horses
	map<std::string, Horse>::iterator it;
	for (it = globalHorseMap.begin(); it != globalHorseMap.end(); it++) {
		Horse currentHorse = it->second;
		string currentHorseMum = "N/A";
		string currentHorseDad = "N/A";
		
		if (currentHorse.getDad() != 0) {
			currentHorseMum = currentHorse.getMumsName();
			currentHorseDad = currentHorse.getDad()->getName();
		}
		
		cout << left;
		cout << setw(10) << currentHorse.getName() << setw(10) << "Horse" << setw(10) << 
		currentHorse.getBreed() << setw(10) << currentHorse.getColour() << setw(12) << currentHorse.getEarType() << setw(10) << currentHorse.getHeight() << setw(16) << 
		currentHorse.getTailColour() << setw(10) << currentHorseDad << currentHorseMum << endl;
	}
}

//main method - run read functions, run output function, take input, run input processing function 
int main()
{
	globalDogMap = readT<Dog>("dogs.csv");
	globalCatMap = readT<Cat>("cats.csv");
	globalHorseMap = readT<Horse>("horses.csv");
	displayInventory();
	while (true){
		processInput();
	}
}
