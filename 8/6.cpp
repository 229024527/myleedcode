//给定一个二维平面的字母和一个单词，看是否可以在这个二维平面上找到该单词。其中找到这个单词的规则是，从一个字母出发，可以横向或者纵向连接二维平面上的其他字母。同一个位置的字母可能使用一次。
//[
//['A', 'B', 'C', 'E'],		"ABCCED"=>true
//['S', 'F', 'C', 'S'],		"SEE"	=>true
//['A', 'D', 'E', 'E']		"ABCB"	=>false
//]
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution{
private:
	//   | x   __ y  左上(0,0)
	//		上     右    下     左
	int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
	int m,n;
	vector<vector<bool>> visited;
	
	bool inArea(int x, int y){
		return x>=0 && x<m && y>=0 && y<n;
	}

	//从board[startx][starty]开始，寻找word[index...word.size())
	bool searchWord(const vector<vector<char>> &board, const string &word, int index, int startx, int starty){
		if(index == word.size() - 1)
			return board[startx][starty] == word[index];

		if(board[startx][starty] == word[index]){
			visited[startx][starty] = true;
			//从startx,starty出发,向四个方向寻找
			for(int i=0; i<4; i++){
				int newx = startx + d[i][0];
				int newy = starty + d[i][1];
				if( inArea(newx, newy) && !visited[newx][newy] &&
					searchWord(board, word, index+1, newx, newy))
						return true;
			}
			visited[startx][starty] = false;
		}

		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word){
		m = board.size();
		assert(m>0);
		n = board[0].size();

		visited = vector<vector<bool>>(m, vector<bool>(n, false));

		for(int i=0; i<board.size(); i++)
			for(int j=0; j<board[i].size(); j++)
				if(searchWord( board, word, 0, i, j))
					return true;

		return false;
	}
};

int main(){

	return 0;
}
