//Number of Boomerangs
//给出一个平面上的n个点，寻找存在多少个由这些点构成的三元组(i,j,k),使得i,j两点的距离等于i,k两点的距离。其中n最多为500，且所有的点坐标的范围在
//[-10000, 10000]之间。
//- 如[[0,0],[1,0]],[2,0]],则结果为2
//- 两个结果为[[1,0],[0,0],[2,0]]和[[1,0],[2,0],[0,0]]
//暴力解法：O(n^3)
//观察到i是一个“枢纽”，对于每个点i，遍历其余点到i的距离O(n^2)
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//时间复杂度：O(n^2)
//空间复杂度：O(n)
class Solution{
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points){
		int res = 0;
		for(int i=0; i<points.size(); i++){
			unordered_map<int, int> record;
			for(int j=0; j<points.size(); j++)
				if(j != i)
					record[dis(points[i], points[j])]++;

			for(unordered_map<int, int>::iterator iter = record.begin();
					iter != record.end(); iter++)
				res += (iter->second)*(iter->second-1);
		}
		return res;
	}

private:
	int dis(const pair<int, int>& pa, const pair<int, int>& pb){
		return (pa.first - pb.first)*(pa.first - pb.first) + 
			(pa.second - pb.second)*(pa.second - pb.second);
	}
};

int main(){

	return 0;
}
