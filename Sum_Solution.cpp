//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字
//及条件判断语句（A?B:C）。

#include<iostream>

using namespace std;

class Solution {
public:
	int Sum_Solution(int n) {
		int sum = n;
		sum && (sum += Sum_Solution(n - 1));
		return sum;	
	}
};