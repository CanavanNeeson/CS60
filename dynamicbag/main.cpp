#include "dynamicbag.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
 
	dynamicBag b1, b2;
	b1.insert(11);
	b1.insert(99);
	b2.insert(45);
	b2.insert(49);
 	b2.insert(43);
	
	cout << b1.size() << endl;
	b1 += b2;
	cout << b1.size() << endl;
	cout << b2[0] << ", " << b2[1] << ", " << b2[2] << endl;
 	cout << b1[0] << ", " << b1[1] << ", " << b1[2] << ", " << b1[3] << ", " << b1[4] << endl;
	
	
	
	return 0;
}