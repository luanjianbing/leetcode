#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。
//找到并返回可以用这种方式转换的最短回文串。
class Solution {
public:
	string shortestPalindrome(string s) {
		// 1. ManaCher（特例超时）
		//// 需要判断从起点开始的最长回文串长度
		//// 然后计算该回文串右边界到字符串右边界的字符串，反向补充到原字符前方
		//// 字符串预处理
		//string newStr = "#";
		//for (auto c : s) {
		//	newStr = newStr + c + "#";
		//}
		//// 回文半径记录数组
		//int *rIndex = new int[newStr.length()];
		//int c = -1;	// 回文中心
		//int R = -1;	// 回文右边界
		//int maxL = INT_MIN;		// 记录最长回文字长
		//for (int i = 0; i <= newStr.length() / 2; ++i) {
		//	if (R > i)
		//		rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;	// 判断当前i跟对称的i'的回文长度，取小的
		//	else
		//		rIndex[i] = 1;	// 回文右边界在当前i的左侧，即无回文

		//	//取最小值后开始从边界暴力匹配，匹配失败就直接退出
		//	while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
		//	{
		//		if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//向两边扩展，找回文字母
		//			rIndex[i]++;
		//		else
		//			break;
		//	}
		//	//观察此时R和C是否能够更新
		//	if (i + rIndex[i] > R)
		//	{
		//		R = i + rIndex[i];
		//		c = i;
		//	}
		//	//更新最大回文半径的值
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
		//// 找到这个范围内回文左边界为0，且回文半径最大的
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
