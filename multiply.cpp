#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> multiply(const vector<int>& A) {
		vector<int> B;
		int size = A.size();
		B.resize(size);
		int i = 0;
		int j = 0;
		for (i = 0; i<size; ++i) {
			int left = 1;
			int right = 1;
			for (j = 0; j<i; ++j) {
				left = left * A[j];
			}
			for (j = i + 1; j<size; ++j) {
				right = right * A[j];
			}
			B[i] = left * right;
		}
		return B;
	}
};