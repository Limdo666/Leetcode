#include<iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		long long n = 0;
		int t = x;
		while (t > 0)
		{
			n = n * 10 + t % 10;
			t = t / 10;
		}
		if (n == x)
			return true;
		else
			return false;
	}
};

int main()
{
	Solution a;
	int num = (int)(-2147483648);
	cout<<a.isPalindrome(numeric_limits<int>::max())<<endl;
	cout << a.isPalindrome(num) << endl;
	system("pause");
	return 0;
}