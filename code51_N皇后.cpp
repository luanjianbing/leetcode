#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

//皇后的走法是：可以横直斜走，格数不限。
//因此要求皇后彼此之间不能相互攻击，
//等价于要求任何两个皇后都不能在同一行、同一列以及同一条斜线上

//列的表示法很直观，一共有 N 列，每一列的下标范围从 0 到 N−1，使用列的下标即可明确表示每一列
//方向一的斜线为从左上到右下方向，同一条斜线上的每个位置满足行下标与列下标之差相等
//方向二的斜线为从右上到左下方向，同一条斜线上的每个位置满足行下标与列下标之和相等

class Solution {
public:
	// 1. 基于集合的回溯算法
	vector<string> generateBoard(vector<int> &queens, int n) {
		auto board = vector<string>();
		for (int i = 0; i < n; ++i) {
			string row = string(n, '.');
			row[queens[i]] = 'Q';
			board.push_back(row);
		}
		return board;
	}

	
	void backtrack(vector<vector<string>> &solutions, vector<int> &queens, int n, int row,
		unordered_set<int> &columns, unordered_set<int> &diagonals1, unordered_set<int> &diagonals2) {
		if (row == n) {
			vector<string> board = generateBoard(queens, n);
			solutions.push_back(board);
		}
		else {
			for (int i = 0; i < n; ++i) {	// 遍历列
				if (columns.find(i) != columns.end()) {
					continue;
				}
				int diagonal1 = row - i;
				if (diagonals1.find(diagonal1) != diagonals1.end()) {
					continue;
				}
				int diagonal2 = row + i;
				if (diagonals2.find(diagonal2) != diagonals2.end()) {
					continue;
				}
				queens[row] = i;
				columns.insert(i);
				diagonals1.insert(diagonal1);
				diagonals2.insert(diagonal2);
				backtrack(solutions, queens, n, row + 1, columns, diagonals1, diagonals2);
				queens[row] = -1;	// 达不到最后一层， 则返回初始化状态
				columns.erase(i);
				diagonals1.erase(diagonal1);
				diagonals2.erase(diagonal2);
			}
		}
	}

	vector<vector<string>> solveNQueens(int n) {
		auto solutions = vector<vector<string>>();
		auto queens = vector<int>(n, -1);
		auto columns = unordered_set<int>();
		auto diagonals1 = unordered_set<int>();
		auto diagonals2 = unordered_set<int>();
		backtrack(solutions, queens, n, 0, columns, diagonals1, diagonals2);
		return solutions;
	}

	//// 2. 基于位运算回溯
	//vector<string> generareBoard(vector<int> &queens, int n) {
	//	auto board = vector<string>();
	//	for (int i = 0; i < n; ++i) {
	//		string row = string(n, '.');
	//		row[queens[i]] = 'Q';
	//		board.push_back(row);
	//	}
	//	return board;
	//}

	//void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, 
	//	int columns, int diagonals1, int diagonals2) {
	//	if (row == n) {
	//		auto board = generareBoard(queens, n);
	//		solutions.push_back(board);
	//	}
	//	else {
	//		int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
	//		while (availablePositions != 0) {
	//			int position = availablePositions & (-availablePositions);
	//			availablePositions = availablePositions & (availablePositions - 1);
	//			int column = __builtin_ctz(position);
	//			queens[row] = column;
	//			solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
	//			queens[row] = -1;
	//		}
	//	}
	//}

	//vector<vector<string>> solveNQueens(int n) {
	//	auto solutions = vector<vector<string>>();
	//	auto queens = vector<int>(n, -1);
	//	solve(solutions, queens, n, 0, 0, 0, 0);
	//	return solutions;
	//}

};

int main() {
	int n = 4;

	Solution s;
	vector<vector<string>> res = s.solveNQueens(n);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
