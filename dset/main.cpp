#include "dorderedset.h"
#include <iostream>
using namespace std;

int main() {
	const int size = 6;
	int a[size] = {3, 4, 5, 6, 8, 7};
	
	dOrderedSet d1(a, size);	
	cout << d1.size() << endl;
	
	cout << d1[0] <<  ' ' << d1[1] <<' ' <<  d1[2] << ' ' << d1[3] << ' ' << d1[4] << ' ' << d1[5] << endl << endl;
	
	int a2[size] = {1,1,1,1,1,1};
	dOrderedSet d2(a2, size);
	cout << d2.size() << endl;
	cout << d2[0] << endl << endl;
	
	int a3[size] = {6,4,3,2,1,-1};
	dOrderedSet d3(a3, size);
	cout << d3.size() << endl;
	cout << d3[0] <<  ' ' << d3[1] <<' ' <<  d3[2] << ' ' << d3[3] << ' ' << d3[4] << ' ' << d3[5] << endl;
	

	
	
	return 0;
}