#pragma once
#include<queue>
#include<vector>


template<class W>
struct TreeNode {
	TreeNode(W weight)
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		,_weight(weight)
	{}
	TreeNode<W> *_left;
	TreeNode<W> *_right;
	TreeNode<W> *_parent;
	W _weight;
};

template<class W>
struct compire {
	bool operator()(const TreeNode<W> * left,const TreeNode<W> * right) {
		return left->_weight < right->_weight;
	}
};

template<class W>
class Tree {
	
public:
	Tree()
		:_Root(nullptr)
	{}

	TreeNode<W> * GetRoot() {
		return _Root;
	}

	void chuangjianshu(const std::vector<W> &v,const W& wuxiao) {
		if (v.empty()) {
			return;
		}
		std::priority_queue<TreeNode<W>*, std::vector<TreeNode<W>*>, compire<W>> q;
		for (size_t i = 0; i < v.size(); ++i) {
			if (v[i] != wuxiao) {
				q.push(new TreeNode<W> (v[i]));
			}
		}
		while (1 < q.size()) {
			TreeNode<W>* left = q.top();
			q.pop();

			TreeNode<W>* right = q.top();
			q.pop();

			TreeNode<W>* parent = new TreeNode<W>(left->_weight + right->_weight);
			q.push(parent);
			parent->_left = left;
			left->_parent = parent;

			parent->_right = right;
			right->_parent = parent;
		}
	}

	~Tree()
	{
		destory(_Root);
	}
private:
	TreeNode<W> * _Root;
private:
	void destory(TreeNode<W>* &root)
	{
		if (root) {
			destory(root->_left);
			destory(root->_right);
			delete root;
			root = nullptr;
		}
	}
};



