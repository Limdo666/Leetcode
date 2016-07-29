#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
	//此处的返回类型为int，会溢出
	int integerBreak(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		int res=1;
		if (n % 3 == 2)
		{
			res = 2;
			n -= 2;
		}
		else if (n % 3 == 1)
		{
			res = 4;
			n -= 4;
		}
		int count = n / 3;
		res *= pow(3, count);
		return res;
	}
};

int main()
{
	Solution slt;
	for (int i = 1; i <= 100; i++)
		cout <<i<<'\t'<< slt.integerBreak(i)<<endl;
	system("pause");
	return 0;
}