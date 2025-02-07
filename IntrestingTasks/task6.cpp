#include <iostream>

void number_to_words(int num) {
	if (num == 0) {
		std::cout << "zero";
		return;
	}

	const char* ones[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	const char* teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteeen", "nineteen"};
	const char* tens[] = {"", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
	const char* hundreds[] = {"", "one hundred", "two hundred", "three hundred", "four hundred", "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred"};
	if (num >= 100) {
		std::cout << hundreds[num / 100] << " ";
		num %= 100;
	}
	if (num >= 10 && num < 20) {
		std::cout << teens[num - 10];
	}
	else {
		if (num >= 20) {
			std::cout << tens[num / 10] << " ";
		}
	if (num % 10 > 0) {
		std::cout << ones[num % 10];
		}
	}
}

int main() {
	int n;
	std::cout << "Insert number (≤1000): ";
	std::cin >> n;
	if (n < 0 || n > 1000) {
		std::cout << "Invalid number" << std::endl;
	}
	else {
		std::cout << "Number to words: ";
		number_to_words(n);
		std::cout << std::endl;
	}

	return 0;
}
