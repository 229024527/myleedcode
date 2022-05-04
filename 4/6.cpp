//Contains Duplicate II
//给出一个整形数组nums和一个整数k，是否存在索引i和j,使得nums[i]==nums[j]且i和j之间的差值不超过k
//暴力解法：O(n^2)
//滑动窗口
#include <iostream>
#include <vector>
#include <unordered_set>

//时间复杂度：O(n)
//空间复杂度：O(k)
using namespace std;

class Solution{
public:
	bool containsInsNearbyDuplicate(vector<int>& nums, int k){

		unordered_set<int> record;
		for(int i=0; i<nums.size(); i++){
			if(record.find(nums[i]) != record.end())
				return true;

			record.insert(nums[i]);

			//保持record中最多有k个元素
			if(record.size() == k+1)
				record.erase(nums[i-k]);
		}

		return false;
	}
};

int main(){
	return 0;
}
