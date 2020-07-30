#include <iostream>
#include <vector>
#include <algorithm>

//给定一个正整数 n，将其拆分为至少两个正整数的和，
//并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

using namespace std;

class Solution {
public:

	int integerBreak(int n) {
		// 1. 动态规划
		vector<int> dp(n + 1, 0);
		for (int i = 2; i < (n + 1); ++i) {
			int curMax = 0;
			for (int j = 1; j < i; ++j) {
				curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
			}
			dp[i] = curMax;
		}
		return dp[n];

		// 2. 优化动态规划

	}
};

int main() {
	Solution s;
	int n = 10;
	int res = s.integerBreak(n);
	cout << res << endl;

	return 0;
}
