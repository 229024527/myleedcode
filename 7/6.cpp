//二分搜索树：
//每个节点的键值大于左孩子;
//每个节点的键值小于右孩子;
//以左右孩子为根的子树仍为二分搜索树
//Lowest Common Ancestor of a Binary Search Tree
//给定一颗二分搜索树和两个节点，寻找这两个节点的最近公共祖先。
//- 如右图所示二分搜索树
//- 2和8的最近公共祖先为6
//- 2和4的最近公共祖先为2
//				6
//			   /         \
//			  2           8
//			 / \         / \
//			0   4       7   9
//			   / \
//			  3   5
#include <iostream>

using namespace std;

///Definition for a binary tree node.
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
		assert(p != NULL && q != NULL);
		if(root == NULL)
			return NULL;

		if(p->val < root->val && q->val < root->val)
			return lowestCommonAncestor( root->left, p, q);
		if(p->val < root->val && q->val < root->val)
			return lowestCommonAncestor( root->right, p, q);

		return root;
	}
};

int main(){

	return 0;
}
