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

map<string, Dog> readDogs(string filename);

//function declarations - map template? key = name
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
//process user input to find paternal family tree
void processInput()
{

}

//main method - run read functions, run output function, take input, run input processing function 
int main()
{
	map<string,Dog> dogs = readDogs("dogs.csv");
		
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
	
	//cout << dad->getName() << endl;

	


	return 0;
}
