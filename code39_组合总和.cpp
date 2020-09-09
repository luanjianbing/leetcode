#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void dfs(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx) {
		if (idx == candidates.size())
			return;
		if (target == 0) {	// 找到一组可能
			ans.push_back(combine);
			return;
		}

		dfs(candidates, target, ans, combine, idx + 1);	// 选择跳过不用第idx个数

		if (target - candidates[idx] >= 0) {
			combine.emplace_back(candidates[idx]);
			dfs(candidates, target - candidates[idx], ans, combine, idx);	// 选择不不跳过使用第idx个数
			combine.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int> & candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combine;
		dfs(candidates, target, ans, combine, 0);
		return ans;
	}
};

int main() {
	vector<int> candidates = { 2, 3, 5 };
	int target = 8;

	Solution s;
	vector<vector<int>> res = s.combinationSum(candidates, target);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
