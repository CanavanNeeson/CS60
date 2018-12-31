//Canavan Neeson. CSCI 60-03. HW 1 Problem 2.
#include <iostream>
#include <string>
using namespace std;

struct Animal {
	string name;
	bool gender; //0 corresponds to female, 1 to male
	int age;
	int price;
	string type; //cat or dog.
};

Animal cheapest(string type, Animal a[], int size);
//Precondition: type is a valid animal type. Size is the size of array a
//Postcondition: Animal object of type "type" with lowest price is returned 
bool livetogether(Animal a, Animal b);
//Precondition: a and b are animals
//Postcondition: returns true if a and b are of same type, false otherwise

int main() {
	int size = 4;
	Animal a[size] = {{"a", 0, 5, 50, "cat"},
					{"b", 0, 4, 60, "cat"},
					{"c", 1, 6, 55, "cat"},
					{"d", 1, 5, 40, "dog"}};
	
	cout << "Cheapest cat: $" << cheapest("cat", a, size).price << endl;
	cout << "Cheapest dog: $" << cheapest("dog", a, size).price << endl;
	if (cheapest("fish", a, size).price > -1)
		cout << "Cheapest fish: $" << cheapest("fish", a, size).price << endl;//-1 price indicates error
	cout << "Can animals \"a\" and \"b\" live together? " << ((livetogether(a[0], a[1])) ? "Yes!\n" : "Nope.\n");
	cout << "Can animals \"a\" and \"d\" live together? " << ((livetogether(a[0], a[3])) ? "Yes!\n" : "Nope.\n");
	
	return 0;
}

Animal cheapest(string type, Animal a[], int size) {
	int lowidx = -1;
	bool found = 0; //True once animal of type "type" is found
	for (int i = 0; i < size; i++) {
		if (a[i].type == type) {
			if (!found) {
				found = 1;
				lowidx = i;
			}
			else if (a[i].price < a[lowidx].price)
					lowidx = i;
		}
	}
	
	
	if (!found) //error handling
	{
		cout << "No animals of type " << type << " found.\n";
		Animal err = {"", 0, -1, -1, type};
		return err;
	} else//(found)
		return a[lowidx];
}

bool livetogether(Animal a, Animal b) {
	return (a.type == b.type) ? true : false;
}