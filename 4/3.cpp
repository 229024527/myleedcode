//Two Sum
//给出一个整型数组nums。返回这个数组中两个数字的索引值i和j,使得nums[i]+nums[j]等于一个给定的target值。两个索引补鞥呢相等。
//- 如nums = [2,7,11,15],target=9
//- 返回[0,1]
//暴力解法
//排序后，使用双索引对撞：
//O(nlogn) + O(n) = O(nlogn)
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

//时间复杂度：O(n)
//空间复杂度：O(n)
class Solution{
public:
	vector<int> twoSum(vector<int>& nums, int target){

		unordered_map<int, int> record;
		for(int i=0; i<nums.size(); i++){

			int complement = target - nums[i];
			if( record.find( complement ) != record.end() ){
				int res[2] = {i, record[complement]};
				return vector<int>(res, res+2);
			}

			record[nums[i]] = i;
		}
		
		throw invalid_argument("The input has no solution");
	}
};

int main(){

	return 0;
}
