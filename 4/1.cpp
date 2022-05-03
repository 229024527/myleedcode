//两类查找问题
//查找有无
//- 元素‘a’是否存在？ set;集合
//查找对应关系(键值对应)
//- 元素‘a’出现了几次？ map;字典
//Intersection of Two Arrays
//TWO SIGMA
//给定两个数组nums,求两个数组的公共元素。
//- 如nums1 = [1,2,2,1], nums2 = [2,2]
//- 结果为[2]
//- 结果中每个元素只能出现一次
//- 出现的顺序可以是任意的
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
		set<int> record(nums1.begin(), nums1.end());

		set<int> resultSet;
		for(int i=0; i<nums2.size(); i++)
			if(record.find(nums2[i]) != record.end())
				resultSet.insert(nums2[i]);

		return vector<int>(resultSet.begin(), resultSet.end());
	}

};

int main(){

	return 0;
}
