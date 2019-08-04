#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// ֵ���� 
typedef int DataType;

typedef struct SListNode 
{
	DataType data; // ֵ 
	struct SListNode *pNext; // ָ����һ����� 
} SListNode;

// ��ʼ�� 
void SListInit(SListNode **ppFirst);

// β������ 
void SListPushBack(SListNode** ppFirst, DataType data);

// ͷ������ 
void SListPushFront(SListNode **ppFirst, DataType data);

// β��ɾ�� 
void SListPopBack(SListNode **ppFirst);

// ͷ��ɾ�� 
void SListPopFront(SListNode **ppFirst);

// ���������룬���뵽���ǰ 
void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data);

// �������ɾ�� 
void SListErase(SListNode **ppFirst, SListNode *pPos);

// ��ֵɾ����ֻɾ�����ĵ�һ�� 
void SListRemove(SListNode **ppFirst, DataType data);

// ��ֵɾ����ɾ�����е� 
void SListRemoveAll(SListNode **ppFirst, DataType data);

// ���� 
void SListDestroy(SListNode **ppFirst);

// ��ֵ���ң����ص�һ���ҵ��Ľ��ָ�룬���û�ҵ������� NULL 
SListNode *SListFind(SListNode *pFirst, DataType data);

void Print(SListNode *pFirst);




// �����ӡ���� 
void ReversePrint(SListNode *pFirst);

// �������� 
SListNode * ReverseList(SListNode **pFirst);

// ɾ����β��ͷ���� 
void RemoveNodeNotTail(SListNode *pos);

// ��ͷ����ǰ���� 
void InsertNoHead(SListNode *pos, int data);

/*
Լɪ��
*/
SListNode * JocephCircle(SListNode *pFirst, int k);

// ð������ 
void BubbleSort(SListNode *pFirst);


// �ϲ������������� 
SListNode * MergeOrderedList(SListNode *p1First, SListNode *p2First);


// ����һ�Σ��ҵ��м��� 
SListNode * FindMid(SListNode *pFirst);

// ����һ�Σ��ҵ������� k ����㣨k��1��ʼ�� 
SListNode * FindK(SListNode *pFirst, int k);

// ����һ�Σ�ɾ�������� k ����㣨k��1��ʼ�����������滻ɾ���� 
void RemoveK(SListNode *pFirst, int k);
