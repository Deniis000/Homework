#include <iostream>
#include <cmath>

struct point {
        double x, y, z;

        double distance (struct point end) {
                double n = sqrt(pow(end.x - x, 2) + pow(end.y - y, 2) + pow(end.z - z, 2));
        return n;
	}
};

struct vector {
        int size, capacity;
        int* data;

	long index(int value) {
        	int ret_val = -1;
        	for (int i = 0; i < size; ++i)
                	if (data[i] == value)
                        	return i;
        	return ret_val;
	}
};

int main() {
	point a = {4, 10, 5};
	point b = {3, 4, 0};
    
	std::cout << "Distance: " << a.distance(b) << std::endl;
	
	vector v = {5, 10, new int[5]{1, 2, 3, 4, 5}};
	
	std::cout << "Index of 3: " << v.vector::index(3) << std::endl;
	std::cout << "Index of 7: " << v.vector::index(7) << std::endl;

	delete[] int;
	return 0;
}
