#include<vector>
#include<set>
using namespace std;

class Solution {
public:

	vector<string> findWords(vector<string>& words) {
		char a[] = "qwertyuiopQWERTYUIOP";
		char b[] = "asdfghjklASDFGHJKL";
		char c[] = "zxcvbnmZXCVBNM";
		vector<string> oneRow = vector<string>();
		vector<set<char>> keymap = vector<set<char>>(3);
		keymap[0] = set<char>(a, a + 21);
		keymap[1] = set<char>(b, b + 19);
		keymap[2] = set<char>(c, c + 15);
		for (size_t i = 0; i < words.size(); i++)
		{
			for (auto im = 0; im < keymap.size(); im++)
			{
				if (keymap[im].find(words[i][0]) != keymap[im].end())
				{
					bool flag = true;
					for (size_t j = 0; j < words[i].size(); j++)
					{
						if (keymap[im].find(words[i][j]) == keymap[im].end())
						{
							flag = false;
							break;
						}
					}
					if (flag)
						oneRow.push_back(words[i]);
				}
			}
		}
		return oneRow;
	}
};