//Longest Substring Without Repeating Characters
//在一个字符串中寻找没有重复字母的最长子串
//- 如"abcabcbb", 则结果为"abc"
//- 如"bbbbb",则结果为"n"
//- 如"pwwkew",则结果为"wke"
//
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//时间复杂度O(n)
//空间复杂度O()

class Solution{
public:
	int lengthOfLongestSubstring(string s){
		int freq[256] = {0};	
		int l=0, r=-1;//滑动窗口为s[l...r]
		int res=0;

		while(l<s.size()){
			if(r + 1 < s.size() && freq[s[r+1]] == 0)
				freq[s[++r]]++;
			else
				freq[s[l++]]--;

			res = max(res, r-l+1);
		}

		return res;
	} 

};

int main(){

	return 0;
}
