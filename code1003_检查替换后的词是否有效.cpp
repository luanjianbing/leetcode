#include <iostream>
#include <stack>

using namespace std;

//给定有效字符串 "abc"。
//
//对于任何有效的字符串 V，我们可以将 V 分成两个部分 X 和 Y，
//使得 X + Y（X 与 Y 连接）等于 V。（X 或 Y 可以为空。）
//那么，X + "abc" + Y 也同样是有效的。
//
//例如，如果 S = "abc"，则有效字符串的示例是："abc"，"aabcbc"，"abcabc"，"abcabcababcc"。
//无效字符串的示例是："abccba"，"ab"，"cababc"，"bac"。
//
//如果给定字符串 S 有效，则返回 true；否则，返回 false。


class Solution {
public:
	bool isValid(string S) {
		if (S.empty()) return true;
		int sLength = S.length();
		stack<char> myStack;
		for (int i = 0; i < sLength; ++i) {
			if (S[i] == 'c') {
				if (myStack.size() >= 2) {
					if(myStack.top() == 'b') myStack.pop();
					else return false;
					if (myStack.top() == 'a')myStack.pop();
					else return false;
				}
				else
					return false;
			}
			else
			{
				myStack.push(S[i]);
			}
		}
		if (myStack.empty())
			return true;
		else
			return false;
	}
};

int main() {
	string str = "cababc";

	Solution s;
	cout << s.isValid(str) << endl;

	return 0;
}
