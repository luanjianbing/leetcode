#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
//
//给定一个仅包含数字 2 - 9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

class Solution {
public:
	void backtrack(vector<string>& res, const unordered_map<char, string>& pairs, 
		const string& digits, int idx, string& combination) {
		if (idx == digits.length())
			res.push_back(combination);
		else
		{
			char digit = digits[idx];
			const string &letters = pairs.at(digit);	// 得到所有字符可能
			for (const char& letter : letters) {
				combination.push_back(letter);
				backtrack(res, pairs, digits, idx + 1, combination);
				combination.pop_back();
			}
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<string> res;
		if (digits.empty()) {
			return res;
		}
		// 1.建立映射然后查找所有可能
		// 建立映射关系
		unordered_map<char, string> pairs = {
			{ '2', "abc" },
			{ '3', "def" },
			{ '4', "ghi" },
			{ '5', "jkl" },
			{ '6', "mno" },
			{ '7', "pqrs" },
			{ '8', "tuv" },
			{ '9', "wxyz" }
		};	// 
		// 查找digits中的字符数n，共有2^n个
		string combination;
		backtrack(res, pairs, digits, 0, combination);
		return res;
	}
};

int main() {
	string digits = "23";

	Solution s;
	vector<string> res = s.letterCombinations(digits);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}
