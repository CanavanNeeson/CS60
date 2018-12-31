#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void reverse(int a[], int first, int last);

int main() {

	srand(time(0));
	int arr[10];
	for (int i = 0; i < 10; i++)
		arr[i] = rand() % 100;

	cout << "Array:\t\t";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;

	reverse(arr, 0, 9);

	cout << "Reverse array: \t";
	for (int i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}

void reverse(int a[], int first, int last) {
	if (first < last) {
		int temp = a[first];
		a[first] = a[last];
		a[last] = temp;
		reverse(a, first + 1, last - 1);
	}

}
