#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

//����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��
//ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

class Solution {
public:
	string reverseWords(string s) {
		if (s.length() == 0 || s.length() == 1) return s;
		vector<string> splitWord;
		int firstIdx = 0;
		int secondIdx = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == ' ' || i == s.length() - 1) {
				string thisWord = "";
				if (i != s.length() - 1) secondIdx = i - 1;
				else secondIdx = i;
				for (int j = secondIdx; j >= firstIdx; --j) {
					thisWord += s[j];
				}
				splitWord.push_back(thisWord);
				firstIdx = i + 1;
			}
		}

		string ans = "";
		for (int i = 0; i < splitWord.size() - 1; ++i) {
			ans = ans + splitWord[i] + " ";
		}
		ans += splitWord.back();

		return ans;
	}
};

int main() {
	string str = "Let's take LeetCode contest";

	Solution s;
	cout << s.reverseWords(str) << endl;

	return 0;
}
