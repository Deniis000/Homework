#include <iostream>

void sieve_of_eratosthenes(int n) {
	bool prime[1001];
	for (int i = 0; i <= n; i++) prime[i] = true;
	for (int j = 2; j * j <= n; j++) {
		if (prime[j]) {
			for (int i = j * j; i <= n; i += j)
				prime[i] = false;
		}
	}

	for (int j = 2; j <= n; j++) {
		if (prime[j])
			std::cout << j << " ";
	}
	std::cout << std::endl;
}

int main() {
	int n;
	std::cout << "Insert n: ";
	std::cin >> n;
	std::cout << "\nPrime numbers to " << n << ":" << std::endl;
	sieve_of_eratosthenes(n);
	return 0;
}
