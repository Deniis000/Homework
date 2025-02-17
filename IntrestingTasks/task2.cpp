#include <iostream>

void pascal_triangle(unsigned int n) {
	for (unsigned int i = 0; i < n; i++) {
		unsigned int num = 1;
		for (unsigned int j = 0; j <= n; j++) {
			std::cout << num << " ";
			num = num * (i - j) / (j + 1);
		}
		std::cout << std::endl;
	}
}

int main() {
	unsigned int n;
	std::cout << "Insert n: ";
	std::cin >> n;
	std::cout << "\nPascal triangle: " << std::endl;
	pascal_triangle(n);

	return 0;
}
