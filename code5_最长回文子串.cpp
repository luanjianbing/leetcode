#include <iostream>
#include <sstream>

using namespace std;

//����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
//����Լ��� s ����󳤶�Ϊ 1000��

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 0 || s.length() == 1) return s;
		// manache
		string newStr = "#";
		for (auto c : s) 
			newStr = newStr + c + "#";
		// ���İ뾶��¼����
		int *rIndex = new int[newStr.length()];
		int c = -1;	// ��������
		int R = -1;	// �����ұ߽�
		int maxL = INT_MIN;	// ��¼������ֳ�
		int maxIdx = 0;
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
			if (maxL < rIndex[i]) {
				maxL = rIndex[i];
				maxIdx = i;
			}
			////���������İ뾶��ֵ
			//maxL = maxL > rIndex[i] ? maxL : rIndex[i];
		}
		delete[] rIndex;
		//�������һ��Ϊʲô����ֵ��maxn-1����Ϊmanacherstring�ĳ��Ⱥ�ԭ�ַ�����ͬ��
		//��������õ��������İ뾶��ʵ��ԭ�ַ������������Ӵ����ȼ�1��
		//����Ȥ�Ŀ����Լ���֤����,-1��Ϊ�˽�����ġ�#��ȥ��
		string ans = "";
		for (int i = maxIdx - (maxL - 1); i <  maxIdx + (maxL - 1); ++i) {
			if (newStr[i] != '#') {
				ans += newStr[i];
			}
		}
		return ans;

	}
};

int main() {
	string str = "accaa";

	Solution s;
	cout << s.longestPalindrome(str) << endl;

	return 0;
}
