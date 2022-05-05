//Two Sum II - Input array is sorted
//给定一个有序整形数组和一个整数target,在其中寻找两个元素，使其和为target。返回这两个数的索引。
//- 如numbers = [2,7,11,15],target=9
//- 返回数字2,7的索引1,2(索引从1开始计算)
//最直接的思考：暴力解法。双层遍历，O(n^2)
#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;
//时间复杂度：O(n)
//空间复杂度：O(1)

class Solution{
public:
	vector<int> twoSum(vector<int>& numbers, int target){

		assert(numbers.size() >= 2);

		int l=0, r=numbers.size()-1;
		while(l<r){
			if(numbers[l] + numbers[r] == target){
				int res[2] = {l+1, r+1};
				return vector<int>(res, res+2);
			}
			else if(numbers[l] + numbers[r] < target)
				l++;
			else
				r--;
		}

		throw invalid_argument("The input has no solution.");
	}
};

int main(){

	return 0;
}
//对撞指针
