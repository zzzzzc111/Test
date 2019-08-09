#include<iostream>

using namespace std;
class Solution {
public:
	int rectCover(int number) {
		if (number < 1) {
			return 0;
		}
		if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		int a = 1;
		int b = 2;
		int c = 3;
		number -= 3;
		while (number--) {
			a = b;
			b = c;
			c = a + b;
		}
		return c;
	}
};

