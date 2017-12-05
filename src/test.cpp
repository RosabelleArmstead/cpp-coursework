#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


map<string, dogs> readInFile(string filename);


int main() {
	
	return 0;
}

map<string, dogs> readInFile(string filename) {
  string param[8];
	
	ifstream infile("inputDog.txt");
	if (infile.is_open()) {
		
		string line;
		while(getline(infile, line)) {
			
			stringstream ss(line);
			string item;
			int i = 0;
			while(getline(ss,item, ',')) {
				param[i] = item;
				cout << param[i] << endl;
			}
			
			//if fatherPointer is null make dog and add to map
			//else set to address of father in map
		}

		//return map of dogs
}
