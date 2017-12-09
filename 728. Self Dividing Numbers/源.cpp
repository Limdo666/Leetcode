#include<vector>
using namespace std;
class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> nums = vector<int>();
		for (int i = left; i <= right; i++)
		{
			int div = i;
			while (div != 0)
			{
				int d = div % 10;
				div /= 10;
				if (d == 0)
					break;
				else if (i % d != 0)
					break;
				else if (div == 0)
					nums.push_back(i);

			}
		}
		return nums;
	}
};