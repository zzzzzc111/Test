#pragma once
typedef unsigned short USH;  //������
typedef unsigned char UCH;   //�ַ�
typedef unsigned long long ULL;  //������

static USH WMASK = 32 * 1024 - 1;    //������������
static USH MIN_MATCH = 3;           //��Сƥ�䳤��
static USH MAX_DIST = WMASK;

static size_t WSIZE = 32 * 1024;    //�������ڴ�С