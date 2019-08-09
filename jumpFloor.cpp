#include<iostream>

using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		/*if (number == 1) {
			return 1;
		}
		if (number == 2) {
			return 2;
		}
		return(jumpFloor(number - 1) + jumpFloor(number - 2));*/
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
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