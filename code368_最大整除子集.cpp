#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//����һ�������ظ�����������ɵļ��ϣ�
//�ҳ��������������Ӽ���
//�Ӽ�������һ��(Si��Sj) ��Ҫ���㣺
//Si % Sj = 0 �� Sj % Si = 0��
//
//����ж��Ŀ���Ӽ������������κ�һ�����ɡ�

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return nums;

		sort(nums.begin(), nums.end());

		vector<vector<int>> EDS(nums.size());

		for (int i = 0; i < n; ++i) {
			vector<int> maxSubSet;
			for (int k = 0; k < i; ++k) {
				if (nums[i] % nums[k] == 0 && maxSubSet.size() < EDS[k].size())
					maxSubSet = EDS[k];
			}
			for (int j = 0; j < maxSubSet.size(); ++j) {
				EDS[i].push_back(maxSubSet[j]);
			}
			EDS[i].push_back(nums[i]);
		}

		vector<int> ret;
		for (int i = 0; i < n; ++i)
			if (ret.size() < EDS[i].size())
				ret = EDS[i];
		return ret;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3 };

	Solution s;
	vector<int> res = s.largestDivisibleSubset(nums);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}
