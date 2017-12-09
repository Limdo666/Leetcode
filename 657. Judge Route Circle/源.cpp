#include<string>
using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int x = 0;
		int y = 0;
		for(auto i = 0; i< moves.size(); i++)
		{
			char c = moves[i];
			if (c == 'U')
				y += 1;
			else if (c == 'D')
				y -= 1;
			else if (c == 'L')
				x -= 1;
			else if (c == 'R')
				x += 1;

		}
		if (x == 0 && y == 0)
			return true;
		else
			return false;
	}
};