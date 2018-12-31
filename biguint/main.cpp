//Canavan Neeson. HW 3. main.cpp
#include <iostream>
#include <string>
#include <cmath>
#include "biguint.h"
using namespace std;
int main(){
	biguint b;
	biguint b1("1031"), b2("554"), b3("134"), b4("134");
	
	cout << "Testing biguint::operator []\n";
	cout << b1[0] << b1[1] << b1[2] << b1[3] << b1[4] << b1[5] << b1[6] << endl;
	cout << b2[0] << b2[1] << b2[2] << b2[3] << b2[4] << b2[5] << b2[6] << endl;
	
	cout << "Testing boolean compare operators \n(1010)\n "
		<< (b1 > b2) << (b1 < b2) << (b < b1) << (b > b1) << endl;
	cout << "(011011)\n "
		<< (b1 <= b2) << (b1 >= b2) << (b <= b1) << (b >= b1) << (b3 >= b4) << (b3 <= b4) << endl;
	cout << "(0110)\n "
		<< (b1 == b2) << (b1 != b2) << (b3 == b4) << (b3 != b4) << endl;
	
	cout << "Testing biguint::operator << \n"
		<< b << endl << b1 << endl << b2 << endl << b3 << endl;
	
	
		
	biguint b1a(b1);
	biguint b1b = b1a;
	b2 += b3;
	
	cout << "Testing biguint::operator += and + \n"
		<< b2 << endl
		<< b1 - b2 << endl;
	
	
	cout << "Testing biguint::operator -= and - \n";
	cout << b1 << endl;
	b1 -= b3;
	cout << b1 << endl;
	
	
	cout << "Testing biguint::toString()\n";
	cout << b.toString() << endl
		<< b1.toString() << endl;
	
	return 0;
}