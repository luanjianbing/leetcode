#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。
//现在你有两个符号  + 和  - 。
//对于数组中的任意一个整数，你都可以从  + 或  - 中选择一个符号添加在前面。
//
//返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

class Solution {
private:
	int count = 0;
public:
	void calculate(vector<int> &nums, int i, int sum, int S) {
		if (i == nums.size()) {
			if (sum == S)
				count++;
		}
		else {
			calculate(nums, i + 1, sum + nums[i], S);
			calculate(nums, i + 1, sum - nums[i], S);
		}
	}

	int findTargetSumWays(vector<int>& nums, int S) {
		// 共有2的nums.size()方个结果
		calculate(nums, 0, 0, S);
		return count;
	}
};

int main() {
	vector<int> nums = { 1, 1, 1, 1, 1 };
	int S = 3;

	Solution s;
	cout << s.findTargetSumWays(nums, S) << endl;

	return 0;
}
