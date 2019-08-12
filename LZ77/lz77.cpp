#include<iostream>
#include"lz77.h"
#include<assert.h>

BitZip::BitZip()
	:_pwin(new UCH[WSIZE*2])
	,_start(0)
	,_ht(WSIZE)
{}

BitZip::~BitZip() 
{
	if (_pwin) {
		delete[] _pwin;
	}
}

void BitZip::FileCompreassLZ77(const std::string& Filename) {
	FILE* fp = fopen(Filename.c_str(),"rb");
	if (nullptr == fp) {
		std::cout << "error for open file" << std::endl;
	}
	//��ȡ�ļ���С
	fseek(fp,0,SEEK_END);
	ULL filesize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	//�ļ���СС��3���ֽ� ��ѹ��
	if (filesize < 3)
		return;
	
	

	FILE * fOut = fopen("1.lzp","wb");
	assert(fOut);
	FILE * fOutF = fopen("2.zip","wb");
	assert(fOutF);
	std::string postFile = Filename.substr(Filename.rfind('.'));
	postFile += '\n';
	fwrite(postFile.c_str(),1,postFile.size(),fOut);

	 
	USH matchHead = 0;      //ͷ��
	USH matchStart = 0;

	size_t chFlag = 0;
	USH bitcount = 0;

	//�ȶ�ȡһ���������ڵ�����
	/*while (1) {*/
	USH HashAddr = 0;

	while (1) {
		size_t rdsize = fread(_pwin, 1, WSIZE * 2, fp);
		if (0 == rdsize) {
			return;
		}
		for (size_t i = 0; i < MIN_MATCH-1; ++i) {
			_ht.HashFunc(HashAddr, _pwin[i]);
			//_ht.InsertString(HashAddr, _pwin[_start + 2], _start, matchHead);
			
			//WriteFlag(fOutF, chFlag, bitcount, true);
		}

		while (1)
		{
			_ht.InsertString(HashAddr, _pwin[_start + 2], _start, matchHead);
			if (0 == matchHead)  //û��ƥ�䴮 ֱ��д��
			{
				fputc(_pwin[_start], fOut);
				WriteFlag(fOutF, chFlag, bitcount, true);
			}
			else  //��ƥ�䴮
			{
				USH curMatchDist = 0;
				USH curMatchLen = LongestMatch(matchHead, curMatchDist);
				if (curMatchLen == 0) {
					fputc(_pwin[_start], fOut);
					WriteFlag(fOutF, chFlag, bitcount, true);
				}
				else {
					fputc(curMatchDist, fOut);
					fputc(curMatchLen, fOut);

					WriteFlag(fOutF, chFlag, bitcount, false);

					curMatchLen -= 1;
					while (curMatchLen--) {  //���뵽��ϣ��
						++_start;
						_ht.InsertString(HashAddr, _pwin[_start + 2], _start, matchHead);
					}
				}
				
			}
			++_start;
		}

	}
	//}
	fclose(fp);
	fclose(fOut);
	fclose(fOutF);
}


// ���ܣ��ڵ�ǰƥ���������ƥ��

// ������
// hashHead: ƥ��������ʼλ��
// matchStart���ƥ�䴮�ڻ��������е���ʼλ��
// ����ֵ���ƥ�䴮�ĳ���
USH BitZip::LongestMatch(USH hashHead, USH& matchStart)
{
	// ��ϣ�������������ȣ���ֹ�����ѭ��
	int chain_length = 256;
	// ʼ�ձ��ֻ�������ΪWSIZE����Ϊ��С�ĳ�ǰ�鿴��������MIN_LOOKAHEAD������
	// ���ֻ����_start���MAX_DIST��Χ�ڵĴ�
	USH limit = _start > MAX_DIST ? _start - MAX_DIST : 0;
	// ��ƥ���ַ��������λ��
	// [pScan, strend]
	UCH* pScan = _pwin + _start;
	UCH* strend = pScan + MAX_MATCH - 1;
	// �������е����ƥ��
	int bestLen = 0;
	UCH* pCurMatchStart;
	USH curMatchLen = 0;
	// ��ʼƥ��	do
	{
		// ��������hashHead��λ�ÿ�ʼƥ��
		pCurMatchStart = _pwin + hashHead;
		while (pScan < strend && *pScan == *pCurMatchStart)
		{
			pScan++;
			pCurMatchStart++;
		}
		// ����ƥ��ĳ��Ⱥ�ƥ�����ʼλ��
		curMatchLen = (MAX_MATCH - 1) - (int)(strend - pScan);
		pScan = strend - (MAX_MATCH - 1);
		/*�������ƥ��ļ�¼*/
		if (curMatchLen > bestLen)
		{
			matchStart = hashHead;
			bestLen = curMatchLen;
		}
	} while ((hashHead = _ht._prev[hashHead & WMASK]) > limit
		&& --chain_length != 0);
	return curMatchLen;
}void BitZip::WriteFlag(FILE * fOut, size_t& flag,USH& bitcount,bool IsChar){	flag <= 1;	if (!IsChar)		flag |= 1;	bitcount++;	if (8 == bitcount) {		fputc(flag, fOut);		flag = 0;		bitcount = 0;	}}