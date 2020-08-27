#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <functional>

//给定一个机票的字符串二维数组[from, to]，
//子数组中的两个成员分别表示飞机出发和降落的机场地点，
//对该行程进行重新规划排序。
//所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，
//所以该行程必须从 JFK 开始。

//说明:
//
//如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。
//例如，行程["JFK", "LGA"] 与["JFK", "LGB"] 相比就更小，排序更靠前
//所有的机场都用三个大写字母表示（机场代码）。
//假定所有机票至少存在一种合理的行程。

using namespace std;

class Solution {
public:
	// 大顶推，字符按字典序排列
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> vec;

	vector<string> stk;

	void dfs(const string& curr) {
		while (vec.count(curr) && vec[curr].size() > 0) {
			string tmp = vec[curr].top();
			vec[curr].pop();
			dfs(move(tmp));
		}
		stk.emplace_back(curr);
	}

	vector<string> findItinerary(vector<vector<string>>& tickets) {
		for (auto& it : tickets) {
			vec[it[0]].emplace(it[1]);	// 默认大顶堆
		}
		dfs("JFK");

		reverse(stk.begin(), stk.end());
		return stk;
	}
	//void dfs(vector<vector<int>> &graph, vector<bool> &hasVisited, int i, vector<int> &ans) {
	//	
	//	if (hasVisited[i])
	//		return;
	//	//cout << i << endl;
	//	hasVisited[i] = true;
	//	
	//	for (int j = 0; j < graph[i].size(); ++j) {
	//		ans.push_back(graph[i][j]);
	//		dfs(graph, hasVisited, graph[i][j], ans);
	//	}
	//}

	//vector<string> findItinerary(vector<vector<string>>& tickets) {
	//	// 给出的是边，dfs一次到底
	//	// 找出所有节点
	//	int idx = 1;
	//	unordered_map<string, int> pairs;
	//	unordered_map<int, string> idxMap;
	//	for (int i = 0; i < tickets.size(); ++i) {
	//		for (int j = 0; j < tickets[i].size(); ++j) {
	//			if (pairs.find(tickets[i][j]) == pairs.end()) {
	//				if (tickets[i][j] == "JFK") {// 设置JKF为遍历的起点
	//					pairs.insert(make_pair(tickets[i][j], 0));
	//					idxMap.insert(make_pair(0, tickets[i][j]));
	//				}
	//				else {
	//					pairs.insert(make_pair(tickets[i][j], idx));
	//					idxMap.insert(make_pair(idx, tickets[i][j]));
	//					idx++;
	//				}
	//				
	//			}
	//		}
	//	}
	//	//for (unordered_map<string, int>::const_iterator iter = pairs.begin(); iter != pairs.end(); iter++) {
	//	//	cout << iter->first << " " << iter->second << endl;
	//	//}
	//	// 构图
	//	vector<vector<int>> graph(pairs.size());
	//	for (int i = 0; i < tickets.size(); ++i)
	//		graph[pairs[tickets[i][0]]].push_back(pairs[tickets[i][1]]);
	//	//for (int i = 0; i < graph.size(); ++i) {
	//	//	cout << i << ": ";
	//	//	for (int j = 0; j < graph[i].size(); ++j) {
	//	//		cout << graph[i][j] << " ";
	//	//	}
	//	//	cout << endl;
	//	//}
	//	//遍历
	//	vector<int> ansIdx;
	//	vector<string> ans;
	//	vector<bool> hasVisited(pairs.size(), false);
	//	ansIdx.push_back(0);
	//	dfs(graph, hasVisited, 0, ansIdx);
	//	for (int i = 0; i < ansIdx.size(); ++i) {
	//		cout << ansIdx[i] << endl;
	//	}
	//	for (int i = 0; i < ansIdx.size(); i++) {
	//		ans.push_back(idxMap[ansIdx[i]]);
	//	}
	//	return ans;
	//}
};

int main() {
	vector<vector<string>> tickets = { {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"},
	{"ATL", "JFK"}, {"ATL", "SFO"} };

	Solution s;
	vector<string> res = s.findItinerary(tickets);
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << " ";

	return 0;
}
