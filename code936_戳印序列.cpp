#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//你想要用小写字母组成一个目标字符串 target。 
//
//开始的时候，序列由 target.length 个 '?' 记号组成。
//而你有一个小写字母印章 stamp。
//
//在每个回合，你可以将印章放在序列上，并将序列中的每个字母替换为印章上的相应字母。
//你最多可以进行 10 * target.length  个回合。
//
//举个例子，如果初始序列为 "?????"，而你的印章 stamp 是 "abc"，
//那么在第一回合，你可以得到 "abc??"、"?abc?"、"??abc"。
//（请注意，印章必须完全包含在序列的边界内才能盖下去。）
//
//如果可以印出序列，那么返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成。
//如果不能印出序列，就返回一个空数组。
//
//例如，如果序列是 "ababc"，印章是 "abc"，
//那么我们就可以返回与操作 "?????" -> "abc??" -> "ababc" 相对应的答案[0, 2]；
//
//另外，如果可以印出序列，那么需要保证可以在 10 * target.length 个回合内完成。
//任何超过此数字的答案将不被接受。


// 解答有问题
class Solution {
private:
	struct Node
	{
		unordered_set<int> made;
		unordered_set<int> todo;
		Node(unordered_set<int> made, unordered_set<int>todo)
			: made(made), todo(todo) {};
	};
public:
	vector<int> movesToStamp(string stamp, string target) {
		int M = stamp.size(), N = target.size();
		queue<int> myQueue;
		vector<bool> done(N, false);
		stack<int> ans;
		vector<Node> A;

		for (int i = 0; i <= N - M; ++i) {
			unordered_set<int> made;
			unordered_set<int> todo;
			for (int j = 0; j < M; ++j) {
				if (target.at(i + j) == stamp.at(j))
					made.insert(i + j);
				else
					todo.insert(i + j);
			}

			A.push_back(Node(made, todo));

			if (todo.empty()) {
				ans.push(i);
				for (int j = i; j < i + M; ++j) {
					if (!done[j]) {
						myQueue.push(j);
						done[j] = true;
					}
				}
			}

		}

		while (!myQueue.empty()) {
			int i = myQueue.front();
			myQueue.pop();

			for (int j = max(0, i - M + 1); j < min(N - M, i); ++j) {
				if (A[j].todo.count(i)) {
					A[j].todo.erase(i);
					if (A[j].todo.empty()) {
						ans.push(j);
						for (int m : A[j].made) {
							if (!done[m]) {
								myQueue.push(m);
								done[m] = true;
							}
						}
					}
				}
			}
		}

		for (bool b : done) {
			if (!b) {
				vector<int> r(1, 0);
				return r;
			}
		}

		vector<int> ret(ans.size(), 0);
		int t = 0;
		while (!ans.empty()) {
			ret[t++] = ans.top();
			ans.pop();
		}
		return ret;
	}
};

int main() {
	string stamp = "abca";
	string target = "aabcaca";

	Solution s;
	vector<int> res = s.movesToStamp(stamp, target);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	return 0;
}
