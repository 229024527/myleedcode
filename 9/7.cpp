//给定一个非空素组，其中所有的柱子都是正整数。问是否可以将 这个数组的元素分成两部分，使得每部分的数字和相等？
//-如对[1,5,11,5],可以分成[1,5,5]和[11]两部分，元素和相等，返回true
//-如对[1,2,3,5],无法分成元素和相等的两部分，返回false
//典型的背包问题，在n个物品中选出一定物品，填满sum/2的背包
//F(n, C)考虑将n个物品填满容量位C的背包
//F(i, c) = F(i-1, c) || F(i-1, c-w(i))
//时间复杂度：O(n*sum/2) = O(n*sum)
//
//-最多有200个数字
//-每个数字最大为100
//-所有数字和为20000；背包最大为10000；n*sum/2=100*10000 = 100万
#include <iostream>

using namespace std;

class Solution{
private:
	//memo[i][c]表示使用索引位[0...i]的这些元素，是否可以完全填充一个容量为c的背包
	//-1表示为未计算；0表示不可以填充；1表示可以填充
	vector<vector<int>> memo;

	//使用nums[0...index],是否可以完全填充一个容量位sum的背包
	bool tryPartition(const vector<int> &nums, int index, int sum){
		if(sum == 0)
			return true;

		if(sum < 0 || index < 0)
			return false;

		if(memo[index][sum] != -1)
			return memo[index][sum] == 1;

		memo[index][sum] = ( tryPartition(nums, index-1, sum) || 
			tryPartition(nums, index-1, sum-nums[index])) ? 1:0;

		return memo[index][sum] == 1;
	}
public:
	bool canPartition(vector<int>& nums){
		int sum = 0;
		for(int i=0; i<nums.size(); i++)
		{
			assert(nums[i] > 0);
			sum += nums[i];
		}

		if( sum%2 != 0)
			return false;

		memo = vector<vector<int>>(nums.size(), vector<int>(sum/2+1, -1));

		return tryPartition(nums, nums.size()-1, sum/2);
	}
};

int main(){
	return 0;
}
