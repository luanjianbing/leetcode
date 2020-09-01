#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ����ʾ�����ķǸ��������顣 
//��� 1 ����������һ����ȡһ��������
//������ 2 ������ʣ����������һ����ȡ������
//Ȼ����� 1 �ã����� ��
//ÿ��һ�����ֻ����ȡһ����������������ȡ֮���ٿ�ȡ��
//ֱ��û��ʣ�������ȡʱ��Ϸ������
//���ջ�÷����ܺ�������һ�ʤ��
//
//����һ����ʾ���������飬Ԥ�����1�Ƿ���ΪӮ�ҡ�
//����Լ���ÿ����ҵ��淨����ʹ���ķ�����󻯡�

class Solution {
public:
	int total(vector<int> &nums, int start, int end, int turn) {
		if (start == end)	// ������ֻʣһλ��
			return nums[start] * turn;
		int scoreStart = nums[start] * turn + total(nums, start + 1, end, -turn);
		int scoreEnd = nums[end] * turn + total(nums, start, end - 1, -turn);
		return max(scoreStart * turn, scoreEnd * turn) * turn;
	}

	bool PredictTheWinner(vector<int>& nums) {
		//// 1. �ݹ�
		//return total(nums, 0, nums.size() - 1, 1) >= 0;

		// 2. ��̬�滮
		// dp[i][j]��ʾ������ʣ�µĲ���Ϊ�±� i ���±� j ʱ����ǰ�������һ����ҵķ���֮������ֵ��ע�⵱ǰ��Ҳ�һ��������
		// ֻ�е�i <= jʱ������ʣ�µĲ��ֲ�������
		// ���i > jʱ��dp[i][j] = 0
		// ���̣�dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
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
