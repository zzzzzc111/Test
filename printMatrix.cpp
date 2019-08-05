//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> arr;
		int hang = matrix[0].size();
		int lie = matrix.size();
		arr.resize(hang*lie);
		int num = 0;
		int i = 0;
		int j = 0;
		int min = hang;
		if (lie < hang)min = lie;
		int cishu = (min + 1) / 2;
		while (i<cishu - 1) {
			if (j / 4 == i) {
				switch (j % 4) {
				case 0:
					for (int x = i; x < hang - i - 1; x++) {
						arr[num++] = matrix[i][x];
					}
					++j;
					continue;
				case 1:
					for (int y = i; y < lie - i - 1; y++) {
						arr[num++] = matrix[y][hang - i - 1];
					}
					++j;
					continue;
				case 2:
					for (int x = hang - i - 1; x > i; --x) {
						arr[num++] = matrix[lie - i - 1][x];
					}
					++j;
					continue;
				case 3:
					for (int y = lie - i - 1; y > i; --y) {
						arr[num++] = matrix[y][i];
					}
					++j;
					continue;
				}
			}
			++i;
		}
		if (hang > lie || hang == lie) {
			if (lie > 2 * i) {
				for (int x = i; x < hang - i; x++) {
					arr[num++] = matrix[i][x];
				}
			}
			if (lie > 2 * i + 1) {
				for (int x = hang - i - 1; x > i - 1; --x) {
					arr[num++] = matrix[lie - i - 1][x];
				}
			}
		}
		else if (lie > hang) {
			if (hang < (i + 1) * 2) {
				for (int y = i; y < lie - i; y++) {
					arr[num++] = matrix[y][i];
				}
			}
			else {
				arr[num++] = matrix[i][i];
				for (int y = i; y < lie - i; y++) {
					arr[num++] = matrix[y][i + 1];
				}
				for (int y = lie - i - 1; y >i; y--) {
					arr[num++] = matrix[y][i];
				}
			}
		}
		return arr;
	}
};