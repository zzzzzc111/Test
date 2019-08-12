#pragma once
#include"lz77.h"

class HashTable {
public:
	HashTable(size_t size);  
	~HashTable();

	void HashFunc(USH& hashAddr, UCH ch);
	UCH H_SHIFT();
	void InsertString(USH& hashAddr, UCH ch, USH pos, USH& macthHead);
	void UpdateDictionary();

	USH * _prev;         //�ֵ���ʼλ��
	USH * _head;         //��������ʼλ��
	size_t _hashsize;    //��ϣ��ĳ���
};