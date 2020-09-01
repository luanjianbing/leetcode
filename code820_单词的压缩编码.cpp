#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
//
//例如，如果这个列表是["time", "me", "bell"]，
//我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
//
//对于每一个索引，
//我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，
//来恢复我们之前的单词列表。
//
//那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

class TrieNode {
	TrieNode* children[26];
public:
	int count;
	TrieNode() {
		for (int i = 0; i < 26; ++i) children[i] = NULL;
		count = 0;
	}
	TrieNode* get(char c) {
		if (children[c - 'a'] == NULL) {
			children[c - 'a'] = new TrieNode();
			count++;
		}
		return children[c - 'a'];
	}
};

class Solution {
public:
	int minimumLengthEncoding(vector<string>& words) {
		//// 1. 后缀删除
		//unordered_set<string> good(words.begin(), words.end());
		//for (const string& word : words) {
		//	for (int k = 1; k < word.size(); ++k) {
		//		good.erase(word.substr(k));
		//	}
		//}

		//int ans = 0;
		//for (const string& word : good) {
		//	ans += word.size() + 1;
		//}
		//return ans;

		// 2. 字典树
		TrieNode* trie = new TrieNode();
		unordered_map<TrieNode*, int> nodes;

		for (int i = 0; i < (int)words.size(); ++i) {
			string word = words[i];
			TrieNode* cur = trie;
			for (int j = word.length() - 1; j >= 0; --j)
				cur = cur->get(word[j]);
			nodes[cur] = i;
		}

		int ans = 0;
		for (auto&[node, idx] : nodes) {
			if (node->count == 0) {
				ans += words[idx].length() + 1;
			}
		}
		return ans;
	}
};

int main() {
	vector<string> words = { "time", "me", "bell" };

	Solution s;
	cout << s.minimumLengthEncoding(words) << endl;

	return 0;
}
