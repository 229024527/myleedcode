//给定一个非空数组，返回前k个出现频率最高的元素。
//- 如给定[1,1,1,2,2,3],k=2
//- 返回[1,2]
//- 注意k的合法性问题
//最简单的思路：扫描一遍统计频率；排序找到前k个出现频率最高的元素。O(nlogn)
//or 维护一个含有k个元素的优先队列。如果遍历到的元素比队列中的最小频率元素的频率高，则去除队列中最小频率的元素，将新元素入队。最终，队列中剩下的，就是前k个出现频率最高的元素。
//时间复杂度：O(nlogk)
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<int> topKFrequent(vector<int> &nums, int k){
		assert(k>0);

		//统计每个元素出现的频率
		unordered_map<int, int> freq;
		for(int i=0; i<nums.size(); i++)
			freq[nums[i]]++;

		assert( k<= freq.size() );
		
		//扫描freq,维护当前出现频率最高的k个元素
		//在优先队列中，按照频率排序，所以数据对是(频率，元素)的形式
		priority_queue< pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>> > pq;
		for(unordered_map<int, int>::iterator iter = freq.begin();
				iter != freq.end(); iter++){
			if(pq.size() == k){
				if(iter->second > pq.top().first){
					pq.pop();
					pq.push( make_pair(iter->second, iter->first) );
				}
			}
			else
				pq.push( make_pair(iter->second, iter->first) );
		}

		vector<int> res;
		while( !pq.empty() ){
			res.push_back( pq.top().second );
			pq.pop();
		}
		return res;
	}
};

int main(){

	return 0;
}
