#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ret;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int>::size_type i = 0, j = 0,size1=nums1.size(),size2=nums2.size();
		while (i != size1 && j != size2)
		{
			if (nums1[i] == nums2[j])
			{
				if (ret.size() == 0 || nums1[i] != ret.back())
					ret.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}
		return ret;
	}
};