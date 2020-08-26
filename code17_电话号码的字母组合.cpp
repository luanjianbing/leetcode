#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
//
//����һ������������ 2 - 9 ���ַ����������������ܱ�ʾ����ĸ��ϡ�
//
//�������ֵ���ĸ��ӳ�����£���绰������ͬ����ע�� 1 ����Ӧ�κ���ĸ��

class Solution {
public:
	void backtrack(vector<string>& res, const unordered_map<char, string>& pairs, 
		const string& digits, int idx, string& combination) {
		if (idx == digits.length())
			res.push_back(combination);
		else
		{
			char digit = digits[idx];
			const string &letters = pairs.at(digit);	// �õ������ַ�����
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
		// 1.����ӳ��Ȼ��������п���
		// ����ӳ���ϵ
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
		// ����digits�е��ַ���n������2^n��
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
