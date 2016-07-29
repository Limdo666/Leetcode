#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int size=words.size();
		if (size < 2)return 0;
		int masks[26];
		for (int i = 0; i < 26; i++)
		{
			masks[i] = 1 << i;
		}
		int *patterns = new int[size]{0};
		int len = 0;
		for (int i = 0; i < size; i++)
		{
			len = words[i].length();
			for (int j = 0; j < len; j++)
			{
				patterns[i] |= masks[words[i][j] - 'a'];
			}
		}
		int max = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				if (!(patterns[i] & patterns[j]))
				{
					int t = words[i].length()*words[j].length();
					if (t > max)
						max = t;
				}
			}
		}
		return max;
	}
};