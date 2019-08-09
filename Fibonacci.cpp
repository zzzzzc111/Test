#include<iostream>

using namespace std;
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 1 || n == 2) {
			return 1;
		}
		if (n == 0) {
			return 0;
		}
		n -= 2;
		int a = 1;
		int b = 1;
		int c = 2;
		while (n--) {
			a = b;
			b = c;
			c = a + b;
		}
		return b;
	}
};