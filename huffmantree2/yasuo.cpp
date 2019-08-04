
#include"wenjianyasuo.h"
#include<iostream>
#include"huffmantree.hpp"

void GetCharNumber(TreeNode<CharInfo>* root, std::vector<CharInfo> _count)
{
	if (nullptr == root)
		return;
	GetCharNumber(root->_left, _count);
	GetCharNumber(root->_right, _count);
	if (root->_left == nullptr&&root->_right == nullptr) {
		std::string &count = _count[root->_weight._Char]._number;
		while (root != nullptr) {
			if (root == root->_parent->_left) {
				count += '0';
			}
			else if (root == root->_parent->_right) {
				count += '1';
			}
			root = root->_parent;
		}
		std::reverse(count.begin(), count.end());
	}
}

void wenjianyasuo::yasuo(const std::string& wenjianmincheng)
{
	FILE* fIn = fopen("wenjianmincheng.c_str()", "r");
	if (fIn == nullptr) {
		return;
	}
	char* rd = new char[1024];
	while (1) {
		size_t read = fread(rd, 1, 1024, fIn);
		if (0 == read) {
			break;
		}
		for (size_t i = 0; i < read; ++i) {
			_count[rd[i]]._count++;
		}
	}
	Tree<CharInfo> tree;
	tree.chuangjianshu(_count,CharInfo(0));
	/*GetCharNumber(tree.GetRoot(),_count);*/

	delete rd;
	rd = nullptr;
}

