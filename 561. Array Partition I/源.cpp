#include<vector>
#include<algorithm>
#include<assert.h>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (auto i=0 ; i < nums.size(); i+=2)
		{
			sum += nums[i];
		}
		return sum;

	}
};