//Intersection of Tow Array
//给定两个数组nums, 求两个数组的交集。
//- 如nums1 = [1,2,2,1],nums2 = [2,2]
//- 结果为[2,2]
//- 出现的顺序可以是任意的
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2){

		map<int, int> record;
		for(int i=0; i<nums1.size(); i++)
			record[nums1[i]] ++;

		vector<int> resultVector;
		for(int i=0; i<nums2.size(); i++)
			if(record[nums2[i]] > 0){
				resultVector.push_back(nums2[i]);
				record[nums2[i]] --;
			}

		return resultVector;
	}
};

int main(){

	return 0;
}
