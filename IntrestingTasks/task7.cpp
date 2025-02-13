#include <iostream>

bool prime(int num) {
	if (num < 2) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void pair_of_primes(int n) {
	for (int i = n; i <= 2 * n - 2; i++) {
		if (prime(i) && prime(i + 2)) {
			std::cout << i << " " << i + 2 << std::endl;
		}
	}
}

int main() {
	int n;
	std::cout << "Insert n: ";
	std::cin >> n;
	if (n < 2) {
		std::cout << "n must be >= 2" << std::endl;
		return 1;
	}
	std::cout << "\nPairs of prime numbers in the interval [" << n << ", " << 2 * n << "]:" << std::endl;
	pair_of_primes(n);

	return 0;
}
