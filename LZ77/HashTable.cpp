#include"HashTable.h"
#include<string>


const USH HASH_BITS = 15;        // ��ϣͰ�ĸ���
const USH HASH_SIZE = (1 << HASH_BITS);         // ��ϣ��Ĵ�С2^15
const USH HASH_MASK = HASH_SIZE - 1;       // ��ϣ���� 111111111111111(15��1)


HashTable::HashTable(size_t size)       //Ϊ��ϣ������ռ�
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


void HashTable::HashFunc(USH& hashAddr, UCH ch)   //�ҹ�ϣ��ַ
{
	hashAddr = (((hashAddr) << H_SHIFT()) ^ (ch)) & HASH_MASK;
}

UCH HashTable::H_SHIFT()
{
	return (HASH_BITS + MIN_MATCH - 1) / MIN_MATCH;
}

void HashTable::InsertString(USH& hashAddr, UCH ch, USH pos, USH& macthHead)  //����
{
	// �����ϣ��ַ
	HashFunc(hashAddr, ch);
	// ����ѹ���Ĳ��Ͻ��У�pos�϶������WSIZE������WMASK��֤��Խ��
	_prev[pos & WMASK] = _head[hashAddr];    
	macthHead = _head[hashAddr];
	_head[hashAddr] = pos;

}


void HashTable::UpdateDictionary()
{
	// ����_head����
	for (int i = 0; i < HASH_SIZE; i++)
	{
		if (_head[i] >= WSIZE)
			_head[i] -= WSIZE;
		else
			_head[i] = 0;
	}
	// ����prev����
	for (int i = 0; i < WSIZE; i++)
	{		if (_prev[i] >= WSIZE)
			_prev[i] -= WSIZE;
		else
			_prev[i] = 0;
	}
}

