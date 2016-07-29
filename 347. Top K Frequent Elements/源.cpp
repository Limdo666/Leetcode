#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool ComparePair(const pair<int, int> &pair1, const pair<int, int> &pair2)
{
	return pair1.second < pair2.second;
}
class Solution {
public:

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> maps;
		for (auto i : nums)
			maps[i]++;
		vector<pair<int, int>> heap(maps.begin(), maps.end());
		vector<int> result;
		make_heap(heap.begin(), heap.end(), ComparePair);
		while (k--) {
			result.push_back(heap.front().first);
			pop_heap(heap.begin(), heap.end(), ComparePair);
			heap.pop_back();
		}
		return result;
	}
};

int main()
{
	Solution a;
	vector<int> nums = { 1, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 4, 4, 4, 4, 4, 4, 4, 4, 7, 8, 4, 5, 3, 4, 5, 3, 6, 3 };
	auto r = a.topKFrequent(nums, 3);
	return 0;
}