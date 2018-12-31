#include <iostream>
#include <string>
#include <map>
using namespace std;

template <typename T1, typename T2>
T1 frequent(T1 a[], T2 size);
//T1 must support =
//T2 must support =, ++, >

int main() {
	const int size = 8;
	string strArr[size] = {"hello", "my", "three", "hello", "my", "my", "my", "hello"};
	int intArr[size] = {1, 2, 3, 4, 5, 4, 6, 9};
	
	cout << frequent(strArr, size) << endl;
	cout << frequent(intArr, size) << endl;
	
	return 0;
}

template <typename T1, typename T2>
T1 frequent(T1 a[], T2 size) {
	map<T1, T2> found;
	for (T2 i = 0; i < size; i++)
		found[a[i]]++;
	
	T1 greatestObj;
	T2 greatest = 0;
	for (auto e:found) 
		if (e.second > greatest) {
			greatestObj = e.first;
			greatest = e.second;
		}
	return greatestObj;
}