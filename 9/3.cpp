#include <iostream>
#include <cassert>
#include <vector>
//给定一个正数n,可以将其分割成多个数字的和，若要让这些数字的乘积最大，求分割的方法（至少要分成两个数）。算法返回这个最大的乘积
//暴力解法：回溯遍历将一个数做分割的所有可能性。O(2^n)
using namespace std;

class Solution {
private:
	vector<int> memo;

	int max3(int a, int b, int c){
		return max(a, max(b,c));
	}

	//将n进行分割（至少分割两部分）,可以后的的最大乘积
	int breakInteger(int n){
		if(n==1)
			return 1;

		if(memo[n] != -1)
			return memo[n];

		int res=-1;
		for(int=1; i<=n-1; i++)
			res = max3(res, i*(n-i), i*breakInteger(n-i));

		memo[n] = res;
		return res;
	}

public:
	int integerBreak(int n){
		assert(n>=2);
		memo = vector<int>(n+1, -1);
		return breakInteger(n);
	}
};

int main(){
	return 0;
}
