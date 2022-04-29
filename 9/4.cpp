#include <iostream>
#include <vector>

using namespace std;

//你是一个专业的小偷，打算洗劫一条街的所有房子。每一个房子里都有不同价值的宝物，但是，如果你选择偷窃连续的两栋房子，就会触发报警系统。编程求出你最多可以偷窃价值多少的宝物？
// -如[3,4,1,2]，则返回6[3,(4),1,(2)]
// -如[4,3,1,2]，则返回6[(4),3,1,(2)]
// 暴力解法：检查所有房子的组合，对每一个组合，检查是否有相邻的房子，如果没有，记录其价值。找最大值O((2^n)*n)

class Solution{
private:
	//memo[i]表示考虑抢劫nums[i...n)所能获得的最大收益
	vector<int> memo;

	//考虑抢劫nums[index...nums.size())这个范围的所有房子
	int tryRob(vector<int> &nums, int index){
		if(index >= nums.size())
			return 0;
		if(memo[index] != -1)
			return memo[index];

		int res = 0;
		for(int i=index; i<nums.size(); i++)
			res = max(res, nums[i] + tryRob(nums, i+2));
		memo[index] = res;
		return res;
	}
public:
	int rob(vector<int>& nums)
	{
		memo = vector<int>(nums.size(), -1);
		return tryRob(nums, 0);
	}
};

int main(){
	return 0;
}

