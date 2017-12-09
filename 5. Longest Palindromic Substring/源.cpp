#include<string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len < 2)
			return s;
		int start, longest=1;
		for (int i = 0; i < len;)
		{
			int j = i, k = i;
			while (k < len - 1 && s[k + 1] == s[k])k++;
			i = k + 1;
			while (k < len - 1 && j > 0 && s[k + 1] == s[j - 1]) {
				k++;
				j--;
			}
			int newlen = k - j + 1;
			if (newlen > longest) {
				start = j;
				longest = newlen;
			}
		}
		return s.substr(start, longest);
	}
};