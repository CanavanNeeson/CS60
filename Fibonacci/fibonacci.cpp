#include <iostream>

int sequence(int);

int main() {

	std::cout << sequence(0) << ' ' << sequence(1) << ' ' << sequence(2) << ' ' << sequence(3) << ' ' << sequence(4) << ' ' << sequence(5) << std::endl;

	return 0;
}

int sequence(int n) {
	if (n == 0 || n == 1)
		return 1;
	else
		return sequence(n-1) + sequence(n - 2);
}
