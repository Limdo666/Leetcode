#include <vector>
using namespace std;


class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> count;
		count.push_back(0);
		for (int i = 1; i <= num; ++i)
		{
			count.push_back(count[i&(i - 1)] + 1);
		}
		return count;
	}
};