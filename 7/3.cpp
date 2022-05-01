//Path Sum
//给出一颗二叉树以及一个数字sum,判断在这颗二叉树上是否存在一条从根到叶子的路径，其路径上的所有节点和为sum。
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution{
public:
	bool hasPathSum(TreeNode* root, int sum){
		
		if(root==NULL)
			return false;

		if(root->left == NULL && root->right == NULL)	//叶子节点
			return root->val == sum;

		if(hasPathSum( root->left, sum-root->val))
			return true;

		if(hasPathSum( root->right, sum-root->val))
			return true;

		return false;
	}
};

int main(){

	return 0;
}
