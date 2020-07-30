#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int calPoints(vector<string>& ops) {
	//	// 1. 线性搜索
	//	int totalScore = 0;
	//	for (int i = 0; i < ops.size(); ++i)
	//	{
	//		int curScore = 0;
	//		if (ops[i] == "+") {
	//			int idx1 = 0, idx2 = 0;
	//			do {
	//				idx1++;
	//			} while (ops[i - idx1] == "0");
	//			idx2 = idx1;
	//			do {
	//				idx2++;
	//			} while (ops[i - idx2] == "0");
	//			curScore = atoi(ops[i - idx1].c_str()) + atoi(ops[i - idx2].c_str());
	//			ops[i] = to_string(curScore);
	//		}
	//		else if (ops[i] == "D") {
	//			int idx = 0;
	//			do {
	//				idx++;
	//			} while (ops[i - idx] == "0");
	//			curScore = 2 * atoi(ops[i - idx].c_str());
	//			ops[i] = to_string(curScore);
	//			
	//		}
	//		else if (ops[i] == "C"){
	//			int idx = 0;
	//			do{
	//				idx++;
	//			} while (ops[i - idx] == "0");
	//			ops[i] = "0";
	//			curScore = -atoi(ops[i - idx].c_str());
	//			ops[i - idx] = "0";
	//		}
	//		else {
	//			curScore = atoi(ops[i].c_str());
	//		}
	//		
	//		totalScore += curScore;
	//		cout << curScore << " " << totalScore << endl;
	//	}
	//	return totalScore;


	// 2. 栈(无用丢弃)
		stack<int> myStack;
		for (int i = 0; i < ops.size(); ++i) {
			if (ops[i] == "+") {
				int top = myStack.top();
				myStack.pop();
				int newTop = top + myStack.top();
				myStack.push(top);
				myStack.push(newTop);
			}
			else if (ops[i] == "C") {
				myStack.pop();
			}
			else if (ops[i] == "D") {
				myStack.push(2 * myStack.top());
			}
			else {
				myStack.push(stoi(ops[i]));
			}
		}
		int ans = 0;
		while (!myStack.empty()) {
			ans += myStack.top();
			myStack.pop();
		}
		return ans;
	}
};

int main() {
	vector<string> ops = { "5", "2", "C", "D", "+" };
	Solution s;
	int res = s.calPoints(ops);
	cout << res << endl;

	return 0;
}
