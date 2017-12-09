/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.
*/

#include<vector>
#include<stack>
#include<iostream>
using namespace std;
struct Node
{
	int x, y;
	int d;
	char c;
	Node(int i, int j, int ch, int dir = 0) :x(i), y(j), d(dir), c(ch) {}
	Node() {}
};
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {

		if (board.empty() || board[0].empty())
			return false;
		stack<Node> path;
		int h = board.size();
		int w = board[0].size();
		for (int i = 0;i < h;i++)
		{
			for (int j = 0;j < w;j++)
			{
				int index = 0;
				if (board[i][j] == word[index])
				{
					Node node(i, j, word[index++]);
					board[i][j] = '*';
					if (index == word.size())
						return true;
					path.push(node);
					while (!path.empty())
					{
						node = path.top();
						Node next;
						switch (node.d)
						{
						case 0:
							if (node.x != 0 && board[node.x - 1][node.y] == word[index])
							{
								next = Node(node.x - 1, node.y, word[index]);
								path.top().d=0;
								break;
							}
						case 1:
							if (node.x != h - 1 && board[node.x + 1][node.y] == word[index])
							{
								next = Node(node.x + 1, node.y, word[index]);
								path.top().d = 1;
								break;
							}
						case 2:
							if (node.y != 0 && board[node.x][node.y - 1] == word[index])
							{
								next = Node(node.x, node.y - 1, word[index]);
								path.top().d = 2;
								break;
							}
						case 3:
							if (node.y != w - 1 && board[node.x][node.y + 1] == word[index])
							{
								next = Node(node.x, node.y + 1, word[index]);
								path.top().d = 3;
								break;
							}
						default:
							board[node.x][node.y] = node.c;
							path.pop();
							if (!path.empty())
								path.top().d++;
							index--;
							continue;
						}
						board[next.x][next.y] = '*';
						path.push(next);
						index++;
						if (index == word.size())
							return true;
					}


				}
			}
		}
		return false;
	}
};

int main()
{
	vector<vector<char>> b =
	{ {'A','B','C','E'},
	{'S','F','C','S'},
	{'A','D','E','E' } };
	string word = "ABFCS";
	Solution s;
	auto r = s.exist(b, word);
	return 0;
}