#include <iostream>
#include <unordered_map>

using namespace std;

//给定两个字符串 s 和 t，判断它们是否是同构的。
//
//如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//
//所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。
//两个字符不能映射到同一个字符上，但字符可以映射自己本身。

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<char, int> pairs;
		unordered_map<char, int> pairt;
		vector<int> vects(s.length(), 0);
		vector<int> vectt(t.length(), 0);
		// 两个字符串长度相同
		// 以第一个字母出现为1，之后出现的另外不同字符—+1
		for (int i = 0; i < s.length(); ++i) {
			if (pairs.find(s[i]) == pairs.end())
				pairs.insert(make_pair(s[i], i));
			if (pairt.find(t[i]) == pairt.end())
				pairt.insert(make_pair(t[i], i));
		}
		for (int i = 0; i < s.length(); ++i) {
			vects[i] = pairs[s[i]];
			vectt[i] = pairt[t[i]];
		}
		for (int i = 0; i < vects.size(); ++i) {
			if (vects[i] != vectt[i])
				return false;
		}
		return true;
	}
	//bool isIsomorphic(string s, string t) {
	//	if (0 == s.size() && 0 == t.size())
	//	{
	//		return true;
	//	}

	//	for (int index = 0; index <= s.size() - 1; index++)
	//	{
	//		if (s.find(s[index]) != t.find(t[index]))
	//		{
	//			return false;
	//		}
	//	}

	//	return true;
	//}

};

int main() {
	string s1 = "paper";
	string t1 = "title";

	Solution s;
	cout << s.isIsomorphic(s1, t1) << endl;

	return 0;
}
