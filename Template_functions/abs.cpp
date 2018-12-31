#include <iostream>

template <typename T>
T abs(T a, T b);
//T must support =, >, and binary -

int main() {
	int ai = 1, bi = 2;
	char ac = 'A', bc = 'V';
	
	std::cout << "abs(1, 2) abs(2, 1) abs('A', 'V')\n";
	std::cout << abs(ai, bi) << ' ' << abs(ai, bi) << ' ' << abs(ac, bc) << std::endl;
	return 0;
}

template <typename T>
T abs(T a, T b) {
	return (a > b) ? a - b : b - a;
}