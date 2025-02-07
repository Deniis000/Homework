#include <iostream>

bool is_palindrome(int num) {
	int rev = 0, orig = num;
	while (num > 0) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return orig == rev;
}

void find_palindrome() {
	for (int i = 1; i < 100; i++) {
		if (is_palindrome(i)) {
			int square = i * i;
			if (is_palindrome(square)) {
				std::cout << i << "^2 = " << square << "\n";
			}
		}
	}
}

int main() {
	std::cout << "Palindrome numbers whose squares are also palindromes: \n";
	find_palindrome();
	return 0;
}
