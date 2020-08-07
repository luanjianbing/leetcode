#include <iostream>
#include <vector>

using namespace std;

//����һ��Ψһ�ĵ��ʣ� �ҳ����в�ͬ ��������(i, j)��
//ʹ���б��е��������ʣ� words[i] + words[j] ����ƴ�ӳɻ��Ĵ���

//����: ["abcd", "dcba", "lls", "s", "sssll"]
//��� : [[0, 1], [1, 0], [3, 2], [2, 4]]
//���� : ��ƴ�ӳɵĻ��Ĵ�Ϊ["dcbaabcd", "abcddcba", "slls", "llssssll"]

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
				tree.emplace_back();	// û�в����Ļ�Ĭ�ϲ���һ���������Ϊ0�Ľڵ�
				tree[add].ch[idx] = tree.size() - 1;	// ������һ���Ľڵ�ָ��
			}
			add = tree[add].ch[idx];
		}
		tree[add].flag = id;	// �ַ�����Ϻ���±�־λ��ʾ���
	}

	// �жϸ��ַ����Ƿ����
	bool isPalindrome(string& s, int left, int right) {
		int len = right - left + 1;
		for (int i = 0; i < len / 2; i++) {
			if (s[left + i] != s[right - i]) {	// ���м��������ж�
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
		tree.emplace_back(Node());	// ѹ��һ�����ڵ�
		int n = words.size();	// �ַ����ܸ���
		for (int i = 0; i < n; i++) {
			insert(words[i], i);
		}

		vector<vector<int>> ret;
		for (int i = 0; i < n; i++) {
			int m = words[i].size();
			for (int j = 0; j <= m; j++) {
				// ��Ϊ��������ж�
				if (isPalindrome(words[i], j, m - 1)) {	// �ұ�
					int left_id = findWord(words[i], 0, j - 1);	// �ж��ֵ����д治���ڸ��ַ�
					if (left_id != -1 && left_id != i) {	
						ret.push_back({ i, left_id });
					}
				}
				if (j && isPalindrome(words[i], 0, j - 1)) {	// ���
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
