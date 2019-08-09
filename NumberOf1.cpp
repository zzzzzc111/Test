#include<iostream>

using namespace std;
int  NumberOf1(int n) {
	int size = 0;
	size_t a;
	if (n > 0) {
		a = n;
	}
	if (n < 0) {
		a = 4294967295 + n + 1;
	}
	while (a) {
		size += a % 2;
		a /= 2;
	}
	return size;
}

