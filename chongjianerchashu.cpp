#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0)
			return;
		TreeNode *root;
		root->val = pre[0];
		vector<int>::iterator pos = pre.begin(  );
		pre.erase(pos);
		root->left = reConstructBinaryTree(pre,);
		root->right = reConstructBinaryTree();
	}
};