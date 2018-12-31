#include "node.h"
#include "lbag.h"
#include <iostream>

using namespace std;

int main() {
	lbag<int> a, b;
	
	a.insert(3);
	a.insert(2);
	a.insert(1);
	
	b.insert(5);
	b.insert(4);
	
// 	cout << a << endl;
// 	cout << b << endl;
// 	
	cout << (a + b) << endl;
	
	a += b;
	cout << a << endl;
	
	a.insert(5);
	a.insert(5);
	
	cout << a << endl;
	
	cout << a.erase_one(3) << ' ' << a.erase_one(5) << endl;
	
	cout << a << endl;
	
	cout << a.erase(5) << endl;
	
	cout << a << endl;
	
	return 0;
}