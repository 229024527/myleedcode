//Move Zeros
//给定一个数组nums,写一个函数，将数组中所有的0挪到数组的末尾，而维持其他所有非0元素的相对位置。
//举例：nums=[0,1,0,3,12],函数运行后结果为[1,3,12,0,0]
//
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	//时间复杂度：O(n)
	//空间复杂度：O(n)
	void moveZeroes(vector<int>& nums){

		vector<int> nonZeroElements;

		for(int i=0; i<nums.size(); i++)
			if(nums[i])
				nonZeroElements.push_back(nums[i]);

		for(int i=0; i<nonZeroElements.size(); i++)
			nums[i] = nonZeroElements[i];

		for(int i=nonZeroElements.size(); i<nums.size(); i++)
			nums[i] = 0;

	}
};

int main(){

	int arr[] = {0,1,0,3,12};
	vector<int> vec(arr, arr+sizeof(arr)/sizeof(int));

	Solution().moveZeroes(vec);

	for(int i=0; i<vec.size(); i++)
		cout<<vec[i]<<" ";
	cout<<endl;

	return 0;
}
