//Canavan Neeson. CSCI 60-03. HW 1 Problem 1.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void writeletter(string names[], int size, char letter, ostream& out);


int main() {
	ifstream in("infile.txt");
	if (in.fail()) {
		cout << "Input file error.\n";
		exit(1);
	}
	
	ofstream out("outfile.txt");
	if (out.fail()) {
		cout << "Output file error.\n";
		exit(1);
	}
	
	int maxnames = 1000, numnames = 0; //Maximum number of names allowed; number of names used
	string names[maxnames];
	for (int i = 0; i < maxnames; i++) //Counts number of indices actually used
	{
		if (in >> names[i])
			numnames++;
		else
			break;
	}
	
	for (int i = 0; i < 26; i++) {
		writeletter(names, numnames, 'A' + i, out); //Technically, numnames is not the size of the array, but the number of indices used
	}
	
	in.close();
	out.close();
	
	return 0;
}

void writeletter(string names[], int size, char letter, ostream& out) {
//	string temp;
	for (int i = 0; i < size; i++) {
		if (names[i][0] == letter) {
			out << names[i] << endl;
		}
	}
}








