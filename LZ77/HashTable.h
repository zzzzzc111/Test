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

	USH * _prev;         //字典起始位置
	USH * _head;         //索引表起始位置
	size_t _hashsize;    //哈希表的长度
};