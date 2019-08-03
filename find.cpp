#include<iostream>
#include<vector>

using namespace std;
bool Find(vector<vector<int>> arr, int n)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		if (n == arr[i][0] || n == arr[i][arr[0].size()-1])
			return true;
		else if (n > arr[i][0] && n < arr[i][arr[0].size() - 1])
		{
			for (int j = 0; j < arr[0].size(); ++j)
			{
				if (n == arr[i][j]) return true;
				else if (n > arr[i][j]) continue;
				else if (n < arr[i][j]) break;
			}
		}
	}
	return false;
}
int main()
{
	vector<vector<int>> arr = { {1,2},{3,4},{5,6} };
	cout << arr[0].size() << arr.size() << endl;
	return 0;
}