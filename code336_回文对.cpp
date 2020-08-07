#include <iostream>
#include <vector>

using namespace std;

//给定一组唯一的单词， 找出所有不同 的索引对(i, j)，
//使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。

//输入: ["abcd", "dcba", "lls", "s", "sssll"]
//输出 : [[0, 1], [1, 0], [3, 2], [2, 4]]
//解释 : 可拼接成的回文串为["dcbaabcd", "abcddcba", "slls", "llssssll"]

class Solution {
public:
	struct Node
	{
		int ch[26];
		int flag;
		Node() {
			flag = -1;
			memset(ch, 0, sizeof(ch));
		}
	};

	vector<Node> tree;

	void insert(string &str, int id) {
		int add = 0;
		for (int i = 0; i < str.length(); ++i) {
			int idx = str[i] - 'a';
			if (!tree[add].ch[idx]) {
				tree.emplace_back();	// 没有参数的话默认插入一个构造参数为0的节点
				tree[add].ch[idx] = tree.size() - 1;	// 更新上一步的节点指向
			}
			add = tree[add].ch[idx];
		}
		tree[add].flag = id;	// 字符串完毕后更新标志位表示完结
	}

	// 判断该字符串是否回文
	bool isPalindrome(string& s, int left, int right) {
		int len = right - left + 1;
		for (int i = 0; i < len / 2; i++) {
			if (s[left + i] != s[right - i]) {	// 从中间向两边判断
				return false;
			}
		}
		return true;
	}

	int findWord(string& s, int left, int right) {
		int add = 0;
		for (int i = right; i >= left; i--) {
			int x = s[i] - 'a';
			if (!tree[add].ch[x]) {
				return -1;
			}
			add = tree[add].ch[x];
		}
		return tree[add].flag;
	}

	vector<vector<int>> palindromePairs(vector<string>& words) {
		tree.emplace_back(Node());	// 压入一个根节点
		int n = words.size();	// 字符串总个数
		for (int i = 0; i < n; i++) {
			insert(words[i], i);
		}

		vector<vector<int>> ret;
		for (int i = 0; i < n; i++) {
			int m = words[i].size();
			for (int j = 0; j <= m; j++) {
				// 分为两块进行判断
				if (isPalindrome(words[i], j, m - 1)) {	// 右边
					int left_id = findWord(words[i], 0, j - 1);	// 判断字典树中存不存在该字符
					if (left_id != -1 && left_id != i) {	
						ret.push_back({ i, left_id });
					}
				}
				if (j && isPalindrome(words[i], 0, j - 1)) {	// 左边
					int right_id = findWord(words[i], j, m - 1);
					if (right_id != -1 && right_id != i) {
						ret.push_back({ right_id, i });
					}
				}
			}
		}
		return ret;
	}
};

int main() {
	vector<string> words = { "abcd", "dcba", "lls", "s", "sssll" };
	Solution s;
	vector<vector<int>> res = s.palindromePairs(words);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	//vector<int> test;
	//test.emplace_back();
	//for (int i = 0; i < test.size(); ++i)
	//	cout << test[i] << " ";


	return 0;
}
