#include <iostream>

void pascal_triangle(int n) {
	for (int i = 0; i < n; i++) {
		int num = 1;
		for (int j = 0; j <= n; j++) {
			std::cout << num << " ";
			num = num * (i - j) / (j + 1);
		}
		std::cout << std::endl;
	}
}

int main() {
	int n;
	std::cout << "Insert n: ";
	std::cin >> n;
	std::cout << "\nPascal triangle: " << std::endl;
	pascal_triangle(n);

	return 0;
}
