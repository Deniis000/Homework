#include <iostream>
#include <cmath>

int main() {
	double a, b, c;
	std::cout << "Enter coefficients a, b, c\n";
	std::cout << "a = "; std::cin >> a;
	std::cout << "b = "; std::cin >> b;
	std::cout << "c = "; std::cin >> c;

	std::cout << "Equation: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;

	if (a != 0) {
		double D = b * b - 4 * a * c;
		if (D > 0) {
			std::cout << "Two real roots." << std::endl;
		}
		else if (D == 0) {
			std::cout << "One real root." << std::endl;
			}
		else {
			std::cout << "No real roots." << std::endl;
		}
	}
	else {
		if (b != 0) {
			std::cout << "Linear equation: one real root." << std::endl;
		}
		else {
			if (c == 0) {
				std::cout << "Infinite number of solutions." << std::endl;
			}
			else {
				std::cout << "No solution." << std::endl;
			}
		}
	}

	return 0;
}
