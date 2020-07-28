#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
//如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
//所谓的朋友圈，是指所有朋友的集合。
//
//给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
//如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
//你必须输出所有学生中的已知的朋友圈总数。

class Solution {
public:
	//// 1. dfs
	//void dfs(vector<vector<int>> &M, vector<bool> &hasVisited, int i) {
	//	for (int j = 0; j < M.size(); ++j) {
	//		if (M[i][j] == 1 && hasVisited[j] == false) {
	//			hasVisited[j] = true;
	//			dfs(M, hasVisited, j);
	//		}
	//	}
	//}
	//// 1. dfs
	//int findCircleNum(vector<vector<int>>& M) {
	//	vector<bool> hasVisited(M.size(), false);
	//	int count = 0;
	//	for (int i = 0; i < M.size(); ++i) {
	//		if (!hasVisited[i]) {
	//			dfs(M, hasVisited, i);
	//			count++;
	//		}
	//	}
	//	return count;
	//}

	//// 2. bfs
	//int findCircleNum(vector<vector<int>>& M) {
	//	queue<int> thisQueue;
	//	vector<bool> hasVisited(M.size(), false);
	//	int count = 0;
	//	for (int i = 0; i < M.size(); ++i) {
	//		if (!hasVisited[i]) {
	//			thisQueue.push(i);
	//			while (!thisQueue.empty()) {
	//				int s = thisQueue.front();
	//				hasVisited[s] = true;
	//				thisQueue.pop();
	//				for (int j = 0; j < M.size(); ++j) {
	//					if (M[s][j] == 1 && !hasVisited[j])
	//						thisQueue.push(j);
	//				}
	//			}
	//			count++;
	//		}
	//	}
	//	return count;
	//}

	// 3. 并查集
	int find(vector<int> &parent, int i) {
		if (parent[i] == -1)
			return i;
		return find(parent, parent[i]);
	}

	void treeUnion(vector<int> &parent, int x, int y) {
		int xset = this->find(parent, x);
		int yset = this->find(parent, y);
		if (xset != yset)
			parent[xset] = yset;
	}

	int findCircleNum(vector<vector<int>>& M) {
		vector<int> parent(M.size(), -1);
		for (int i = 0; i < M.size(); ++i) {
			for (int j = 0; j < M.size(); j++){
				if (M[i][j] == 1 && i!= j)
					this->treeUnion(parent, i, j);
			}
		}
		int count = 0;
		for (int i = 0; i < parent.size(); ++i) {
			if (parent[i] == -1)
				count++;
		}
		return count;
	}
};

int main() {
	vector<vector<int>> matrix = { {1, 1, 0}, {1, 1, 0}, {0, 0, 1} };
	Solution s;
	int res = s.findCircleNum(matrix);
	cout << res << endl;

	return 0;
}
