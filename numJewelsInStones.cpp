//给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。
//S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int numJewelsInStones(string J, string S) {
	int Jewels = 0;
	/*for (int i = 0; i < S.size(); ++i) {
		if (J.find(S[i]) == 1) {
			Jewels++;
		}
	}*/
	int arr[256] = {0};
	for (int i = 0; i < J.size(); ++i)
	{
		arr[J[i]]++;
	}
	for (int i = 0; i < S.size(); ++i) {
		if (arr[S[i]]) {
			Jewels++;
		}
	}
	return Jewels;
}

//int main()
//{
//	string J = "aA";
//	string S = "aAAbbbb";
//	int size = numJewelsInStones(J,S);
//	
//	return 0;
//}