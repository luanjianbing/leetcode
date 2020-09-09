#include <iostream>
#include <vector>

using namespace std;

//������������ n �� k������ 1 ... n �����п��ܵ� k ��������ϡ�

class Solution {
public:
	vector<int> tmp;
	vector<vector<int>> ans;

	void back(int cur, int n, int k) {
		// ��֦��temp ���ȼ������� [cur, n] �ĳ���С�� k�������ܹ��������Ϊ k �� temp
		if (tmp.size() + (n - cur + 1) < k) {
			return;
		}
		// ��¼�Ϸ��Ĵ�
		if (tmp.size() == k) {
			ans.push_back(tmp);
			return;
		}
		//// cur == n + 1��ʱ������ݹ�
		//if (cur == n + 1) {
		//	return;
		//}
		// ����ѡ��ǰλ��
		tmp.push_back(cur);
		back(cur + 1, n, k);
		tmp.pop_back();
		// ���ǲ�ѡ��ǰλ��
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
