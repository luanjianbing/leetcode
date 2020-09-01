#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给定一个表示分数的非负整数数组。 
//玩家 1 从数组任意一端拿取一个分数，
//随后玩家 2 继续从剩余数组任意一端拿取分数，
//然后玩家 1 拿，…… 。
//每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。
//直到没有剩余分数可取时游戏结束。
//最终获得分数总和最多的玩家获胜。
//
//给定一个表示分数的数组，预测玩家1是否会成为赢家。
//你可以假设每个玩家的玩法都会使他的分数最大化。

class Solution {
public:
	int total(vector<int> &nums, int start, int end, int turn) {
		if (start == end)	// 数组中只剩一位数
			return nums[start] * turn;
		int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
		int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
		return max(scoreStart * turn, scoreEnd * turn) * turn;
	}

	bool PredictTheWinner(vector<int>& nums) {
		//// 1. 递归
		//return total(nums, 0, nums.size() - 1, 1) >= 0;

		// 2. 动态规划
		// dp[i][j]表示当数组剩下的部分为下标 i 到下标 j 时，当前玩家与另一个玩家的分数之差的最大值，注意当前玩家不一定是先手
		// 只有当i <= j时，数组剩下的部分才有意义
		// 因此i > j时，dp[i][j] = 0
		// 方程：dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
		int length = nums.size();
		auto dp = vector<vector<int>>(length, vector<int>(length));
		for (int i = 0; i < length; i++) {
			dp[i][i] = nums[i];
		}
		for (int i = length - 2; i >= 0; i--) {
			for (int j = i + 1; j < length; j++) {
				dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
			}
		}
		return dp[0][length - 1] >= 0;
	}
};

int main() {
	vector<int> nums = { 1, 5, 233, 7 };

	Solution s;
	cout << s.PredictTheWinner(nums) << endl;

	return 0;
}
