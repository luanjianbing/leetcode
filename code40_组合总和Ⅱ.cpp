#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ��code39��ȣ�ÿ����ֻ����ʹ��һ��

class Solution {
private:
	vector<pair<int, int>> freq;	// k-v: ��-���ֵĴ���
	vector<vector<int>> ans;	// ��Ž����ά����
	vector<int> sequence;	// �������
public:
	void dfs(int pos, int rest) {
		if (rest == 0) {	// ʣ��Ϊ0�����ҵ�һ�����
			ans.push_back(sequence);
			return;
		}
		if (pos == freq.size() || rest < freq[pos].first) {	// ��ʣ��С�����Ļ�����������󣬺��涼����ڵ�ǰʣ��������֦
			return;
		}

		dfs(pos + 1, rest);

		int most = min(rest / freq[pos].first, freq[pos].second);
		for (int i = 1; i < most; ++i) {
			sequence.push_back(freq[pos].first);
			dfs(pos + 1, rest - i * freq[pos].first);	// ��������һ�𣬵����������i��
		}
		for (int i = 1; i <= most; ++i) {
			sequence.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());	// �����֦����ʣ��ֵ����candidate[i]ʱ�������Ͳ���Ҫ����
		for (int num : candidates) {
			if (freq.empty() || num != freq.back().first)
				freq.emplace_back(num, 1);
			else
				++freq.back().second;
		}
		dfs(0, target);
		return ans;
	}

	//// ��׼dfs+����
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
	//	vector<vector<int>> ans;	// ��¼�����
	//	vector<int> combine;	// ��¼ÿһ�����
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
