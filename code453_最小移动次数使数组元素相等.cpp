#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//����һ������Ϊ n �ķǿ��������飬
//�ҵ�����������Ԫ����ȵ���С�ƶ�������
//ÿ���ƶ�����ʹ n - 1 ��Ԫ������ 1��

class Solution {
public:
	int minMoves(vector<int>& nums) {
		// ��̬�滮
		// ���Ƚ�nums����
		sort(nums.begin(), nums.end());
		int moves = 0;
		for (int i = 1; i < nums.size(); ++i) {
			int diff = (moves + nums[i]) - nums[i - 1];
			nums[i] += moves;
			moves += diff;
		}
		return moves;
	}
};

int main() {
	vector<int> nums = { 1, 2, 3 };
	Solution s;
	int res = s.minMoves(nums);
	cout << res << endl;

	return 0;
}
