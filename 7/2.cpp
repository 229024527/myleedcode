//Invert Binary Tree
//反转一颗二叉树
//	4		       4
//	/\		       /\
//     2  7	              7  2
//    /\  /\		     /\  /\
//   1 3  6 9		    9 6  3 1

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

///Definition for a binary tree node.
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
	TreeNode* invertTree(TreeNode* root){
		if(root == NULL)
			return NULL;

		invertTree( root->left );
		invertTree( root->right );
		swap( root->left, root->right );

		return root;
	}
};

int main(){

	return 0;
}








//递归
