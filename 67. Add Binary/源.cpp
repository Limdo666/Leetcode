#include<string>

using namespace std;


class Solution {
public:
	string addBinary(string a, string b) {
		char ch = '0';
		int diff = a.length() - b.length();
		if (diff < 0)
		{
			swap(a, b);
			diff = -diff;
		}
		int i = b.length()-1;
		int j = i + diff;
		while (i >= 0)
		{
			a[j] += b[i]+ch-'0'-'0'-'0';
			if (a[j] == 3)
			{
				a[j] = '1';
				ch = '1';
			}
			else if (a[j] == 2)
			{
				a[j] = '0';
				ch = '1';
			}
			else if (a[j] == 1)
			{
				a[j] = '1';
				ch = '0';
			}
			else
			{
				a[j] = '0';
			}
			--i;
			--j;
		}
		while (j >= 0) {
			a[j] += ch-'0'-'0';
			if (a[j] == 2) {
				a[j] = '0';
				ch = '1';
			}
			else if (a[j] == 1) {
				a[j] = '1';
				ch = '0';
			}
			else {
				a[j] = '0';
			}
			--j;
		}
		if (ch == '1')
			a = '1' + a;
		return a;
	}
};

int main()
{
	Solution a;
	auto b=a.addBinary("101101101010", "11111001010101");
	return 0;
}