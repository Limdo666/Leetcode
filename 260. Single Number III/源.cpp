#include <vector>
#include <ctime>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int aXorb = 0;
		for (auto i : nums)
			aXorb ^= i;
		int BitOne = aXorb&(-aXorb);
		int a = 0;
		for (auto i : nums){
			if (BitOne&i)
				a ^= i;
		}
		int b = a^aXorb;
		return vector<int>{ a, b };
	}
};