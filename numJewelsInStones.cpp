//�����ַ���J ����ʯͷ�б�ʯ�����ͣ����ַ��� S������ӵ�е�ʯͷ��
//S ��ÿ���ַ�������һ����ӵ�е�ʯͷ�����ͣ�����֪����ӵ�е�ʯͷ���ж����Ǳ�ʯ��
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