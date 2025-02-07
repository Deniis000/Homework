#include <iostream>

void factorization(int n) {
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			std::cout << i << " ";
			n /= i;
		}
	}
	if (n > 1)
		std::cout << n;
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "Insert number: ";
	std::cin >> n;
	std::cout << "\nFactorization: " << std::endl;
	factorization(n);

	return 0;
}
