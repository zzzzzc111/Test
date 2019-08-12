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
	//获取文件大小
	fseek(fp,0,SEEK_END);
	ULL filesize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	//文件大小小于3个字节 不压缩
	if (filesize < 3)
		return;
	
	

	FILE * fOut = fopen("1.lzp","wb");
	assert(fOut);
	FILE * fOutF = fopen("2.zip","wb");
	assert(fOutF);
	std::string postFile = Filename.substr(Filename.rfind('.'));
	postFile += '\n';
	fwrite(postFile.c_str(),1,postFile.size(),fOut);

	 
	USH matchHead = 0;      //头部
	USH matchStart = 0;

	size_t chFlag = 0;
	USH bitcount = 0;

	//先读取一个滑动窗口的数据
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
			if (0 == matchHead)  //没有匹配串 直接写入
			{
				fputc(_pwin[_start], fOut);
				WriteFlag(fOutF, chFlag, bitcount, true);
			}
			else  //有匹配串
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
					while (curMatchLen--) {  //插入到哈希表
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


// 功能：在当前匹配链中找最长匹配

// 参数：
// hashHead: 匹配链的起始位置
// matchStart：最长匹配串在滑动窗口中的起始位置
// 返回值：最长匹配串的长度
USH BitZip::LongestMatch(USH hashHead, USH& matchStart)
{
	// 哈希链的最大遍历长度，防止造成死循环
	int chain_length = 256;
	// 始终保持滑动窗口为WSIZE，因为最小的超前查看窗口中有MIN_LOOKAHEAD的数据
	// 因此只搜索_start左边MAX_DIST范围内的串
	USH limit = _start > MAX_DIST ? _start - MAX_DIST : 0;
	// 待匹配字符串的最大位置
	// [pScan, strend]
	UCH* pScan = _pwin + _start;
	UCH* strend = pScan + MAX_MATCH - 1;
	// 本次链中的最佳匹配
	int bestLen = 0;
	UCH* pCurMatchStart;
	USH curMatchLen = 0;
	// 开始匹配	do
	{
		// 从搜索区hashHead的位置开始匹配
		pCurMatchStart = _pwin + hashHead;
		while (pScan < strend && *pScan == *pCurMatchStart)
		{
			pScan++;
			pCurMatchStart++;
		}
		// 本次匹配的长度和匹配的起始位置
		curMatchLen = (MAX_MATCH - 1) - (int)(strend - pScan);
		pScan = strend - (MAX_MATCH - 1);
		/*更新最佳匹配的记录*/
		if (curMatchLen > bestLen)
		{
			matchStart = hashHead;
			bestLen = curMatchLen;
		}
	} while ((hashHead = _ht._prev[hashHead & WMASK]) > limit
		&& --chain_length != 0);
	return curMatchLen;
}void BitZip::WriteFlag(FILE * fOut, size_t& flag,USH& bitcount,bool IsChar){	flag <= 1;	if (!IsChar)		flag |= 1;	bitcount++;	if (8 == bitcount) {		fputc(flag, fOut);		flag = 0;		bitcount = 0;	}}