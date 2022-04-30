//Letter Combinations of a Phone Number
//1		2(abc)		3(def)
//4(ghi)	5(jkl)		6(mno)
//7(pqrs)	8(tuv)		9(wxyz)
//如对数字字符串“23”，返回：
//["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
#include <iostream>

using namespace std;
private:
	const string letterMap[10] = {
		" ", 	//0
		"",	//1
		"abc",	//2
		"def",	//3
		"ghi",	//4
		"jkl",	//5
		"mno",	//6
		"pqrs",	//7
		"tuv",	//8
		"wxyz"	//9
	};
	vector<string> res;
	//s中保存了此时从digits[0...index-1]翻译得到的一个字母字符串
	//寻找和digists[index]匹配的字母，获得digits[0...index]翻译得到的解
	void findCombination(const string &digits, int index, const string &s){
		if(index == digits.size()){
			//保存s
			res.push_back(s);
			return;
		}

		char c = digits[index];
		assert(c >= '0' && c <= '9' && c != '1');
		string letters = letterMap[c - '0'];
		for(int i=0; i<letters.size(); i++)
			findCombination(digits, index+1, s+letters[i] );
	}
class Solution{
public:
	vector<string> letterCombinations(string digits){
		res.clear();
		if(digits == "")
			return res;

		findCombination(digits, 0, "");
		return res;
	}
};

int main(){
	return 0;
}
//递归
