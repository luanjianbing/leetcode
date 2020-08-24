#include <iostream>

using namespace std;

//������Χ[m, n]������ 0 <= m <= n <= 2147483647��
//���ش˷�Χ���������ֵİ�λ�루���� m, n ���˵㣩��

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		// ��λ����Ҫ֪��ÿһλ���������Ƿ����0
		// ����0�Ļ��Ǹ�λ�þ�Ϊ0
		// int���ʹ洢����4�ֽ�,32λ
		if ((m <= 0 && n > 0) || (m < 0 && n >= 0)) return 0;
		//// 1. �����루��ʱ��
		//int ans = INT32_MAX;
		//for (int cur = m; cur <= n; ++cur) 
		//	ans &= cur;
		//return ans;

		// 2. ������ǰ׺(λ��)
		int shift = 0;
		// �ҵ�����ǰ׺
		while (m < n) {
			m >>= 1;
			n >>= 1;
			++shift;
		}
		return m << shift;

		////Brian Kernighan �㷨
		//while (m < n)
		//	n = n & (n - 1);
		//return n;

		
	}
};

int main() {
	int m = 5;
	int n = 7;

	Solution s;
	cout << s.rangeBitwiseAnd(m, n) << endl;

	return 0;
}
