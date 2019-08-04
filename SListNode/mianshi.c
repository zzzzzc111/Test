#include"slistnode.h"

void ReversePrint(SListNode *pFirst)
{
	if (pFirst == NULL)
	{
		return;
	}
	
	if (pFirst->pNext != NULL)
	{
		ReversePrint(pFirst->pNext);
	}
	printf("%d ", pFirst->data);
}