#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
	string param[8];
	Map<string, Dog> dogMap()
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
			
			if (param[7] = '') 
			{
				Asthetic asthetic(param[2], param[3], param[4], param[5]);
				Dog newDog(param[0], param[1], asthetic, param[6], null); 	
			}
			 else
			{
				Asthetic asthetic(param[2], param[3], param[4], param[5]);
				Dog newDog(param[0], param[1], asthetic, param[6],dogMap.getValue(param[7])); 
			}			
								
		}

		//return dogmap

	}
	return 0;

}
