#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//����һ���ַ��� s�������ͨ�����ַ���ǰ������ַ�����ת��Ϊ���Ĵ���
//�ҵ������ؿ��������ַ�ʽת������̻��Ĵ���
class Solution {
public:
	string shortestPalindrome(string s) {
		// 1. ManaCher��������ʱ��
		//// ��Ҫ�жϴ���㿪ʼ������Ĵ�����
		//// Ȼ�����û��Ĵ��ұ߽絽�ַ����ұ߽���ַ��������򲹳䵽ԭ�ַ�ǰ��
		//// �ַ���Ԥ����
		//string newStr = "#";
		//for (auto c : s) {
		//	newStr = newStr + c + "#";
		//}
		//// ���İ뾶��¼����
		//int *rIndex = new int[newStr.length()];
		//int c = -1;	// ��������
		//int R = -1;	// �����ұ߽�
		//int maxL = INT_MIN;		// ��¼������ֳ�
		//for (int i = 0; i <= newStr.length() / 2; ++i) {
		//	if (R > i)
		//		rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;	// �жϵ�ǰi���ԳƵ�i'�Ļ��ĳ��ȣ�ȡС��
		//	else
		//		rIndex[i] = 1;	// �����ұ߽��ڵ�ǰi����࣬���޻���

		//	//ȡ��Сֵ��ʼ�ӱ߽籩��ƥ�䣬ƥ��ʧ�ܾ�ֱ���˳�
		//	while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
		//	{
		//		if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//��������չ���һ�����ĸ
		//			rIndex[i]++;
		//		else
		//			break;
		//	}
		//	//�۲��ʱR��C�Ƿ��ܹ�����
		//	if (i + rIndex[i] > R)
		//	{
		//		R = i + rIndex[i];
		//		c = i;
		//	}
		//	//���������İ뾶��ֵ
		//	maxL = maxL > rIndex[i] ? maxL : rIndex[i];
		//}
		////for (int i = 0; i < newStr.length() / 2; i++) {
		////	cout << newStr[i] << " ";
		////}
		////cout << endl;
		////for (int j = 0; j < newStr.length() / 2; ++j) {
		////	cout << rIndex[j] << " ";
		////}
		//if (R == newStr.length()) return s;
		//// �ҵ������Χ�ڻ�����߽�Ϊ0���һ��İ뾶����
		//int tarIdx = 0;
		//for (int i = newStr.length() / 2 - 1; i >= 0; --i) {
		//	if (i - (rIndex[i] - 1) == 0) {
		//		tarIdx = i;
		//		break;
		//	}
		//}
		//string ans = "";
		//for (int i = s.length() - 1; i >= tarIdx; --i) {
		//	ans += s[i];
		//}
		//ans += s;
		//return ans;

		//// 2. Rabin-Karp 
		//int n = s.size();
		//int base = 131, mod = 1000000007;
		//int left = 0, right = 0, mul = 1;
		//int best = -1;
		//for (int i = 0; i < n; ++i) {
		//	left = ((long long)left * base + s[i]) % mod;
		//	right = (right + (long long)mul * s[i]) % mod;
		//	if (left == right) {
		//		best = i;
		//	}
		//	mul = (long long)mul * base % mod;
		//}
		//string add = (best == n - 1 ? "" : s.substr(best + 1, n));
		//reverse(add.begin(), add.end());
		//return add + s;

		// 3. KMP
		int n = s.size();
		vector<int> fail(n, -1);
		for (int i = 1; i < n; ++i) {
			int j = fail[i - 1];
			while (j != -1 && s[j + 1] != s[i]) {
				j = fail[j];
			}
			if (s[j + 1] == s[i]) {
				fail[i] = j + 1;
			}
		}
		int best = -1;
		for (int i = n - 1; i >= 0; --i) {
			while (best != -1 && s[best + 1] != s[i]) {
				best = fail[best];
			}
			if (s[best + 1] == s[i]) {
				++best;
			}
		}
		string add = (best == n - 1 ? "" : s.substr(best + 1, n));
		reverse(add.begin(), add.end());
		return add + s;
	}
};

int main() {
	string str = "absds";

	Solution s;
	cout << s.shortestPalindrome(str) << endl;
	return 0;
}
