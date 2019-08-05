#include"tongxunlu.h"
#include<iostream>
using namespace std;

template<class W>
tongxunlu::tongxunlu()
	:_size(0)
{
}
void tongxunlu::zhujiemian()
{
	size_t flag = 0;
	size_t n = 0;
	cout << "   1.进入主菜单"   << endl;
	cout << "   0.退出"         << endl;
	cin >> flag ;
	while (flag) {
		cout << "*******************************" << endl;
		cout << "*****  1. 增加联系人     ******" << endl;
		cout << "*****  2. 删除联系人     ******" << endl;
		cout << "*****  3. 修改信息       ******" << endl;
		cout << "*****  4. 查找联系人     ******" << endl;
		cout << "*****  5. 显示所有联系人 ******" << endl;
		cout << "*****  6. 清空联系人     ******" << endl;
		cout << "*****  7. 按姓名排序     ******" << endl;
		cout << "*****  0. 退出           ******" << endl;
		cout << "*******************************" << endl;
	}
	cin >> n;
	switch (n) {
	case 1:
		tongxunlu::zeng(head);
	case 2:
		tongxunlu::shan();
	case 3:
		tongxunlu::gai();
	case 4:
		tongxunlu::cha();
	case 5:
		tongxunlu::zeng();
	case 6:
		tongxunlu::zeng();
	case 7:
		tongxunlu::zeng();
	}
}

void tongxunlu::zeng(Info* _head)
{
	Info* people = (Info*)malloc(sizeof(Info));
	cout << "请输入要增加联系人的信息：" << endl;
	cout << "姓名：";
	cin >> people->_name;
	cout << endl;
	cout <<"性别： ";
	cin >> people->_xinbie;
	cout << endl << "年龄： ";
	cin >> people->_age;
	cout << endl << "电话： ";
	cin >> people->_telephone ;
	cout << endl << "住址： ";
	cin >> people->_home;
	people->_right = _head; 
	while (_head != nullptr) {
		_head = _head->_right;
	}
	_head->_right = people;
}