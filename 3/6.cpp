//给定一个有n个元素的数组，数组中元素的取值只有0,1,2三种可能。为这个数组排序。
//- 可以使用任意一种排序算法
//- 没有使用上题目中给出的特殊条件
//计数排序：分别统计0,1,2的元素个数
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
public:
	//时间复杂度：O(n)
	//空间复杂度：O(k), k为元素的取值范围
	void sortColors(vector<int>& nums){

		int count[3] = {0}; //存放0,1,2三个元素的频率
		for(int i=0; i<nums.size(); i++){
			assert(nums[i]>=0 && nums[i]<=2);
			count[nums[i]]++;
		}

		int index = 0;
		for(int i=0; i<count[0]; i++)
			nums[index++] = 0;
		for(int i=0; i<count[1]; i++)
			nums[index++] = 1;
		for(int i=0; i<count[2]; i++)
			nums[index++] = 2;

	}

};

int main(){

	return 0;
}
