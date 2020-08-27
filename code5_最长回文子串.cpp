#include <iostream>
#include <sstream>

using namespace std;

//给定一个字符串 s，找到 s 中最长的回文子串。
//你可以假设 s 的最大长度为 1000。

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 0 || s.length() == 1) return s;
		// manache
		string newStr = "#";
		for (auto c : s) 
			newStr = newStr + c + "#";
		// 回文半径记录数组
		int *rIndex = new int[newStr.length()];
		int c = -1;	// 回文中心
		int R = -1;	// 回文右边界
		int maxL = INT_MIN;	// 记录最长回文字长
		int maxIdx = 0;
		for (int i = 0; i < newStr.length(); ++i) {
			if (R > i)
				rIndex[i] = rIndex[2 * c - i] < R - i ? rIndex[2 * c - i] : R - i;	// 判断当前i跟对称的i'的回文长度，取小的
			else
				rIndex[i] = 1;	// 回文右边界在当前i的左侧，即无回文
			//取最小值后开始从边界暴力匹配，匹配失败就直接退出
			while (i + rIndex[i] < newStr.length() && i - rIndex[i] > -1)
			{
				if (newStr[i + rIndex[i]] == newStr[i - rIndex[i]])//向两边扩展，找回文字母
					rIndex[i]++;
				else
					break;
			}
			//观察此时R和C是否能够更新
			if (i + rIndex[i] > R)
			{
				R = i + rIndex[i];
				c = i;
			}
			if (maxL < rIndex[i]) {
				maxL = rIndex[i];
				maxIdx = i;
			}
			////更新最大回文半径的值
			//maxL = maxL > rIndex[i] ? maxL : rIndex[i];
		}
		delete[] rIndex;
		//这里解释一下为什么返回值是maxn-1，因为manacherstring的长度和原字符串不同，
		//所以这里得到的最大回文半径其实是原字符串的最大回文子串长度加1，
		//有兴趣的可以自己验证试试,-1是为了将后面的‘#’去掉
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
