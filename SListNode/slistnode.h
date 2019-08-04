#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
// 值类型 
typedef int DataType;

typedef struct SListNode 
{
	DataType data; // 值 
	struct SListNode *pNext; // 指向下一个结点 
} SListNode;

// 初始化 
void SListInit(SListNode **ppFirst);

// 尾部插入 
void SListPushBack(SListNode** ppFirst, DataType data);

// 头部插入 
void SListPushFront(SListNode **ppFirst, DataType data);

// 尾部删除 
void SListPopBack(SListNode **ppFirst);

// 头部删除 
void SListPopFront(SListNode **ppFirst);

// 给定结点插入，插入到结点前 
void SListInsert(SListNode **ppFirst, SListNode *pPos, DataType data);

// 给定结点删除 
void SListErase(SListNode **ppFirst, SListNode *pPos);

// 按值删除，只删遇到的第一个 
void SListRemove(SListNode **ppFirst, DataType data);

// 按值删除，删除所有的 
void SListRemoveAll(SListNode **ppFirst, DataType data);

// 销毁 
void SListDestroy(SListNode **ppFirst);

// 按值查找，返回第一个找到的结点指针，如果没找到，返回 NULL 
SListNode *SListFind(SListNode *pFirst, DataType data);

void Print(SListNode *pFirst);




// 倒叙打印链表 
void ReversePrint(SListNode *pFirst);

// 逆置链表 
SListNode * ReverseList(SListNode **pFirst);

// 删除非尾无头链表 
void RemoveNodeNotTail(SListNode *pos);

// 无头链表前插入 
void InsertNoHead(SListNode *pos, int data);

/*
约瑟夫环
*/
SListNode * JocephCircle(SListNode *pFirst, int k);

// 冒泡排序 
void BubbleSort(SListNode *pFirst);


// 合并两个有序链表 
SListNode * MergeOrderedList(SListNode *p1First, SListNode *p2First);


// 遍历一次，找到中间结点 
SListNode * FindMid(SListNode *pFirst);

// 遍历一次，找到倒数第 k 个结点（k从1开始） 
SListNode * FindK(SListNode *pFirst, int k);

// 遍历一次，删除倒数第 k 个结点（k从1开始），不能用替换删除法 
void RemoveK(SListNode *pFirst, int k);
