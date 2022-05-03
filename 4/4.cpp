//4Sum II
//给出四个整型数组A,B,C,D,寻找有多少i,j,k,l的组合，使得A[i] + B[j] + C[k] + D[l] == 0。其中，A,B,C,D中均含有相同的元素个数N，且0<=N<=500
//暴力解法：O(n^4)
//将D中的元素放入查找表: O(n^3)
//将C+D的每一种可能放入查找表：O(n^2)
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

//时间复杂度：O(n^2)
//空间复杂度：O(n^2)
class Solution{
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
		assert(A.size() == B.size() && B.size() == C.size() && C.size() == D.size());
		unordered_map<int, int> record;
		for(int i=0; i<C.size(); i++)
			for(int j=0; j<D.size(); j++)
				record[ C[i] + D[j]] ++;
		
		int res = 0;
		for(int i=0; i<A.size(); i++)
			for(int j=0; j<B.size(); j++)
				if(record.find(0-A[i]-B[j]) != record.end())
					res += record[0-A[i]-B[j]];

		return res;
	}
};

int main(){

	return 0;
}
