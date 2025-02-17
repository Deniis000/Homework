#include <iostream>

int* arr;

void magic_vectors(int index, int n, int sum, int product, int last) {
	if (index == n) {
		if (sum == product) {
			for (int i = 0; i < n; i++) {
				std::cout << arr[i] << (i == n - 1 ? "\n" : ", ");
			}
		}
		return;
	}
	for (int i = last; i <= 2 * n; i++) {
		arr[index] = i;
		magic_vectors(index + 1, n, sum + 1, product * i, i);
	}
}
int main() {
	int n;
	std::cout << "Insert N: ";
	std::cin >> n;
	if (n < 1) {
		std::cout << "N must be >= 1" << std::endl;
		return 1;
	}

	arr = new int[n];
	std::cout << "Magic vectors for N = " << n << ":\n";
	magic_vectors(0, n, 0, 1, 1);
	
	delete[] arr;

	return 0;
}
