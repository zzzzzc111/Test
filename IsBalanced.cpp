#include<iostream>
#include<math.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

using namespace std;
class Solution {
public:
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL) {
			return true;
		}
		return GetDepth(pRoot) != -1;
	}
private:
	int GetDepth(TreeNode * root) {
		if (root == NULL)
			return 0;
		int left = GetDepth(root->left);
		if (left == -1)
			return -1;
		int right = GetDepth(root->right);
		if (right == -1) {
			return -1;
		}
		return fabs(left - right) > 1 ? -1 : (left>right?left+1:right+1);
	}
};