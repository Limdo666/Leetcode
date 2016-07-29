#include <vector>
using namespace std;

class Solution {
public:
	int countPrimes(int n)
	{
		if (n < 2)return 0;
		vector<int> filter(n, 0);
		int sqrtn = sqrt(n);
		for (int i = 2; i <= sqrtn; i++)
		{
			if (filter[i]==0)
			{
				for (int j = i*i; j < n; j+=i)
				{
					filter[j] = 1;
				}
			}
		}
		int ans = 0;
		for (int i = 2; i<n; i++){
			if (filter[i] == 0)
				ans++;
		}
		return ans;
	}
};