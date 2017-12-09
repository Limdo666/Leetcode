#include<string>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int mark[26] = { 0 };
		for (char ch : magazine)
		{
			mark[ch - 'a']++;
		}
		for (char ch : ransomNote)
		{
			if (--mark[ch - 'a'] < 0)
				return false;
		}
		return true;
	}
};