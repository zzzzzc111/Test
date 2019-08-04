#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;
typedef struct SeqList
{
	DataType *data;//数据区 
	int sz;//有效个数 
	int capacity;//容量 
}SeqList, *pSeqList;


void SeqListInit(SeqList *ps)
{
	ps->sz = 0;
	ps->data = (DataType*)malloc(sizeof(DataType) * 10);
	ps->capacity = 10;
}

void SeqListPushFront(SeqList *ps, DataType data)
{
	assert(ps);
	if (ps->capacity == ps->sz)
	{
		ps->data = (DataType*)realloc(ps->data,sizeof(DataType) * (ps->capacity) * 2);
	}
	ps->capacity = ps->capacity * 2;
	int i = 0;
	for (i = ps->sz; i > 0; i--)
	{
		ps->data[i] = ps->data[i - 1];
	}
	ps->data[0] = data;
	ps->sz++;
}

void SeqListPrint(SeqList *ps)
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}