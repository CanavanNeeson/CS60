#include "lbiguint.h"
#include <iostream>
using namespace std;

int main() {
	lbiguint b1("3141"), b2;
	
	
	cout << b1 << endl;
	
	b2 = b1;

	cout << b2 << endl;
	
	return 0;
}