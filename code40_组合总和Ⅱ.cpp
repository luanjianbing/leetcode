#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 与code39相比，每个数只可以使用一次

class Solution {
private:
	vector<pair<int, int>> freq;	// k-v: 数-出现的次数
	vector<vector<int>> ans;	// 存放结果二维数组
	vector<int> sequence;	// 单个组合
public:
	void dfs(int pos, int rest) {
		if (rest == 0) {	// 剩余为0，即找到一组组合
			ans.push_back(sequence);
			return;
		}
		if (pos == freq.size() || rest < freq[pos].first) {	// 当剩余小于数的话，经过排序后，后面都会大于当前剩余数，剪枝
			return;
		}

		dfs(pos + 1, rest);

		int most = min(rest / freq[pos].first, freq[pos].second);
		for (int i = 1; i < most; ++i) {
			sequence.push_back(freq[pos].first);
			dfs(pos + 1, rest - i * freq[pos].first);	// 连续的数一起，调用了这个数i次
		}
		for (int i = 1; i <= most; ++i) {
			sequence.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());	// 排序剪枝，当剩余值大于candidate[i]时，后续就不需要考虑
		for (int num : candidates) {
			if (freq.empty() || num != freq.back().first)
				freq.emplace_back(num, 1);
			else
				++freq.back().second;
		}
		dfs(0, target);
		return ans;
	}

	//// 标准dfs+回溯
	//void traceBack(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx) {
	//	if (idx == candidates.size())
	//		return;
	//	if (target == 0) {
	//		ans.push_back(combine);
	//		return;
	//	}
	//	traceBack(candidates, target, ans, combine, idx + 1);
	//	if ((target - candidates[idx]) >= 0) {
	//		combine.push_back(candidates[idx]);
	//		traceBack(candidates, target - candidates[idx], ans, combine, idx + 1);
	//		combine.pop_back();
	//	}
	//}

	//vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
	//	vector<vector<int>> ans;	// 记录最后结果
	//	vector<int> combine;	// 记录每一次组合
	//	traceBack(candidates, target, ans, combine, 0);
	//	return ans;
	//}
};

int main() {
	vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
	int target = 8;

	Solution s;
	vector<vector<int> > res = s.combinationSum2(candidates, target);

	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
