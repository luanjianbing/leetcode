#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <functional>

//����һ����Ʊ���ַ�����ά����[from, to]��
//�������е�������Ա�ֱ��ʾ�ɻ������ͽ���Ļ����ص㣬
//�Ը��г̽������¹滮����
//������Щ��Ʊ������һ���� JFK������Ϲ��ʻ�����������������
//���Ը��г̱���� JFK ��ʼ��

//˵��:
//
//������ڶ�����Ч���г̣�����԰��ַ���Ȼ���򷵻���С���г���ϡ�
//���磬�г�["JFK", "LGA"] ��["JFK", "LGB"] ��Ⱦ͸�С���������ǰ
//���еĻ�������������д��ĸ��ʾ���������룩��
//�ٶ����л�Ʊ���ٴ���һ�ֺ�����г̡�

using namespace std;

class Solution {
public:
	// ���ƣ��ַ����ֵ�������
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
			vec[it[0]].emplace(it[1]);	// Ĭ�ϴ󶥶�
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
	//	// �������Ǳߣ�dfsһ�ε���
	//	// �ҳ����нڵ�
	//	int idx = 1;
	//	unordered_map<string, int> pairs;
	//	unordered_map<int, string> idxMap;
	//	for (int i = 0; i < tickets.size(); ++i) {
	//		for (int j = 0; j < tickets[i].size(); ++j) {
	//			if (pairs.find(tickets[i][j]) == pairs.end()) {
	//				if (tickets[i][j] == "JFK") {// ����JKFΪ���������
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
	//	// ��ͼ
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
	//	//����
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
