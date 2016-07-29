#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int len = 0, table[128];
		for (int i = 0; i < 128; ++i)
			table[i] = -1;
		int fast = 0, slow = 0;
		while (fast < s.length())
		{
			if (table[s[fast]]>=slow)
			{
				if (len < fast - slow)
					len = fast - slow;
				slow = table[s[fast]] + 1;
			}
			table[s[fast]] = fast;
			fast++;
		}
		if (len < fast - slow)
			len = fast - slow;
		return len;
	}
};
int main()
{
	Solution s;
	string str = "a";
	int i = s.lengthOfLongestSubstring(str);
}


/*
class Solution {
public:
int lengthOfLongestSubstring(string s) {
int len = 0, table[128] = { 0 };
int i = 0, j = 0, size = s.length();
while (j < size)
{
table[s[j]]++;
if (table[s[j]]>1)
{
len = max(len, j - i);
while (table[s[j]] > 1)
{
table[s[i++]]--;
}
}
j++;
}
len = max(len, j - i);
return len;
}
};

*/