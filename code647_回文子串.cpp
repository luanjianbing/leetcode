#include <iostream>

using namespace std;

//����һ���ַ�����
//��������Ǽ�������ַ������ж��ٸ������Ӵ���
//
//���в�ͬ��ʼλ�û����λ�õ��Ӵ���
//��ʹ������ͬ���ַ���ɣ�
//Ҳ�ᱻ������ͬ���Ӵ���

class Solution {
public:
	int countSubstrings(string s) {
		//// 1. �г����еĻ������ģ�Ȼ���ҳ����еĻ��Ĵ�
		//// ������������������һ������ż����������������������
		//// n����������2n-1���������{left, right}��Ϊ0~2n-2
		//// ����left_i = i/2,right_i = left_i+i_mod(2)
		//int n = s.size(), ans = 0;
		//for (int i = 0; i < 2 * n - 1; ++i) {	// �������л�������
		//	int l = i / 2, r = i / 2 + i % 2;	// �õ����һ��ĵ�
		//	while (l >= 0 && r < n && s[l] == s[r]) {	// ������չ�жϻ���
		//		--l;
		//		++r;
		//		++ans;
		//	}
		//}         
		//return ans;

		// Manacher
		string newStr = "#";	// ��ʼ
		for (auto c : s) {
			newStr = newStr + c + "#";
		}
		// ���İ뾶��¼����
		int *rIndex = new int[newStr.length()];
		int c = -1;	// ��������
		int R = -1;	// �����ұ߽�
		int maxL = INT_MIN;		// ��¼������ֳ�
		int ans = 0;
		for (int i = 0; i < newStr.length(); ++i) {
			if (R > i)
				rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;	// �жϵ�ǰi���ԳƵ�i'�Ļ��ĳ��ȣ�ȡС��
			else
				rIndex[i] = 1;	// �����ұ߽��ڵ�ǰi����࣬���޻���

								//ȡ��Сֵ��ʼ�ӱ߽籩��ƥ�䣬ƥ��ʧ�ܾ�ֱ���˳�
			while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
			{
				if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//��������չ���һ�����ĸ
					rIndex[i]++;
				else
					break;
			}
			//�۲��ʱR��C�Ƿ��ܹ�����
			if (i + rIndex[i] > R)
			{
				R = i + rIndex[i];
				c = i;
			}
			//���������İ뾶��ֵ
			maxL = maxL > rIndex[i] ? maxL : rIndex[i];
			ans += (rIndex[i] / 2);
		}
		delete[] rIndex;
		return ans;
	}
};

int main() {

	return 0;
}
