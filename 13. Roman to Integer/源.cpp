#include<string>
#include<unordered_map>



using namespace std;



class Solution {
public:
	int romanToInt(string s) {
		if (s.length() == 0)
			return 0;
		int num=0;
		int pre=0;
		int curr=0;
		for (char ch : s)
		{
			switch (ch)
			{
			case 'I':curr = 1;break;
			case 'V':curr = 5;break;
			case 'X':curr = 10;break;
			case 'L':curr = 50;break;
			case 'C':curr = 100;break;
			case 'D':curr = 500;break;
			case 'M':curr = 1000;break;
			}
			num += curr;
			if (pre < curr)
			{
				num -= (pre << 1);
			}
			pre = curr;
		}
		return num;
	}
};

int main()
{
	Solution a;
	int num = a.romanToInt("DCXXI");
	return -1;
}