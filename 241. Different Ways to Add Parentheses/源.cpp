#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		return inOrder(input);
	}
	vector<int> inOrder(string str) {
		vector<int> curRst;
		int len = str.size();
		for (int i = 0;i < len;i++) {
			char ch = str[i];
			if (ch == '+' || ch == '-' || ch == '*') {
				vector<int> left, right;
				string substr = str.substr(0, i);
				
				left = inOrder(substr);
				substr = str.substr(i + 1);
				right = inOrder(substr);

				for(auto i:left)
					for (auto j : right) {
						if (ch == '+')
							curRst.push_back(i + j);
						else if (ch == '-')
							curRst.push_back(i - j);
						else
							curRst.push_back(i*j);
					}
			}
		}
		if (curRst.empty())
			curRst.push_back(atoi(str.c_str()));
		return curRst;
	}
	
};