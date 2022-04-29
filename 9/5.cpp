#include <iostream>
#include <vector>

using namespace std;

class Knapsack01{
private:
	//二位数组
	vector<vector<int>> memo;

	//用[0...index]的物品，填充容积位c的背包的最大价值
	int bestValue(const vector<int>&w, const vector<int> v, int index, int c){
		if(index < 0 || c <= 0)	
			return 0;

		if(memo[index][c] != -1)
			return memo[index][c];

		int res = bestValue(w, v, index-1, c);
		if(c >= w[index])
			res = max(res, v[index] + bestValue(w, v, index-1, c-w[index]) );
		memo[index][c] = res;
		return res;
	}
public:
	int knapsack01(const vector<int>&w const vector<int>&v, int C){
		int n = w.size();
		//			n行	每一行又是一个vector<int> 有C+1列，每一个初始化为-1
		memo = vector<vector<int>>(n, vector<int>(C+1, -1));
		return bestValue(w, v, n-1, C);
	}
};

int main(){
	return 0;
}
//背包问题记忆化搜索
