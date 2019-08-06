#include<iostream>
//����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ��
//��������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL) {
			return 0;
		}
		int left = TreeDepth(pRoot->left) + 1;
		int right = TreeDepth(pRoot->right) + 1;
		return left>right ? left : right;
	}
};