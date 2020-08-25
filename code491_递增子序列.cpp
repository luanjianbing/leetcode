#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，
//递增子序列的长度至少是2。

class Solution {
public:
	vector<int> temp;
	vector<vector<int>> ans;
	unordered_set<int> s;
	int n;

	void findSubsequences(int mask, vector<int>& nums) {
		temp.clear();
		for (int i = 0; i < n; ++i) {
			if (mask & 1) {
				temp.push_back(nums[i]);
			}
			mask >>= 1;
		}
	}

	// 检查是否递增
	bool check() {
		for (int i = 1; i < temp.size(); ++i) {
			if (temp[i] < temp[i - 1]) {
				return false;
			}
		}
		return temp.size() >= 2;
	}

	int getHash(int base, int mod) {
		int hashValue = 0;
		for (const auto &x : temp) {
			hashValue = 1LL * hashValue * base % mod + (x + 101);	// 避免负数？
			hashValue %= mod;
		}
		return hashValue;
	}

	vector<vector<int>> findSubsequences(vector<int>& nums) {
		n = nums.size();
		for (int i = 0; i < (1 << n); ++i) {	// 总共组成有2^n组
			findSubsequences(i, nums);
			int hashValue = getHash(263, int(1E9) + 7);
			if (check() && s.find(hashValue) == s.end()) {
				ans.push_back(temp);
				s.insert(hashValue);
			}
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 4, 6, 7, 7 };

	Solution s;
	vector<vector<int>> res = s.findSubsequences(nums);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

