#pragma once
#include<string>
#include<vector>





class CharInfo {
public:
	CharInfo(size_t count = 0)
		:_count(count)
	{}

	bool operator ==(const CharInfo& info) const
	{
		return _count == info._count;
	}

	bool operator !=(const CharInfo& info) const
	{
		return _count != info._count;
	}

	CharInfo operator +(const CharInfo& info) const
	{
		return CharInfo(_count + info._count);
	}

	bool operator >(const CharInfo& info) const
	{
		return _count > info._count;
	}
	char _Char;
	size_t _count;
	std::string _number;
};

class wenjianyasuo {
public:
	wenjianyasuo()
		
	{
		_count.resize(256);
		for (size_t i = 0; i < 256; ++i) {
			_count[i]._Char = (char)i;
		}
	}
	void yasuo(const std::string& wenjianmincheng);
	/*void jieyasuo();*/


private:
	std::vector<CharInfo> _count;
};