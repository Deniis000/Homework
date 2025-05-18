#include <iostream>
#include <cmath>

int main() {
	double weight, height, k;

	std::cout << "Enter your weight: ";
	std::cin >> weight;

	std::cout << "Enter your height: ";
	std::cin >> height;

	if (height <= 0) {
		std::cout << "Height must be greater than 0" << std::endl;
		return 1;
	}

	k = weight / pow(height, 2);
	
	cout << "Your body mass index: " << k << endl;

	if (k <= 27) {
		cout << "Status: normal" << endl;
	}
	else if (k <= 30) {
		cout << "Status: overweight" << endl;
	}
	else {
		cout << "Status: obesity, medical attention needed" << endl;
	}

	return 0;
}

