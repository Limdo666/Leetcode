#include<string>
using namespace std;

class Solution {
public:
	string reverseVowels(string s) {
		int i = 0, j = s.size()-1;
		while (i < j)
		{
			if (!isVowel(s[i]))
			{
				i++;
				continue;
			}
			if (!isVowel(s[j]))
			{
				j--;
				continue;
			}
			swap(s[i++], s[j--]);
		}
		return s;
	}
	inline bool isVowel(char c)
	{
		
		switch (c)
		{
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			return true;
		default:
			return false;
		}
	}
};