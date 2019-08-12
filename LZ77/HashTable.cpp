#include"HashTable.h"
#include<string>


const USH HASH_BITS = 15;        // 哈希桶的个数
const USH HASH_SIZE = (1 << HASH_BITS);         // 哈希表的大小2^15
const USH HASH_MASK = HASH_SIZE - 1;       // 哈希掩码 111111111111111(15个1)


HashTable::HashTable(size_t size)       //为哈希表申请空间
	: _prev(new USH[size * 2])
	, _head(_prev + size)
	, _hashsize(size * 2)
{
	memset(_head, 0, sizeof(USH)*size);
}

HashTable::~HashTable() {
	if (_prev) {
		delete[] _prev;
		_prev = nullptr;
	}
}


void HashTable::HashFunc(USH& hashAddr, UCH ch)   //找哈希地址
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

UCH HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

void HashTable::InsertString(USH& hashAddr, UCH ch, USH pos, USH& macthHead)  //插入
{
	// 计算哈希地址
	HashFunc(hashAddr, ch);
	// 随着压缩的不断进行，pos肯定会大于WSIZE，与上WMASK保证不越界
	_prev[pos & WMASK] = _head[hashAddr];    
	macthHead = _head[hashAddr];
	_head[hashAddr] = pos;

}


void HashTable::UpdateDictionary()
{
	// 更新_head数组
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if (_head[i] >= WSIZE)
			_head[i] -= WSIZE;
		else
			_head[i] = 0;
	}
	// 更新prev数组
	for (int i = 0; i < WSIZE; i++)
	{		if (_prev[i] >= WSIZE)
			_prev[i] -= WSIZE;
		else
			_prev[i] = 0;
	}
}

