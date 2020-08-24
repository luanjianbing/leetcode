#include <iostream>

using namespace std;

//给定范围[m, n]，其中 0 <= m <= n <= 2147483647，
//返回此范围内所有数字的按位与（包含 m, n 两端点）。

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		// 按位与需要知道每一位上所有数是否存在0
		// 存在0的话那该位置就为0
		// int类型存储的是4字节,32位
		if ((m <= 0 && n > 0) || (m < 0 && n >= 0)) return 0;
		//// 1. 暴力与（超时）
		//int ans = INT32_MAX;
		//for (int cur = m; cur <= n; ++cur) 
		//	ans &= cur;
		//return ans;

		// 2. 处理公共前缀(位移)
		int shift = 0;
		// 找到公共前缀
		while (m < n) {
			m >>= 1;
			n >>= 1;
			++shift;
		}
		return m << shift;

		////Brian Kernighan 算法
		//while (m < n)
		//	n = n & (n - 1);
		//return n;

		
	}
};

int main() {
	int m = 5;
	int n = 7;

	Solution s;
	cout << s.rangeBitwiseAnd(m, n) << endl;

	return 0;
}
