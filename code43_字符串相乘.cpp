#include <iostream>
#include <sstream>

using namespace std;

//给定两个以字符串形式表示的非负整数 num1 和 num2，
//返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式

class Solution {
public:
	string multiply(string num1, string num2) {
		//// 1.暴力(溢出)
		//int n1 = 0, n2 = 0;
		//int length1 = num1.length();
		//int length2 = num2.length();
		//string res = "";
		//for (int i = 0; i < length1; ++i) 
		//	n1 = n1 * 10 + num1[i] - '0';
		//for (int i = 0; i < length2; ++i)
		//	n2 = n2 * 10 +  num2[i] - '0';
		//int resInt = n1 * n2;
		//res = to_string(resInt);
		//return res;
		
		// 2.字符串相乘在第几位上就加几个零 
		if (num1 == "0" || num2 == "0") {
			return "0";
		}
		string ans = "0";
		int m = num1.size(), n = num2.size();
		for (int i = n - 1; i >= 0; i--) {
			string curr;
			int add = 0;
			for (int j = n - 1; j > i; j--) {
				curr.push_back(0);
			}
			int y = num2.at(i) - '0';
			for (int j = m - 1; j >= 0; j--) {
				int x = num1.at(j) - '0';
				int product = x * y + add;
				curr.push_back(product % 10);
				add = product / 10;
			}
			while (add != 0) {
				curr.push_back(add % 10);
				add /= 10;
			}
			reverse(curr.begin(), curr.end());
			for (auto &c : curr) {
				c += '0';
			}
			ans = addStrings(ans, curr);
		}
		return ans;
	}

	string addStrings(string &num1, string &num2) {
		int i = num1.size() - 1, j = num2.size() - 1, add = 0;
		string ans;
		while (i >= 0 || j >= 0 || add != 0) {
			int x = i >= 0 ? num1.at(i) - '0' : 0;
			int y = j >= 0 ? num2.at(j) - '0' : 0;
			int result = x + y + add;
			ans.push_back(result % 10);
			add = result / 10;
			i--;
			j--;
		}
		reverse(ans.begin(), ans.end());
		for (auto &c : ans) {
			c += '0';
		}
		return ans;
	}
};

int main() {
	string num1 = "123";
	string num2 = "456";

	Solution s;
	string res = s.multiply(num1, num2);
	cout << res << endl;

	return 0;
}

