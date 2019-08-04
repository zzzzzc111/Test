#include"slistnode.h"

void test()
{
	SListNode *pfirst;
	SListInit(&pfirst);
	SListPushFront(&pfirst, 0);
	SListPushFront(&pfirst, 2);
	SListPushFront(&pfirst, 5);
	SListPushFront(&pfirst, 8);
	SListPushFront(&pfirst, 10);
	Print(pfirst);
	/*ReversePrint(pfirst);*/
	ReverseList(&pfirst);
	Print(pfirst);
}

int main()
{
	test();
	system("pause");
	return 0;
}