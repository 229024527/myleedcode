//Permutations
//给定一个整形数组，其中的每一个元素都各不相同，返回这些元素所有排列的可能。
//-如对于[1,2,3]
//-返回[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
private:
	vector<vector<int>> res;
	vector<bool> used;

	//p中保存了一个有index个元素的排列。
	//向这个排列的末尾添加第index+1个元素，获得一个有index+1个元素的排列
	void generatePermutation(const vector<int> &nums, int index, vector<int> &p){
		if(index == nums.size())
		{
			res.push_back(p);
			return;
		}

		for(int i=0; i<nums.size(); i++)
			if(!used[i])
			{
				//将nums[i]添加在p中
				p.push_back(nums[i]);
				used[i] = true;
				generatePermutation(nums, index+1, p);
				p.pop_back();
				used[i] = false;
			}
		return;
	}
public:
	vector<vector<int>> permute(vector<int> &nums){
		res.clear();
		if( nums.size() == 0)
			return res;

		used = vector<bool>(nums.size(), false);
		vector<int> p;
		generatePermutation(nums, 0, p);

		return res;
	}
};

int main(){
	return 0;
}
