#include <string>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		int len1 = s.length();
		int len2 = t.length();
		if (len1 != len2) return false;
		int pattern1[26] = { 0 }, pattern2[26] = { 0 };

		for (int i = 0; i < len1; i++)
			pattern1[s[i] - 'a']++;

		for (int i = 0; i < len2; i++)
			pattern2[t[i] - 'a']++;
		for (int i = 0; i < 26; i++)
			if (pattern1[i] != pattern2[i])
				return false;
		return true;
	}
};
int main()
{
	Solution a;
	string s = "axncxlhjle";
	string t = "xxconlaelh";
	auto r = a.isAnagram(s,t);
	return 0;
}