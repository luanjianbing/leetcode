#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
//
//你可以对一个单词进行如下三种操作：
//
//插入一个字符
//删除一个字符
//替换一个字符


class Solution {
public:
	int minDistance(string word1, string word2) {
		//// 1. 递归（超时），自顶向下
		//if (word1.length() == 0 || word2.length() == 0)		// 定义递归出口
		//	return max(word1.length(), word2.length());
		//if (word1.back() == word2.back())	// 最后字符相同，看前面一位结果
		//	return minDistance(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1));
		//// 否则进行插入，删除，替换
		//return 1 + min(min(minDistance(word1, word2.substr(0, word2.length() - 1)),
		//	minDistance(word1.substr(0, word1.length() - 1), word2)),
		//	minDistance(word1.substr(0, word1.length() - 1), word2.substr(0, word2.length() - 1)));

		// 2. 动态规划，自底向上
		int length1 = word1.size();
		int length2 = word2.size();

		vector<vector<int>> op;
		// 构造初始解
		for (int i = 0; i < length1 + 1; ++i) {
			vector<int> row;
			for (int j = 0; j < length2 + 1; ++j) {
				if (i == 0)
					row.push_back(j);
				else if (j == 0)
					row.push_back(i);
				else
					row.push_back(0);
			}
			op.push_back(row);
		}
		// 动态规划
		for (int i = 0; i < length1; ++i) {
			for (int j = 0; j < length2; ++j) {
				if (word1[i] == word2[j]) {
					op[i + 1][j + 1] = op[i][j];
				}
				else {
					op[i + 1][j + 1] = min(min(op[i + 1][j], op[i][j + 1]), op[i][j]);
				}
			}
		}
		return op[length1][length2];
	}
};

int main() {

	return 0;
}
