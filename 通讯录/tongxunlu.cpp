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
	cout << "   1.�������˵�"   << endl;
	cout << "   0.�˳�"         << endl;
	cin >> flag ;
	while (flag) {
		cout << "*******************************" << endl;
		cout << "*****  1. ������ϵ��     ******" << endl;
		cout << "*****  2. ɾ����ϵ��     ******" << endl;
		cout << "*****  3. �޸���Ϣ       ******" << endl;
		cout << "*****  4. ������ϵ��     ******" << endl;
		cout << "*****  5. ��ʾ������ϵ�� ******" << endl;
		cout << "*****  6. �����ϵ��     ******" << endl;
		cout << "*****  7. ����������     ******" << endl;
		cout << "*****  0. �˳�           ******" << endl;
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
	cout << "������Ҫ������ϵ�˵���Ϣ��" << endl;
	cout << "������";
	cin >> people->_name;
	cout << endl;
	cout <<"�Ա� ";
	cin >> people->_xinbie;
	cout << endl << "���䣺 ";
	cin >> people->_age;
	cout << endl << "�绰�� ";
	cin >> people->_telephone ;
	cout << endl << "סַ�� ";
	cin >> people->_home;
	people->_right = _head; 
	while (_head != nullptr) {
		_head = _head->_right;
	}
	_head->_right = people;
}