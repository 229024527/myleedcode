//Perfect Squares
//给出一个正整数n,寻找最少的完全平方数，使得他们的和为n.
//- 完全平方数：1,4,9,16...
//- 12 = 4+4+4		n=3
//- 13 = 4+9		n=2
//对问题建模:
//整个问题转化为一个图论问题。
//从n到0，每个数字表示一个节点；
//如果两个数字x到y相差一个完全平方数，则连接一条边。
//我们得到了一个无权图。
//原问题转化成，求整个无权图中从n到0的最短路径。

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

class Solution{
public:
	int numSquares(int n){

		assert(n>0);

		queue< pair<int,int> > q; 
		q.push( make_pair(n, 0) );

		vector<bool> visited(n+1, false);

		while( !q.empty() ){
			int num = q.front().first;
			int step = q.front().second;
			q.pop();

			if(num == 0)
				return step;

			for(int i=1; ; i++)
				int a = num - i*i;
				if( a < 0 )
					break;
				if( a == 0)
					return step + 1;
				if(! visited[a]){
					q.push(make_pair(a, step+1));
					visited[a] = true;
				}
		}

		throw invalid_argument("No Solution.");
	}
};

int main(){

	return 0;
}
