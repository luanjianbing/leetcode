#include <iostream>
#include <vector>

using namespace std;

//���� 4 ��д�� 1 �� 9 ���ֵ��ơ�
//����Ҫ�ж��Ƿ���ͨ�� *�� / �� + �� - ��(��) ������õ� 24��
//
//ʾ�� 1:

class Solution {
public:
	static constexpr int TARGET = 24;	// Ŀ���ֵ
	static constexpr double EPSILON = 1e-6;	// ʵ��������������10(-6)����Ϊ����
	static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;	// ����4���������

	bool judgePoint24(vector<int> &nums) {
		vector<double> l;
		for (const int &num : nums) {					// ��Ϊ����ʵ��������������������
			l.emplace_back(static_cast<double>(num)); // ǿ��ת��Ϊdouble�ͽ��д���
		}
		return solve(l);
	}

	bool solve(vector<double> &l) {
		if (l.size() == 0) {	// �����룬�޷�����
			return false;
		}
		if (l.size() == 1) {	// ֻ��һ�����룬�ж�����ֵ��target�Ĳ�ֵ�Ƿ����Ҫ��
			return fabs(l[0] - TARGET) < EPSILON;
		}
		int size = l.size();	// �����������size
		for (int i = 0; i < size; i++) {	// ����������(double)
			for (int j = 0; j < size; j++) {	// ������ǰ�����������
				if (i != j) {	// ���ǳ�������֮������
					vector<double> list2 = vector<double>();
					// ����������������������ȡ���Ѿ���ϵ���λ��
					for (int k = 0; k < size; k++) {
						if (k != i && k != j) {	// ѹ�������ϵ���������������
							list2.emplace_back(l[k]);
						}
					}
					for (int k = 0; k < 4; k++) {
						if (k < 2 && i > j) {	// �Ӽ������� 
							continue;
						}
						// ÿ��������������м���ֵ����ѹ��list
						if (k == ADD) {
							list2.emplace_back(l[i] + l[j]);
						}
						else if (k == MULTIPLY) {
							list2.emplace_back(l[i] * l[j]);
						}
						else if (k == SUBTRACT) {
							list2.emplace_back(l[i] - l[j]);
						}
						else if (k == DIVIDE) {
							if (fabs(l[j]) < EPSILON) {	// �жϳ���Ϊ0�����
								continue;
							}
							list2.emplace_back(l[i] / l[j]);
						}

						if (solve(list2)) {
							return true;
						}
						list2.pop_back();
					}
				}
			}
		}
		return false;
	}
};

int main() {
	vector<int> nums = { 4, 1, 8 ,7 };
	Solution s;
	cout << s.judgePoint24(nums) << endl;

	return 0;
}
