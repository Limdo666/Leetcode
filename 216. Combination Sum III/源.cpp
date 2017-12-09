#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> rst;
		dfs(1, n, k, rst, vector<int>());
		return rst;
	}

	void dfs(int start, int remain, int RestNums, vector<vector<int>>& res, vector<int> cur)
	{
		if (RestNums == 0 && remain ==0) {
			res.push_back(cur);
		}else {
			for (int i = start;i < 10;i++) {
				if (remain < i)
					break;
				cur.push_back(i);
				dfs(i + 1, remain - i, RestNums - 1, res, cur);
				cur.pop_back();
			}
		}
	}
};

int main() {
	Solution a;
	auto b = a.combinationSum3(3, 7);
	return 0;
}