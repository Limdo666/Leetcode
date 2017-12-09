#include<string>
using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		for (size_t i = 0, k = 0; i < s.size(); i=k)
		{
			int j = i;
			while (j < s.size())
			{
				if (s[j] == ' ')
					break;
				j++;
			}
			k = j;
			j--;
			k++;
			while(i<j)
			{
				swap(s[i], s[j]);
				i++;
				j--;
			}
		}
		return s;
	}
};