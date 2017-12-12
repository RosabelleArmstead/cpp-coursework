#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;


//Map for storing each type of animal
map<string, Dog> dogs;
map<string, Cat> cats;
map<string, Horse> horses;

//Declarations for each method 
map<string, Dog> readDogs(string filename);
map<string, Cat> readCats(string fileName);
map<string, Horse> readHorses(string fileName);
void display();
void processInput();
void displayInventory();


//main method - run read functions, run output function, take input, run input processing function
int main()
{
	dogs = readDogs("dogs.csv");
	displayInventory();

		
	cout << "Enter the first letter of the animal group and the name of the specified one to find its paternal tree: ";

	string inputDogName;
	cin >> inputDogName;

	Dog tmp = dogs.at(inputDogName);		

	cout << "Paternal tree of " << inputDogName << ":" << endl;
	cout << inputDogName << " <-- ";
	while(dogs.at(tmp.getName()).getDad()!=0) {

		cout << tmp.getDad()->getName() << " <-- ";
		tmp = dogs.at(tmp.getDad()->getName());

	}
	cout << "[END]" << endl;
	return 0;
}


//Reads dogs into dogs map from the dogs file
map<string, Dog> readDogs(string fileName)
{
	string param[8];
	map<string, Dog> dogMap;
	ifstream infile("files/" + fileName);
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
map<string, Cat> readCats(string fileName)
{
	return cats;
}

//read horses csv into data structure
map<string, Horse> readHorses(string fileName)
{	
	return horses;
}
//produce formatted output
void display()
{

}
//process user input to find paternal family tree
void processInput()
{

}

//Displays the entire inventory
void displayInventory() 
{
	int widthCounter = 91;
		
	cout << left;
	cout << setw(10) << "Name" << setw(10) << "Group" << setw(10) << "Breed" << setw(10) 
	<< "Colour" << setw(12) << "Ear Type" << setw(10) << "Height" << setw(16) << "Tail Colour" << 		setw(10) << "Dad" << setw(3) << "Mum" << endl;	


	for (int i = 0; i <= widthCounter; i++ )	
	{
 		cout << "-";	
	}

	cout << endl;
	
	map<std::string, Dog>::iterator it;
	for (it = dogs.begin(); it != dogs.end(); it++) {
		Dog currentDog = it->second;
		string currentDogMum = "N/A";
		string currentDogDad = "N/A";
		
		if (currentDog.getDad() != 0) {
			currentDogMum = currentDog.getMumsName();
			currentDogDad = currentDog.getDad()->getName();
		}
		
		cout << left;
		cout << setw(10) << currentDog.getName() << setw(10) << "Dog" << setw(10) << 
		currentDog.getBreed() << setw(10) << currentDog.getColour() << setw(12) << 			currentDog.getEarType() << setw(10) << currentDog.getHeight() << setw(16) << 
		currentDog.getTailColour() << setw(10) << currentDogDad << currentDogMum << endl;
	}
	
}


 

