/* main.cpp */
#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

/* function declarations */
template <class T> map<string,T> readT(string fileName);
template <class T> void processAnimal(string inputAnimal, map<string, T> map);
string ltrim(string s, const char* t);
void processInput();
bool checkIfInDogMap(string name);
bool checkIfInCatMap(string name);
bool checkIfInHorseMap(string name);
void checkIfInAnyMap(string name);
string chooseFile(string inputAnimal);

/* global map declarations */
map<string, Dog> globalDogMap;
map<string, Cat> globalCatMap;
map<string, Horse> globalHorseMap;

/*
* Reads a csv file into a map of T class objects by splitting on commas within
* a line for the class parameters, and using each line as a separate object.
*/
template <class T> map<string,T> readT(string fileName)
{
	string param[8]; //array for parameters of T object
	map<string, T> tMap;
	ifstream infile("files/" + fileName); //get file from correct directory
	if (infile.is_open()) 
	{
		string line;
		while(getline(infile, line)) 
		{
			stringstream ss(line);
			string item;
			int i = 0;
			while(getline(ss,item, ',')) 
			{
				param[i] = item; //populate parameter array from line on comma split
				i++;
			}
			if (tMap.find(param[6]) == tMap.end()) // if object has no father, set null pointer
			{
				T newT(param[0], param[1], param[2], param[3], param[4], param[5], 
				NULL, param[7]); //null pointer if no father
				tMap.insert(pair<string, T> (param[1], newT));
			}
			else // if object has father, set pointer to father
			{
				Animal *fatherPointer = &tMap.at(param[6]); //pointer to father object
				T newT(param[0], param[1], param[2], param[3], param[4], param[5], 
				fatherPointer, param[7]);
				tMap.insert(pair<string, T> (param[1], newT));
			}							
		}	
	}
	else
	{
		cout << "There was an error reading the file!" << endl; //error checking for if the file cannot be read
	}
	return tMap;
}

/*
* returns animal name string by trimming first 2 characters of string s
*/
string ltrim(string s)
{
	return s.erase(0, 2);
}

/*
* Compares first letter of user input to find which map to search for an animal.
* Runs ltrim function on user input to get animal name from user input.
* Runs error checking functions in case animal does no exist in given map, or there
* is no map for the user input.
*/
void processInput()
{
	string inputAnimal = "";
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";
	getline(cin, inputAnimal);

	
	if(inputAnimal[1]!=' ') // if input was not a character followed by a space followed by a name, start again
	{
		processInput();
	
	} else {

		if (inputAnimal[0] == 'd') // if user inputs d, dog map is checked
		{
			inputAnimal = ltrim(inputAnimal);
			if(!checkIfInDogMap(inputAnimal)) // if dog doesn't exist in map, error message
			{
				cout << inputAnimal << " was not found within the \e[mDogs!" << endl;
			}		
		}
		else if (inputAnimal[0] == 'c') // if user inputs c, cat map is checked
		{
			inputAnimal = ltrim(inputAnimal);
			if(!checkIfInCatMap(inputAnimal)) // if cat doesn't exist in map, error message
			{
				cout << inputAnimal << " was not found within the \e[mCats!" << endl;
			}
		}
		else if (inputAnimal[0] == 'h') // if user inputs h, horse map is checked
		{
			inputAnimal = ltrim(inputAnimal);
			if(!checkIfInHorseMap(inputAnimal)) // if horse doesn't exist in map, error message
			{
				cout << inputAnimal << " was not found within the \e[mHorses!" << endl;
			}
		}
		else if (inputAnimal[0] == 'a') // if user inputs a, all maps are checked
		{
			inputAnimal = ltrim(inputAnimal);
			try //try catch so if animal doesn't exist in any map, error message
			{
				checkIfInAnyMap(inputAnimal);
			}
			catch (const char* msg) 
			{
				cerr << inputAnimal << msg << endl;
			}
		}
		else // if user inputs anything else, there is no map so error message
		{
			cout << "Not an animal! Enter a to search all, c to search cats, d to search dogs or h to search horses." << endl;
		}
	}
}

/*
* Returns true if user input name is found in dog map
* If true, runs processAnimal function for dog in the dog map
*/
bool checkIfInDogMap(string name) 
{
	try 
	{
		globalDogMap.at(name);
		processAnimal<Dog>(name, globalDogMap);
		return true;
	} 
	catch (const out_of_range& e) 
	{
		return false;
	}
}

/*
* Returns true if user input name is found in cat map
* If true, runs processAnimal function for cat in the cat map
*/
bool checkIfInCatMap(string name) 
{
	try 
	{
		globalCatMap.at(name);
		processAnimal<Cat>(name, globalCatMap);
		return true;
	} 
	catch (const out_of_range& e) 
	{
		return false;
	}
}

/*
* Returns true if user input name is found in horse map
* If true, runs processAnimal function for horse in the horse map
*/
bool checkIfInHorseMap(string name) 
{
	try 
	{
		globalHorseMap.at(name);
		processAnimal<Horse>(name, globalHorseMap);
		return true;
	} 
	catch (const out_of_range& e) 
	{
		return false;
	}
}

/*
* Throws exception if user input name is not found in any map
*/
void checkIfInAnyMap(string name) 
{
	if(checkIfInDogMap(name)) {}
	else if (checkIfInCatMap(name)) {}
	else if (checkIfInHorseMap(name)) {}
	else 
	{
		throw " was not found within any inventory!";
	}	
}

/*
* Takes user input animal and map for given animal and displays the paternal tree
* of the given animal. Uses father pointer to get address location for father of animal.
*/
template <class T> void processAnimal(string inputAnimal, map<string,T> tMap) 
{
	try // try catch for if the animal has no father, display default tree
	{
		Animal animal = tMap.at(inputAnimal);
		cout << "Paternal tree of " << inputAnimal << ":" << endl;
		cout << inputAnimal << " <-- ";
		/* while loop to get all fathers until an animal with no father */
		while(tMap.at(animal.getName()).getDad()!=0)
		{
			cout << animal.getDad()->getName() << " <-- ";
			animal = tMap.at(animal.getDad()->getName());
		}
	} 
	catch (const out_of_range& e) 
	{
		cout << inputAnimal << " <-- ";
	}
	cout << "[END]" << endl;
}

/*
* Displays formatted output of all animals by iterating through the maps and outputting
* the relevant attributes.
*/
void displayInventory() 
{
	cout << "There are " << globalDogMap.size() << " dog(s), " << globalCatMap.size() << " cat(s) and " << globalHorseMap.size() << 
	" horse(s) in the inventory, which are:" << endl;
	/* column titles formatting */
	int widthCounter = 91;
	cout << left;
	cout << setw(10) << "Name" << setw(10) << "Group" << setw(10) << "Breed" << setw(10) 
	<< "Colour" << setw(12) << "Ear Type" << setw(10) << "Height" << setw(16) << "Tail Colour" << setw(10) << "Dad" << setw(3) << 
	"Mum" << endl;
	for (int i = 0; i <= widthCounter; i++)	
	{
 		cout << "-";	
	}
	cout << endl;
	/* display for dogs */
	map<std::string, Dog>::iterator dogIt;
	for (dogIt = globalDogMap.begin(); dogIt != globalDogMap.end(); dogIt++) 
	{
		Dog currentDog = dogIt->second;
		string currentDogMum = "N/A";
		string currentDogDad = "N/A";
		if (currentDog.getDad() != 0) 
		{
			currentDogMum = currentDog.getMumsName();
			currentDogDad = currentDog.getDad()->getName();
		}
		cout << left;
		cout << setw(10) << currentDog.getName() << setw(10) << "Dog" << setw(10) << 
		currentDog.getBreed() << setw(10) << currentDog.getColour() << setw(12) << currentDog.getEarType() << 
		setw(10) << currentDog.getHeight() << setw(16) << currentDog.getTailColour() << 
		setw(10) << currentDogDad << currentDogMum << endl;
	}
	cout << endl;
	/* display for cats */
	map<std::string, Cat>::iterator catIt;
	for (catIt = globalCatMap.begin(); catIt != globalCatMap.end(); catIt++) 
	{
		Cat currentCat = catIt->second;
		string currentCatMum = "N/A";
		string currentCatDad = "N/A";	
		if (currentCat.getDad() != 0) 
		{
			currentCatMum = currentCat.getMumsName();
			currentCatDad = currentCat.getDad()->getName();
		}
		cout << left;
		cout << setw(10) << currentCat.getName() << setw(10) << "Cat" << setw(10) << 
		currentCat.getBreed() << setw(10) << currentCat.getColour() << setw(12) << currentCat.getEarType() << 
		setw(10) << currentCat.getHeight() << setw(16) << currentCat.getTailColour() <<	
		setw(10) <<	currentCatDad << currentCatMum << endl;
	}
	cout << endl;
	/* display for horses */
	map<std::string, Horse>::iterator it;
	for (it = globalHorseMap.begin(); it != globalHorseMap.end(); it++) 
	{
		Horse currentHorse = it->second;
		string currentHorseMum = "N/A";
		string currentHorseDad = "N/A";	
		if (currentHorse.getDad() != 0) 
		{
			currentHorseMum = currentHorse.getMumsName();
			currentHorseDad = currentHorse.getDad()->getName();
		}
		cout << left;
		cout << setw(10) << currentHorse.getName() << setw(10) << "Horse" << setw(10) << 
		currentHorse.getBreed() << setw(10) << currentHorse.getColour() << setw(12) << currentHorse.getEarType() << 
		setw(10) << currentHorse.getHeight() << setw(16) << currentHorse.getTailColour() << 
		setw(10) << currentHorseDad << currentHorseMum << endl;
	}
}

/*
* Entry point for the program. Runs the readT function to create all animal maps. Runs
* the displayInventory function to display all animals. Continues running the program
* until force quit.
*/
int main()
{
	globalDogMap = readT<Dog>("dogs.csv");
	globalCatMap = readT<Cat>("cats.csv");
	globalHorseMap = readT<Horse>("horses.csv");
	displayInventory();
	while (true)
	{
		processInput();
	}
}
