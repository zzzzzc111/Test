#pragma once
#include<string>
#include"HashTable.h"
#include"Commen.h"


class BitZip {
public:
	BitZip();
	~BitZip();

	void FileCompreassLZ77(const std::string& Filename);
	void UNFileCompreassLZ77();
private:
	USH LongestMatch(USH hashHead, USH& matchStart);
	void WriteFlag(FILE * fOut, size_t& flag, USH& bitcount, bool IsChar);
private:
	USH _start;
	UCH* _pwin;   //»¬¶¯´°¿Ú
	HashTable _ht;
};