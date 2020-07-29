#include <iostream>
#include <vector>
#include <queue>
//
//我们得到了一副藏宝图，藏宝图显示，在一个迷宫中存在着未被世人发现的宝藏。
//
//迷宫是一个二维矩阵，用一个字符串数组表示。它标识了唯一的入口（用 'S' 表示），和唯一的宝藏地点（用 'T' 表示）。但是，宝藏被一些隐蔽的机关保护了起来。在地图上有若干个机关点（用 'M' 表示），只有所有机关均被触发，才可以拿到宝藏。
//
//要保持机关的触发，需要把一个重石放在上面。迷宫中有若干个石堆（用 'O' 表示），每个石堆都有无限个足够触发机关的重石。但是由于石头太重，我们一次只能搬一个石头到指定地点。
//
//迷宫中同样有一些墙壁（用 '#' 表示），我们不能走入墙壁。剩余的都是可随意通行的点（用 '.' 表示）。石堆、机关、起点和终点（无论是否能拿到宝藏）也是可以通行的。
//
//我们每步可以选择向上 / 向下 / 向左 / 向右移动一格，并且不能移出迷宫。搬起石头和放下石头不算步数。那么，从起点开始，我们最少需要多少步才能最后拿到宝藏呢？如果无法拿到宝藏，返回 - 1 。


using namespace std;

class Solution {
public:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int n, m;	// 原maze大小row/col

	bool inBound(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	vector<vector<int>> bfs(int x, int y, vector<string>& maze) {
		vector<vector<int>> ret(n, vector<int>(m, -1));	// 初始化原maze大小vector
		ret[x][y] = 0;	// 起始点设为0
		queue<pair<int, int>> Q;
		Q.push({ x, y });	// 首先压入起始点
		while (!Q.empty()) {
			auto p = Q.front();
			Q.pop();
			int x = p.first, y = p.second;	// 得到队列前端的坐标
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];	// 这一步其实也就是找到当前点的周围四个点，bfs
				if (inBound(nx, ny) && maze[nx][ny] != '#' && ret[nx][ny] == -1) {
					ret[nx][ny] = ret[x][y] + 1;	// 计算该点到各个非墙点的步数（距离）
					Q.push({ nx, ny });
				}
			}
		}
		return ret;
	}

	int minimalSteps(vector<string>& maze) {
		n = maze.size(), m = maze[0].size();	// n = 行数, m = 列数
		// 机关 & 石头
		vector<pair<int, int>> buttons, stones;
		// 起点 & 终点
		int sx, sy, tx, ty;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'M') {		// 找到所有机关位置
					buttons.push_back({ i, j });
				}
				if (maze[i][j] == 'O') {		// 找到所有石头位置
					stones.push_back({ i, j });
				}
				if (maze[i][j] == 'S') {		// 找到起始点位置
					sx = i, sy = j;			// <startx, starty>
				}
				if (maze[i][j] == 'T') {		// 找到终点位置
					tx = i, ty = j;			// <terminalx, terminaly>
				}
			}
		}
		int nb = buttons.size();	// 计算得到机关总数
		int ns = stones.size();		// 计算得到石头总数
		vector<vector<int>> start_dist = bfs(sx, sy, maze);	// 这一步得到起始点到各非墙点的步数，采用bfs

		cout << "start_dist起始点到各能到达点距离" << endl;
		for (int i = 0; i < start_dist.size(); i++) {
			for (int j = 0; j < start_dist[i].size(); ++j) {
				cout << start_dist[i][j] << " ";
			}
			cout << endl;
		}

		// 边界情况：没有机关
		if (nb == 0) {
			return start_dist[tx][ty];	// 没有机关直接走去终点
		}
		// 从某个机关到其他机关 / 起点与终点的最短距离。
		vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
		// 中间结果
		vector<vector<vector<int>>> dd(nb);
		for (int i = 0; i < nb; i++) {
			vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
			dd[i] = d;	// 某个机关到各非墙点的距离信息
			// 从某个点到终点不需要拿石头
			dist[i][nb + 1] = d[tx][ty];	// 某个机关到终点的距离
		}

		cout << "dist机关点到终点的距离" << endl;
		for (int i = 0; i < dist.size(); i++) {
			for (int j = 0; j < dist[i].size(); ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < nb; i++) {	// 遍历各个机关点
			int tmp = -1;
			for (int k = 0; k < ns; k++) {
				int mid_x = stones[k].first, mid_y = stones[k].second;
				if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {	// 该机关点可以到达的石头点 以及 该石头点可以由起点到达
					if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
						tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];	
					}
				}
			}
			dist[i][nb] = tmp;// 这一步之后得到从起点到石头点+从石头点到该机关点最小的距离
			for (int j = i + 1; j < nb; j++) {
				int mn = -1;
				for (int k = 0; k < ns; k++) {
					int mid_x = stones[k].first, mid_y = stones[k].second;
					if (dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
						if (mn == -1 || mn > dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]) {
							mn = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];	
						}
					}
				}
				dist[i][j] = mn;	// 这一步之后找到该机关点到下一个机关点最小距离
				dist[j][i] = mn;
			}
		}

		cout << "dist机关点与机关点之间拿完石头最小路径和起始点拿完石头到机关点最小路径" << endl;
		for (int i = 0; i < dist.size(); i++) {
			for (int j = 0; j < dist[i].size(); ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}

		// 无法达成的情形
		for (int i = 0; i < nb; i++) {	// 这说明有机关无法从起点到达或者有机关无法到达终点，无法满足所有机关打开条件
			if (dist[i][nb] == -1 || dist[i][nb + 1] == -1) return -1;
		}

		// dp 数组， -1 代表没有遍历到
		vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
		for (int i = 0; i < nb; i++) {
			dp[1 << i][i] = dist[i][nb];	// 起点信息
		}

		cout << "dp" << endl;
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		// 起始点->机关+机关->下一个机关->。。。
		// 由于更新的状态都比未更新的大，所以直接从小到大遍历即可
		for (int mask = 1; mask < (1 << nb); mask++) {
			for (int i = 0; i < nb; i++) {
				// 当前 dp 是合法的
				if (mask & (1 << i)) {
					for (int j = 0; j < nb; j++) {
						// j 不在 mask 里
						if (!(mask & (1 << j))) {
							int next = mask | (1 << j);
							if (next == 7) cout << "next = 7 : "<< mask << " " << i << " "<< j << endl;
							else cout << "next = " << next << " " << mask << " " << i << " " << j << endl;
							if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
								dp[next][j] = dp[mask][i] + dist[i][j];	// 起点到第一个机关+机关到下一个机关
							}
						}
					}
				}
			}
		}

		cout << "dp" << endl;
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		// 起始点->机关+机关->下一个机关->。。。+最后一个机关->终点
		int ret = -1;
		int final_mask = (1 << nb) - 1;
		for (int i = 0; i < nb; i++) {
			if (ret == -1 || ret > dp[final_mask][i] + dist[i][nb + 1]) {
				ret = dp[final_mask][i] + dist[i][nb + 1];
			}
		}

		return ret;
	}
};

int main() {
	vector<string> maze = { "S#OM", "M...", "M.T." };	// 这种字符一维数组也可以用vect[i][j]访问
	Solution s;
	int res = s.minimalSteps(maze);
	cout << res << endl;
	return 0;
}

