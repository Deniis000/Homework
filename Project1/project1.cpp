#include <iostream>
 
int main() {
	int a, b, c;
	a = 5;
	b = 6;
	
	c = a;
	a = b;
	b = c;

	int x1 = 7, x2 = 8;
	int &x3 = x1;
	x3 = 9;
       	int* px1;
	px1 = &x1;
	int* px2;
	px2 = &x2;
	int* px3;
	px3 = &x3;
	std::cout << "x1: "<<  x1  << "\nx2: " << x2  << "\nx3: "<< x3  << std::endl;
	std::cout << "px1: " << px1  << std::endl;
	std::cout << "px1: " << (long) px1  << std::endl;
	std::cout << "px2: " << px2  << std::endl;
        std::cout << "px2: " << (long) px2  << std::endl;
	std::cout << "px3: " << px3  << std::endl;
        std::cout << "px3: " << (long) px3  << std::endl;
	std::cout << "*px1: "<< *px1 <<  "\n*px2: " << *px2 << "\n*px3: " << *px3 << std::endl;
	
	int arr [5];
	for(char i = 0; i < 5; i = i + 1) {
		arr [i] = (i-3)*(i-3);
	}
	for(int i = 0; i < 5; i = i + 1) {
		std::cout << "i: " << arr[i] << std::endl;
	}
	std::cout << "*arr: " << *arr << std::endl;

	int* l = arr + 2;
	std::cout << arr << std::endl;
	std::cout << (long) arr  << std::endl;
	std::cout << l << std::endl;
	std::cout << (long) l  << std::endl;

	std::cout << "**********" << std::endl;
	std::cout << "size of bool: " << sizeof (bool) << std::endl;
	std::cout << "size of char: "  << sizeof (char) << std::endl;
	std::cout << "size of int: "  << sizeof (long int) << std::endl;
	std::cout << "size of float: " << sizeof (float) << std::endl;
	std::cout << "size of double: "  << sizeof (double) << std::endl;
	
	std::cout << "size of bool: " << sizeof (bool*) << std::endl;
        std::cout << "size of char: "  << sizeof (char*) << std::endl;
        std::cout << "size of int: "  << sizeof (long int*) << std::endl;
        std::cout << "size of float: " << sizeof (float*) << std::endl;
        std::cout << "size of double: "  << sizeof (double*) << std::endl;
	
	double d, *pd;
	pd = &d;
	std::cout << pd << std::endl;
	std::cout << (pd + 1) << std::endl;
	
	for(int i = 0; i < 5; i++) {
                std::cout << "i: " << *(arr + i) << std::endl;
        }
	
	int* k = arr + 4;
	std::cout << *k << std::endl;
	std::cout << k - arr << std::endl;
        std::cout << (long int)k - (long int)arr << std::endl;	
	
	for(int* i = arr; i < arr + 5; i++) {
		std::cout << *i << std::endl;
	}

	char pch [6] = "hello";
	for(int i = 0; i < 5; i++) {
		std::cout << pch[i] << std::endl;
	}
	while(*pch++) std::cout << *(pch);
	return 0;
}
