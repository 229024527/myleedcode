//给出一颗二叉树以及一个数字sum,判断在这颗二叉树上存在多少条路径，其路径上的所有节点和为sum。
//-其中路径不一定要起始于根节点；终止于叶子节点。
//-路径可以从任意节点开始，但是只能是向下走的。
//
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
	//在以root为根节点的二叉树中，寻找和为sum的路径，返回这样的路径个数
	int pathSum(TreeNode* root, int sum){
		if( root == NULL )
			return 0;

		int res = findPath( root, sum );
		res += pathSum( root->left, sum);
		res += pathSum( root->right, sum);

		return res;
	}

private:
	//在以node为根节点的二叉树中，寻找包含node的路径，和为sum
	//返回这样的路径个数
	int findPath(TreeNode* node, int sum){
		if( node == NULL )
			return 0;

		int res = 0;
		if( node->val == num)
			res += 1;

		res += findPath(node->left, num - node->val );
		res += findPath(node->right, num - node->val );

		return res;
	}
};

int main(){

	return 0;
}
