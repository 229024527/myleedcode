//给出两个整数n和k,求在1...n这n个数字中选出k个数字的所有组合。
//-如n=4,k=2
//-结果为[[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	//求解C(n,k),当前已经找到的组合存储在c中，需要从start开始搜索新的元素
	void generateCombinations(int n, int k, int start, vector<int> &c){
		if(c.size() == k){
			res.push_back(c);
			return;
		}

		//还有k - c.size()个空位,所以,[i...n]中至少要有k-c.size()个元素
		//i最多为n-(k-c.size())+1
		for(int i=start; i<=n-(k-c.size())+1; i++){
			c.push_back(i);
			generateCombinations(n, k, i+1， c);
			c.pop_back();
		}

		return;
	}
public:
	//n个数选k个
	vector<vector<int>> combine(int n, int k){
		res.clear();
		if(n <= 0 || k<=0 || k>n)
			return res;

		vector<int> c;
		generateCombinations(n, k, 1, c);

		return res;
	}
};

int main(){

	return 0;
}
//优化
//剪支
