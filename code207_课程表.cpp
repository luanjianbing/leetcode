#include <iostream>
#include <vector>

using namespace std;

//你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse - 1 。
//
//在选修某些课程之前需要一些先修课程。 
//例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0, 1]
//
//给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 

class Solution {
public:
	bool dfs(vector<vector<int>> &graph, vector<bool> &hasVisited, int i) {
		for (int j = 0; j < graph[i].size(); ++j) {
			if (!hasVisited[graph[i][j]]) {
				hasVisited[graph[i][j]] = true;
				if (!dfs(graph, hasVisited, graph[i][j]))
					return false;
			}
			else
				return false;
			hasVisited[graph[i][j]] = false;
		}
		return true;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// 1. 按照图来理解（即这个图没有环）
		// 首先构图
		vector<vector<int>> graph(numCourses);
		for (int i = 0; i < prerequisites.size(); ++i) {
			graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		// 遍历这里用dfs
		vector<bool> hasVisited(numCourses, false);
		for (int i = 0; i < numCourses; ++i) {
			if (!hasVisited[i]) {
				hasVisited[i] = false;
				bool res = dfs(graph, hasVisited, i);
				if (!res) return false;
				for (auto v : hasVisited)
					v = false;
			}
		}
		return true;
	}
};

int main() {
	int numCourses = 2;
	vector<vector<int>> prerequisites_1 = { {1, 0}, {0, 1} };
	vector<vector<int>> prerequisites_2 = { { 1, 0 } };
	vector<vector<int>> prerequisites_3 = { { 1, 0 }, { 2, 0} };
	vector<vector<int>> prerequisites_4 = { { 2, 0 },{ 1, 0 },{ 3, 1 },{ 3, 2 }, {1, 3} };
	vector<vector<int>> prerequisites_5 = { { 0, 1 },{ 0, 2 },{ 1, 2 } };

	Solution s;
	bool res1 = s.canFinish(numCourses, prerequisites_1);
	cout << res1 << endl;
	bool res2 = s.canFinish(numCourses, prerequisites_2);
	cout << res2 << endl;
	bool res3 = s.canFinish(3, prerequisites_3);
	cout << res3 << endl;
	bool res4 = s.canFinish(4, prerequisites_4);
	cout << res4 << endl;
	bool res5 = s.canFinish(3, prerequisites_5);
	cout << res5 << endl;

	return 0;
}
