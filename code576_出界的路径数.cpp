#include <iostream>
#include <vector>

using namespace std;

//给定一个 m × n 的网格和一个球。球的起始坐标为 (i, j) ，
//你可以将球移到相邻的单元格内，
//或者往上、下、左、右四个方向上移动使球穿过网格边界。
//但是，你最多可以移动 N 次。
//找出可以将球移出边界的路径数量。
//答案可能非常大，返回 结果 mod 109 + 7 的值。

class Solution {
public:
	//// 1、暴力递归（超出时间限制）
	//int floodFill(vector<vector<int>> &grid, int i, int j, int step, int N) {
	//	if (step > N)
	//		return 0;
	//	if (grid[i][j] == 0)
	//		return 1;
	//	return floodFill(grid, i + 1, j, step + 1, N)+
	//	floodFill(grid, i, j + 1, step + 1, N)+
	//	floodFill(grid, i - 1, j, step + 1, N)+
	//	floodFill(grid, i, j - 1, step + 1, N);
	//}

	//int findPaths(int m, int n, int N, int i, int j) {
	//	vector<vector<int>> grid(m + 2, vector<int>(n + 2, 0));
	//	for (int x = 1; x <= m; ++x)
	//		for (int y = 1; y <= n; ++y)
	//			grid[x][y] = 1;

	//	for (int x = 0; x < grid.size(); ++x) {
	//		for (int y = 0; y < grid[x].size(); ++y){
	//			cout << grid[x][y] << " ";
	//		}
	//		cout << endl;
	//	}
	//	return floodFill(grid, i + 1, j + 1, 0, N) % 1000000007;
	//}

	// 2. 动态规划
	int findPaths(int m, int n, int N, int i, int j) {
		int MOD = 1000000007;
		if (N == 0) { return 0; }

		vector<vector<vector<unsigned long long int>>> dp(m + 2, vector<vector<unsigned long long int>>(n + 2, vector<unsigned long long int>(N + 1, 0)));
		// 周围变为1
		for (int i = 0; i <= m + 1; i++) {
			dp[i][0][0] = 1;
			dp[i][n + 1][0] = 1;
		}
		for (int i = 0; i <= n + 1; i++) {
			dp[0][i][0] = 1;
			dp[m + 1][i][0] = 1;
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= n; j++) {
					dp[i][j][k] = (dp[i - 1][j][k - 1] + dp[i + 1][j][k - 1] + \
						dp[i][j - 1][k - 1] + dp[i][j + 1][k - 1]) % MOD;
				}
			}
		}
		int sum = 0;
		for (int k = 1; k <= N; k++) {
			sum = (sum + dp[i + 1][j + 1][k]) % MOD;
		}
		return sum;
	}
};

int main() {
	// 球起始坐标(i, j)
	// 网格大小(m, n)
	// 最多移动N次，将球移出网格外

	int i = 1, j = 5;
	int m = 8, n = 7;
	int N = 16;

	Solution s;
	cout << s.findPaths(m, n, N, i, j) << endl;

	return 0;
}
