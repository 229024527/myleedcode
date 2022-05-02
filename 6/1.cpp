//Valid Parentheses
//给定一个字符串，只包含(,[,{,),],},判定字符串中的括号匹配是否合法。
//-如"()", "()[]{}"是否合法的
//-如"(]", "([)]"是非法的

#include <iostream>
#include <cassert>
#include <string>
#include <stack>

using namespace std;

class Solution{
public:
	bool isValid(string s){
		stack<char> stack;
		for(int i=0; i<s.size(); i++){
			if(s[i] == '(' || s[i] == '{' || s[i] == '[')
				stack.push( s[i] );
			else{
				if(stack.size() == 0)
					return false;

				char c = stack.top();
				stack.pop();

				char match;
				if(s[i] == ')')
					match = '(';
				else if(s[i] == ']')
					match = '[';
				else{
					assert(s[i] == '}');
					match = '{';
				}

				if( c != match)
					return false;
			}
		}
		if(stack.size() != 0)
			return false;
		return true;
	}
};

int main(){

	return 0;
}

//栈
