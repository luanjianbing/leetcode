#include <iostream>
#include <stack>

using namespace std;

//给定一个包含正整数、
//加(+)、减(-)、乘(*)、除(/ )的算数表达式(括号除外)，
//计算其结果。
//
//表达式仅包含非负整数， + ， - ，*， / 
//四种运算符和空格  。 
//整数除法仅保留整数部分。

class Solution {
public:
	int calculate(string s) {
		stack<char> stackOpt;
		stack<int> stackNum;

		for (int i = 0; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9') {	// 数字
				int thisNum = s[i] - '0';
				while (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					thisNum = thisNum * 10 + (s[i + 1] - '0');
					i++;
				}
				stackNum.push(thisNum);
			}
			else if (s[i] == ' ')	// 空格
			{
				continue;
			}
			else {	// 符号
				if (s[i] == '*' || s[i] == '/') {
					char thisOpt = s[i];
					// 需要找到下一个不为空格的位置
					if (s[i + 1] == ' ')
						while (s[++i] == ' ');
					else
						i++;
					int frontNum = stackNum.top();
					int thisRes = 0;
					int nextNum = s[i] - '0';
					if ((i + 1) < s.length()) {
						while (s[i + 1] >= '0' && s[i + 1] <= '9')
						{
							nextNum = nextNum * 10 + (s[i + 1] - '0');
							i++;
						}
					}
					if (thisOpt == '*')
						thisRes = frontNum * nextNum;
					else
						thisRes = frontNum / nextNum;
					stackNum.pop();
					stackNum.push(thisRes);
				}
				else
					stackOpt.push(s[i]);
			}
		}
		
		// 为了避免从后往前算引起'-'后面需要加括号计算的情况
		// 需要将栈内元素反过来计算

		stack<char> stkOpt;
		stack<int> stkNum;

		while (!stackOpt.empty()) {
			stkOpt.push(stackOpt.top());
			stackOpt.pop();
		}
		while (!stackNum.empty()) {
			stkNum.push(stackNum.top());
			stackNum.pop();
		}

		while (stkNum.size() > 1) {
			int num1 = stkNum.top();
			stkNum.pop();
			int num2 = stkNum.top();
			stkNum.pop();
			char operation = stkOpt.top();
			stkOpt.pop();

			int res = 0;
			if (operation == '+')
				res = num1 + num2;
			else
				res = num1 - num2;

			stkNum.push(res);
		}
		
		return stkNum.top();
	}
};

int main() {
	string str = "1*2-3/4+5*6-7*8+9/10";

	Solution s;
	cout << s.calculate(str) << endl;

	return 0;
}
