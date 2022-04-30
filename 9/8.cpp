//给定一个整数序列，求其中的最长上升子序列的长度。
//-如[10,9,2,5,3,7,101,18],其最长上升子序列的长度为4
//-最长上升子序列为[2,5,7,101]
//-注意1：什么是子序列？
//-注意2：什么是上升？
//-注意3：一个序列可能有多个最长上升子序列；但这个最长的长度只有1个
//暴力解法：选择所有的子序列进行判断。O((2^n)*n)
//LIS(longest increasing subsequence)
//LIS(i)表示以第i个数字为结尾的最长上升子序列的长度
//LIS(i)表示[0...i]的范围内，选择数字nums[i]可以获得的最长上升子序列的长度
//LIS(i) = max(1 + LIS(j) if nums[i] > nums[j])
//	   j<i
#include <iostream>

using namespace std;

class Solution{
public:
	int lengthOfLIS(vector<int> &nums){
		if( nums.size() == 0)
			return 0;

		//memo[i]表示以nums[i]为结尾的最差的航上升子序列的长度
		vector<int> memo(nums.size(), 1);
		for(int i=1; i<nums.size(); i++)
			for(int j=0; j<i; j++)
				if(nums[j] < nums[i])
					memo[i] = max(memo[i], 1+memo[j]);

		int res = 1;
		for(int i=0; i<nums.size(); i++)
			res = max(res, memo[i]);

		return res;
	}
};

int main(){
	return 0;
}

//动态规划
