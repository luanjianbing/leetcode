#include <iostream>
#include <vector>
#include <algorithm>

//����һ�������� n��������Ϊ���������������ĺͣ�
//��ʹ��Щ�����ĳ˻���󻯡� ��������Ի�õ����˻���

using namespace std;

class Solution {
public:

	int integerBreak(int n) {
		// 1. ��̬�滮
		vector<int> dp(n + 1, 0);
		for (int i = 2; i < (n + 1); ++i) {
			int curMax = 0;
			for (int j = 1; j < i; ++j) {
				curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
			}
			dp[i] = curMax;
		}
		return dp[n];

		// 2. �Ż���̬�滮

	}
};

int main() {
	Solution s;
	int n = 10;
	int res = s.integerBreak(n);
	cout << res << endl;

	return 0;
}
