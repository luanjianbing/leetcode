#include <iostream>
#include <vector>

using namespace std;

//有 N 个房间，开始时你位于 0 号房间。
//每个房间有不同的号码：0，1，2，...，N - 1，
//并且房间里可能有一些钥匙能使你进入下一个房间。
//
//在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，
//每个钥匙 rooms[i][j] 由[0, 1，...，N - 1] 中的一个整数表示，
//其中 N = rooms.length。 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
//
//最初，除 0 号房间外的其余所有房间都被锁住。
//
//你可以自由地在房间之间来回走动。
//
//如果能进入每个房间返回 true，否则返回 false。

class Solution {
public:
	void dfs(vector<vector<int>> &rooms, vector<bool> &hasVisited, int i) {
		if (hasVisited[i]) return;
		hasVisited[i] = true;
		for (int j = 0; j < rooms[i].size(); ++j) {
			dfs(rooms, hasVisited, rooms[i][j]);
		}
	}

	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		// 理解为有向图判断有没有孤立点
		int nSize = rooms.size();
		vector<bool> hasVisited(nSize, false);

		dfs(rooms, hasVisited, 0);

		for (int i = 0; i < hasVisited.size(); ++i) {
			if (!hasVisited[i]) return false;
		}
		return true;
	}
};

int main() {
	vector<vector<int>> rooms = { {1, 3}, {3, 0, 1}, {2}, {0} };
	vector<vector<int>> rooms1 = { { 1 },{ 2 },{ 3 },{  } };

	Solution s;
	cout << s.canVisitAllRooms(rooms1) << endl;

	return 0;
}
