#include<iostream>

using namespace std;
class Solution {
public:
	int jumpFloorII(int number) {
		//1 1 2 4 8 16
		//1 1         1  1*(1-0)/1
		//1 2 1       1  1*(2-0)/1   a*(2-1)/2  
		//1 3 3 1     1  1*(3-0)/1   a*(3-1)/2  a*(3-2)/3
		//1 4 6 4 1   1  1*(4-0)/1   a*(4-1)/2  a*(4-2)/3  a*(4-3)/4  
		//num = 2^(number-1);
		if (number == 1)   
			return 1;
		int num = 1;
		int a = 1;
		int n = number - 1;
		for (int i = 0; i < n; ++i) {
			a = a * (n - i) / (i + 1);
			num += a;
		}
		return num;
	}
};