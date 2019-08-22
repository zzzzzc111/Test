class Solution {
public:
	bool IsContinuous(vector<int> numbers) {
		if (numbers.size() == 0)
			return false;
		int arr[14] = { 0 };
		int size = numbers.size();
		for (int i = 0; i < size; ++i) {
			arr[numbers[i]]++;
		}
		int n = arr[0];
		size -= n;
		int i = 1;
		while (arr[i] == 0) {
			i++;
		}
		for (int j = i; j < numbers.size() + i; ++j) {
			if (arr[j] == 0)
				n--;
		}
		if (n < 0)
			return false;
		return true;
	}
};