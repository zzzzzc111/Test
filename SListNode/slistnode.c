#include"slistnode.h"

void SListInit(SListNode **ppFirst)
{
	*ppFirst = NULL;
}

void SListPushBack(SListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;
	node->pNext = NULL;
	SListNode *ret = *ppFirst;
	if (ret == NULL)
	{
		*ppFirst = node;
		return;
	}
	while (ret->pNext)
	{
		ret = ret->pNext;
	}
	ret ->pNext = node;
}

void SListPushFront(SListNode** ppFirst, DataType data)
{
	assert(ppFirst);
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;
	node->pNext = *ppFirst;
	*ppFirst = node;
}

void Print(SListNode *pFirst)
{
	SListNode *ret = pFirst;
	
	while (ret)
	{
		printf("%d ", ret->data);
		ret = ret->pNext;
	}
	printf("\n");
}

void SListPopBack(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);
	SListNode *ret = *ppFirst;
	if (ret->pNext == NULL)
	{
		free(ret);
		ret = NULL;
		return;
	}
	while (ret->pNext->pNext != NULL)
	{
		ret = ret->pNext;
	}
	free(ret->pNext);
	ret->pNext = NULL;
}

void SListPopFront(SListNode **ppFirst)
{
	assert(ppFirst);
	assert(*ppFirst);
	SListNode *ret = *ppFirst;
	if (ret->pNext == NULL)
	{
		free(ret);
		ret = NULL;
		return;
	}
	*ppFirst = ret->pNext;
	free(ret);
}

void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data)
{
	assert(ppFirst);
	assert(*ppFirst);
	SListNode *ret = *ppFirst;
	SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;
	node->pNext = pPos;
	while (ret->pNext != pPos)
	{
		ret = ret->pNext;
	}
	ret->pNext = node;
}

void SListErase(SListNode **ppFirst, SListNode *pPos)
{
	assert(ppFirst);
	SListNode *ret = *ppFirst;
	if (pPos == ret)
	{
		ret = ret->pNext;
		free(pPos);
		return;
	}
	while (ret->pNext!=pPos)
	{
		ret = ret->pNext;
	}
	ret->pNext = pPos->pNext;
	free(pPos);
}

void SListRemove(SListNode **ppFirst, DataType data)
{
	assert(ppFirst);
	SListNode *ret = *ppFirst;
	if (ret->data == data)
	{
		*ppFirst = ret->pNext;
		free(ret);
		return;
	}
	while (ret->pNext->data != data)
	{
		ret = ret->pNext;
	}
	SListNode *node = ret->pNext;
	ret->pNext = node->pNext;
	free(node);
}

void SListRemoveAll(SListNode **ppFirst, DataType data)
{
	assert(ppFirst);
	SListNode *ret = *ppFirst;
	while (ret->data == data)
	{
		*ppFirst = ret->pNext;
		free(ret);
		ret = *ppFirst;
		if (ret == NULL)
		{
			return;
		}
	}
	while (ret->pNext)
	{
		if (ret->pNext->data == data)
		{
			SListNode *node = ret->pNext;
			ret->pNext = node->pNext;
			free(node);
		}
		
		else
			ret = ret->pNext;
	}
}

void SListDestroy(SListNode **ppFirst)
{
	assert(ppFirst);
	SListNode *first = *ppFirst;
	if (first == NULL)
	{
		return;
	}
	SListNode *second = first->pNext;
	while (second)
	{
		free(first);
		first = second;
		second = second->pNext;
	}
	free(first);
	*ppFirst = NULL;
}

SListNode *SListFind(SListNode *pFirst, DataType data)
{
	SListNode *node = pFirst;
	while (node!=NULL&&node->data!=data)
	{
		node = node->pNext;
	}
	return(node);
}

SListNode * ReverseList(SListNode **pFirst)
{
	assert(pFirst);
	SListNode *first = *pFirst;
	SListNode *second = first;
	SListNode *ret = NULL;
	while (second)
	{
		ret = first;
		first = second;
		second = second->pNext;
		first->pNext = ret;
	}
	SListNode *node = *pFirst;
	*pFirst = first;
	node->pNext = NULL;
	return *pFirst;
}
