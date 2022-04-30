#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Knapsack01{
public:
	int knapsack01(const vector<int> &w, const vector<int> &v, int c){
		assert(w.size() == v.size());
		int n = w.size();
		if(n == 0)
			return 0;

		vector<vector<int>> memo(2, vector<int>(c+1， -1));

		for(int j=0; j<=c; j++)
			memo[0][j] = (j >= w[0] ? v[0] : 0);

		for(int i=1; i<n; i++)
			for(int j=0; j<=c; j++){
				//考虑0~i物品，且容积为j的背包获得的最大值是多少
				memo[i%2][j] = memo[(i-1)%2][j];
				if( j>= w[i] )
					memo[i%2][j] = max( memo[i%2][j], v[i] + memo[(i-1)%2][j-w[i]] );
			}
		return memo[(n-1)%2][c];
	}
};

int main(){
	return 0;
}
//优化空间复杂度2C
