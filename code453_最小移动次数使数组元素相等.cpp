#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给定一个长度为 n 的非空整数数组，
//找到让数组所有元素相等的最小移动次数。
//每次移动将会使 n - 1 个元素增加 1。

class Solution {
public:
	int minMoves(vector<int>& nums) {
		// 动态规划
		// 首先将nums排序
		sort(nums.begin(), nums.end());
		int moves = 0;
		for (int i = 1; i < nums.size(); ++i) {
			int diff = (moves + nums[i]) - nums[i - 1];
			nums[i] += moves;
			moves += diff;
		}
		return moves;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3 };
	Solution s;
	int res = s.minMoves(nums);
	cout << res << endl;

	return 0;
}
