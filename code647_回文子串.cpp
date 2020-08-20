#include <iostream>

using namespace std;

//给定一个字符串，
//你的任务是计算这个字符串中有多少个回文子串。
//
//具有不同开始位置或结束位置的子串，
//即使是由相同的字符组成，
//也会被视作不同的子串。

class Solution {
public:
	int countSubstrings(string s) {
		//// 1. 列出所有的回文中心，然后找出所有的回文串
		//// 奇数个数回文中心是一个数，偶数个数回文中心是两个数
		//// n个数会生成2n-1组回文中心{left, right}，为0~2n-2
		//// 其中left_i = i/2,right_i = left_i+i_mod(2)
		//int n = s.size(), ans = 0;
		//for (int i = 0; i < 2 * n - 1; ++i) {	// 遍历所有回文中心
		//	int l = i / 2, r = i / 2 + i % 2;	// 得到左右回文点
		//	while (l >= 0 && r < n && s[l] == s[r]) {	// 左右扩展判断回文
		//		--l;
		//		++r;
		//		++ans;
		//	}
		//}         
		//return ans;

		// Manacher
		string newStr = "#";	// 起始
		for (auto c : s) {
			newStr = newStr + c + "#";
		}
		// 回文半径记录数组
		int *rIndex = new int[newStr.length()];
		int c = -1;	// 回文中心
		int R = -1;	// 回文右边界
		int maxL = INT_MIN;		// 记录最长回文字长
		int ans = 0;
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
			//更新最大回文半径的值
			maxL = maxL > rIndex[i] ? maxL : rIndex[i];
			ans += (rIndex[i] / 2);
		}
		delete[] rIndex;
		return ans;
	}
};

int main() {

	return 0;
}
