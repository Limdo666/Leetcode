#include <string>
using namespace std;
class Solution {
public:
	string convertToTitle(int n) {
		int temp=n;
		string ret;
		while (temp != 0)
		{
			char c=temp % 26 + 'A' - 1;
			temp /= 26;
			if (c >= 'A')
				ret = c+ret;
			else
			{
				ret = 'Z'+ret;
				temp--;
			}
		}
		return ret;
	}
};