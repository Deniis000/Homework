#include <iostream>

int main() {
	int grade;
	std::cout << "Enter grade (2 to 12): ";
	std::cin >> grade;

	switch (grade) {
		case 12:
		case 11: std::cout << "Excellent" << std::endl; break;
		case 10:
		case 9:
		case 8: std::cout << "Good" << std::endl; break;
		case 7:
		case 6:
		case 5: std::cout << "Satisfactory" << std::endl; break;
		case 4:
		case 3:
		case 2: std::cout << "Bad" << std::endl; break;
		default: std::cout << "Error: grade must be between 2 and 12." << std::endl;
	}

	return 0;
}
