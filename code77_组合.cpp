#include <iostream>
#include <vector>

using namespace std;

//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

class Solution {
public:
	vector<int> tmp;
	vector<vector<int>> ans;

	void back(int cur, int n, int k) {
		// 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
		if (tmp.size() + (n - cur + 1) < k) {
			return;
		}
		// 记录合法的答案
		if (tmp.size() == k) {
			ans.push_back(tmp);
			return;
		}
		//// cur == n + 1的时候结束递归
		//if (cur == n + 1) {
		//	return;
		//}
		// 考虑选择当前位置
		tmp.push_back(cur);
		back(cur + 1, n, k);
		tmp.pop_back();
		// 考虑不选择当前位置
		back(cur + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k) {
		back(1, n, k);
		return ans;
	}
};

int main() {
	int n = 4;
	int k = 2;

	Solution s;
	vector<vector<int>> res = s.combine(n, k);
	
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
