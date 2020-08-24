#include <iostream>
#include <sstream>

using namespace std;

//����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ�
//�������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		for (int i = 1; i * 2 <= n; ++i) {
			if (n % i == 0) {
				bool match = true;
				for (int j = i; j < n; ++j) {
					if (s[j] != s[j - i]) {
						match = false;
						break;
					}
				}
				if (match) {
					return true;
				}
			}
		}
		return false;
	}
};

int main() {
	string str = "abcabcabcac";

	Solution s;
	cout << s.repeatedSubstringPattern(str) << endl;

	return 0;
}
