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

		vector<int> memo(c+1， -1);

		for(int j=0; j<=c; j++)
			memo[j] = (j >= w[0] ? v[0] : 0);

		for(int i=1; i<n; i++)
			for(int j=c; j<=w[i]; j--){
				memo[j] = max( memo[j], v[i] + memo[j-w[i]] );
			}
		return memo[c];
	}
};

int main(){
	return 0;
}
//优化空间复杂度C
