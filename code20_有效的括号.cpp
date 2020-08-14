#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。


class Solution {
public:
	bool isValid(string s) {
		//// 返回true的情况只有两种(错误)
		//// 1. 顺序 2.中心对称
		//int lenStr = s.length();
		//if (!lenStr) return true;
		//bool isSituationOne = true;
		//if (lenStr % 2) return false;
		//for (int i = 0; i < lenStr; i += 2) {
		//	if (!(s[i + 1] - s[i] > 0 && s[i + 1] - s[i] < 5))
		//		isSituationOne = false;
		//}
		//if (isSituationOne)
		//{
		//	return true;
		//}
		//else
		//{
		//	int mid = lenStr / 2;
		//	int ptrLeft = mid - 1;
		//	int ptrRight = mid;
		//	while (ptrLeft >= 0) {
		//		if (!(s[ptrRight] - s[ptrLeft] > 0 && s[ptrRight] - s[ptrLeft] < 5))
		//			break;
		//		ptrLeft--;
		//		ptrRight++;
		//	}

		//	if (ptrLeft < 0)
		//		return true;
		//	return false;
		//}

		// 使用栈结构
		int n = s.length();
		if (n % 2)return false;

		unordered_map <char, char> pairs = {
			{')', '('}, {']', '['}, {'}', '{'}
		};

		stack<char> myStack;
		for (char ch : s) {
			if (pairs.count(ch)) {
				if (myStack.empty() || myStack.top() != pairs[ch]) {
					return false;
				}
				myStack.pop();
			}
			else {
				myStack.push(ch);
			}
		}

		return myStack.empty();
	}
};

int main() {
	string str = "([)]";
	Solution s;
	bool res = s.isValid(str);
	cout << res << endl;

	return 0;
}
