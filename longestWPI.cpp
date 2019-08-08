//给你一份工作时间表?hours，上面记录着某一位员工每天的工作小时数。

//我们认为当员工一天中的工作小时数大于?8 小时的时候，那么这一天就是「劳累的一天」。

//所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。

//请你返回「表现良好时间段」的最大长度。

//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//class Solution {
//public:
//	int longestWPI(vector<int>& hours) {
//		vector<int> size;
//		size.resize(hours.size());
//		int length = 0;
//		int max = 0;
//		int flag,num;   // 8 8 8 8 8 8 1
//		flag = 0;
//		num = 0;
//		for (int i = 0; i < hours.size();++i) {
//			if (hours[i] < 8) flag = 0;
//			else flag = 1;
//			switch(flag)
//				case 
//			/*if (hours[i] > 8 || hours[i] == 8) {
//				while (hours[i] > 8 || hours[i] == 8) {
//					flag++;
//					i++;
//				}
//				size[num] = flag;
//				i--;
//			}
//			else if (hours[i] < 8) {
//				while (hours[i] < 8) {
//					flag--;
//					i++;
//				}
//				size[num] = flag;
//				i--;
//			}
//			flag = 0;
//			num++;
//			continue;*/
//		}
//	}
//};