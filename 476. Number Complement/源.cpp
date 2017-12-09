#include<iostream>

class Solution {
public:
	int findComplement(int num) {
		unsigned int bits = 0xffffffff;
		int i = num;
		while (i>0)
		{
			i <<= 1;
			bits >>= 1;
		}
		return (~num) & bits;
	}
};

int main()
{
	Solution s = Solution();
	std::cout<<s.findComplement(5);
	system("pause");

}