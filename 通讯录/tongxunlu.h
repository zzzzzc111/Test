#pragma once
#include<string>

struct _head {
	_head()
		: left(nullptr)
		, right(nullptr)
	{}
	Info *left;
	Info *right;
};
struct Info {

	Info* _left;
	Info* _right;
	char _name[10];
	char _xinbie[10];
	size_t _age;
	std::string _telephone;
	std::string _home;
};

class tongxunlu {
	
public:
	tongxunlu();
	void zhujiemian();
	void zeng(Info* head);
	void shan();
	void gai();
	void cha();
	size_t _size;
	_head head;
};