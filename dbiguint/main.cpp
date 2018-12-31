#include <iostream>
#include "dbiguint.h"
using namespace std;

int main() {
	dbiguint h("11110"), i("123"), j("124"), k("99"), l("98"), m("98");
	dbiguint dif = h - i;
	
	cout << (h - i) << ' ' << (j - i) << ' ' << (k - l) << ' ' << (l - k) << endl;
	
	
	dbiguint hh = h, ii = i;
	cout << hh << ' ' << ii << endl;
	
	h -= k;
	cout << h << endl;
	h -= i;
	cout << h << endl;
	h -= j;
	cout << h << endl;
	h -= l;
	cout << h << endl;
	cout << (h < i) << (h > i) << (h == k) << (l == m) << (k < l) << (l >= k) << ( l!= m) << endl;
	cout << h.compare(i) << j.compare(h) << j.compare(j) << k.compare(h) << endl;
	
	dbiguint i1("2"), i2("23"), i3("999");
	i1 += i2;
	cout << i1 << endl;
	i1 += i3;
	cout << i1 << endl;
	
	return 0;
}