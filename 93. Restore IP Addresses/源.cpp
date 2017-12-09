#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> rst;
		dfs(0, 4, s, rst, "");
		return rst;
	}


};



class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		int len = s.length();
		string part[4];
		vector<string> rst;
		for (int i = 1;i != 4;++i) {
			if ((len - i) > 3 * 3 || (len - i) < 3)
				continue;
			part[0] = string(s.begin(), s.begin() + i);
			if (IsFailed(part[0]))
				continue;
			part[0] += '.';

			for (int j = i + 1;j != i + 4;++j) {
				if ((len - j) > 3 * 2 || (len - j) < 2)
					continue;
				part[1] = string(s.begin() + i, s.begin() + j);
				if (IsFailed(part[1]))
					continue;
				part[1] += '.';

				for (int k = j + 1;k != j + 4;++k) {
					if ((len - k) > 3 || (len - k) < 1)
						continue;
					part[2] = string(s.begin() + j, s.begin() + k);
					if (IsFailed(part[2]))
						continue;
					part[2] += '.';
					part[3] = string(s.begin() + k, s.end());
					if (IsFailed(part[3]))
						continue;
					string s;
					for (int i = 0;i != 4;i++) {
						s += part[i];
					}
					rst.push_back(s);
				}
			}
		}
		return rst;
	}
	bool IsFailed(string s) {
		int n;
		switch (s.length()) {
		case 0:
			n = 0;return true;
		case 1:
			n = s[0] - '0';return false;
		case 2:
			if (s[0] - '0' == 0)
				return true;
			n = 10 * (s[0] - '0') + s[1] - '0';break;
		case 3:
			if (s[0] - '0' == 0)
				return true;
			n = 100 * (s[0] - '0') + 10 * (s[1] - '0') + s[2] - '0';break;
		}
		return n > 255;
	}

	void dfs(int start, int restSegs, const string& digits, vector<string>& IPs, string cur) {
		if (restSegs == 0) {
			IPs.push_back(cur);
		}
		else {
			for (int i = 1; i < 4 && start + i <= digits.size(); i++) {
				int temp = digits.size() - start - i;
				if (restSegs - 1 <= temp && temp <= (restSegs - 1) * 3) {
					string seg = digits.substr(start, i);
					if (seg.size() > 1 && seg[0] == '0') continue;
					if (stoi(seg) < 256) {
						string toAppend = restSegs == 1 ? seg : seg + ".";
						dfs(start + i, restSegs - 1, digits, IPs, cur + toAppend);
					}
				}
			}
		}
	}
};

int main() {
	Solution a;
	auto b = a.restoreIpAddresses("010010");
	return 0;
}