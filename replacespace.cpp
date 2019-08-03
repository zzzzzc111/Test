#include<iostream>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int size = 0;
		for (int i = 0; i<length; ++i) {
			if (str[i] == ' ') {
				size++;
			}
		}
		int length2 = length + size * 2;
		int j = length - 1;
		for (int i = length2 - 1; i >= 0; --i) {
			if (*(str + j) != ' ') {
				*(str + i) = *(str + j);
			}
			else if (*(str + j) == ' ') {
				*(str + i) = '0'; i--;
				*(str + i) = '2'; i--;
				*(str + i) = '%';
			}
			j--;
		}
	}
};