class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int n = array.size();
		int ret = array[0];
		int max = array[0];
		for (int i = 1; i<n; ++i) {
			ret = ret + array[i];
			if (ret > max) {
				max = ret;
			}
			if (ret < 0) {
				ret = 0;


			}


		}
		return max;
	}
};