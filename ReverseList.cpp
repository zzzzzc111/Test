//输入一个链表，反转链表后，输出新链表的表头。
#include<iostream>

using namespace std;
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode * ReverseList(ListNode* pHead) {
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		ListNode* first = pHead;
		ListNode* second = first -> next;
		ListNode* third = second -> next;
		first->next = NULL;
		while (third) {
			second->next = first;
			first = second;
			second = third;
			third = third->next;
		}
		second->next = first;
		return second;
	}
};

int main()
{

	return 0;
}