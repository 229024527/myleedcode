#include <iostream>
#include <vector>

using namespace std;

class Solution{

public:
	int climbStairs(int n){
		vector<int> memo(n+1, -1);

		memo[0] = 1;
		memo[2] = 1;
		for(int i=2; i<=n; i++)
			memo[i] = memo[i-1] + memo[i-2];
		return memo[n];
	}
};

int main(){
	return 0;
}
