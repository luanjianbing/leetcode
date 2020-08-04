#include <iostream>
#include <vector>

using namespace std;

//ħ�������� ������A[0...n - 1]�У�����ν��ħ����������������A[i] = i��
//����һ�������������飬��дһ�ַ����ҳ�ħ�����������еĻ���������A���ҳ�һ��ħ��������
//���û�У��򷵻� - 1�����ж��ħ����������������ֵ��С��һ����



class Solution {
public:
	int getAnswer(vector<int> nums, int left, int right) {
		if (left > right)	// �Ҳ����Ƴ�����
			return -1;
		int mid = (right - left) / 2 + left;
		int leftAnswer = getAnswer(nums, left, mid - 1);
		if (leftAnswer != -1) {	// ˵���ҵ���һ��
			return leftAnswer;
		}
		else if (nums[mid] == mid) {
			return mid;
		}
		return getAnswer(nums, mid + 1, right);
	}

	int findMagicIndex(vector<int>& nums) {
		//// 1. ��������
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (i == nums[i]) return i;
		//}
		//return -1;

		// 2. ���ּ�֦��ĳЩ������в���ı��֣�
		// �����ǰ�е���ħ����������ֻ������߲��֣�������������߶��ÿ���
		return getAnswer(nums, 0, (int)nums.size() - 1);
	}
};

int main()
{
	vector<int> nums = {0, 2, 3, 4, 5};
	Solution s;
	int res = s.findMagicIndex(nums);
	cout << res << endl;

	return 0;
}