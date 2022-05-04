//Contains Duplicate
//给出一个整形数组nums，是否存在索引i和j，使得nums[i]和nums[j]之间的差别不超过给定的整数t，且i和j之间的差别不超过给定的整数k。
//滑动窗口
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//时间复杂度：O(nlogn)
//空间复杂度：O(k)
class Solution{
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k, int t){
		set<long long> record;
		for(int i=0; i<nums.size(); i++){
			if(record.lower_bound((long long)nums[i]-(long long)t) != record.end() &&
					*record.lower_bound((long long)nums[i]-(long long)t) <= (long long)nums[i]+(long long)t)
				return true;

			record.insert(nums[i]);

			//保持record中最多有k个元素
			if(record.size() == k+1)
				record.erase(nums[i-k]);
		}

		return false;
	}
};
