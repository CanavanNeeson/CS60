#include "lbiguint.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	lbiguint l0, l1("123");
	cout << l0.size() << ' ' << l1.size() << endl;
	cout << l1[0] << ' ' <<  l1[1] << ' ' << l1[2] << endl;
	cout << l0 << endl;
	cout << l1 << endl;
	
	return 0;
}