//双索引技术Two Pointer
//滑动窗口
//给定一个整形数组和一个数字s,找到数组中最短的一个连续子数组，使得连续子数组的数字和sum>=s,返回这个最短的连续子数组的长度值
//- 如，给定数组[2,3,1,2,4,3],s=7
//- 答案为[4,3],返回2
//暴力解：遍历所有的连续子数组[i...j]         大量的重复计算
//计算其和sum,验证sum >= s
//时间复杂度O(n^3)
//
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//时间复杂度O(n)
//空间复杂度O(1)

class Solution{
public:
	int minSubArrayLen(int s, vector<int>& nums){

		int l=0, r=-1;	//nums[l...r]为我们的滑动窗口
		int sum = 0;
		int res = nums.size() + 1;

		while(l<nums.size()){
			if(num<s)
				sum += nums[++r];
			else
				sum -= nums[l++];

			if(sum>=s)
				res = min(res, r-l+1);
		}

		if(res == nums.size()+1)
			return 0;

		return res;
	}
};

int main(){

	return 0;
}
