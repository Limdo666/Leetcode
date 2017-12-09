#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {

		if (nums.size() == 0)
			return 0;
		int max = nums[0], currSum = 0;
		for (int i = 0;i < nums.size();i++)
		{
			if (currSum < 0)
				currSum = nums[i];
			else
			{
				currSum += nums[i];

			}

			if (max < currSum)
				max = currSum;
		}
		return max;
	}
};

int main()
{
	//vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> nums = { -2,-3,-5,5,-1,123,-10 };

	Solution a;
	auto rst = a.maxSubArray(nums);
	cout << rst << endl;
	system("pause");
	return 0;
}