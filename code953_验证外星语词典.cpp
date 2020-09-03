#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//某种外星语也使用英文小写字母，但可能顺序 order 不同。
//字母表的顺序（order）是一些小写字母的排列。
//
//给定一组用外星语书写的单词 words，以及其字母表的顺序 order，
//只有当给定的单词在这种外星语中按字典序排列时，
//返回 true；否则，返回 false

class Solution {
public:
	bool isAlienSorted(vector<string>& words, string order) {
		unordered_map<char, int> dictions;
		for (int i = 0; i < order.length(); ++i) {
			char thisWord = order.at(i);
			dictions.insert(make_pair(thisWord, i));
		}
		vector<vector<int>> msg(words.size());
		for (int i = 0; i < words.size(); ++i) {
			for (int j = 0; j < words[i].length(); ++j) {
				msg[i].push_back(dictions[words[i].at(j)]);
			}
		}
		for (int i = 0; i < msg.size(); ++i) {
			for (int j = 0; j < msg[i].size(); ++j) {
				cout << msg[i][j] << " ";
			}
			cout << endl;
		}

		bool isBreak = false;
		for (int i = 0; i < msg.size() - 1; ++i) {
			int k = 0, thrd = min(msg[i].size(), msg[i + 1].size());
			for (; k < thrd; ++k) {
				if (msg[i][k] != msg[i + 1][k]) {
					if (msg[i][k] > msg[i + 1][k])
						return false;
					break;
				}
			}
			cout << k << " " << thrd << endl;
			if ((msg[i].size() > msg[i + 1].size()) && (k == (thrd )))
				return false;
			k = 0;
		}
		return true;
	}
};

int main() {
	vector<string> words = { "apple", "app" };
	string order = "abcdefghijklmnopqrstuvwxyz";

	Solution s;
	cout << s.isAlienSorted(words, order) << endl;

	return 0;
}
