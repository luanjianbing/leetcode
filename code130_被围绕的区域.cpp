#include <iostream>
#include <vector>

using namespace std;

//给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
//
//找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

class Solution {
public:
	void floodFill(int x, int y, int &xSize, int &ySize, vector<vector<char>>& board) {
		board[x][y] = '#';
		if (x > 0 && board[x - 1][y] == 'O')floodFill(x - 1, y, xSize, ySize, board);
		if (y > 0 && board[x][y - 1] == 'O')floodFill(x, y - 1, xSize, ySize, board);
		if (x < xSize -1 && board[x + 1][y] == 'O')floodFill(x + 1, y, xSize, ySize, board);
		if (y < ySize -1 && board[x][y + 1] == 'O')floodFill(x, y + 1, xSize, ySize, board);
	}

	void solve(vector<vector<char>>& board) {
		if (board.size() < 3) return;
		int xSize = board.size();
		int ySize = board[0].size();
		for (int i = 0; i < ySize; ++i) {
			if (board[0][i] == 'O') floodFill(0, i, xSize, ySize, board);
			if (board[xSize - 1][i] == 'O') floodFill(xSize - 1, i, xSize, ySize, board);
		}

		for (int i = 0; i < xSize; ++i) {
			if (board[i][0] == 'O')  floodFill(i, 0, xSize, ySize, board);
			if (board[i][ySize - 1] == 'O')  floodFill(i, ySize - 1, xSize, ySize, board);
		}
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == '#') board[i][j] = 'O';
				else if (board[i][j] == 'O') board[i][j] = 'X';
			}
		}
	}
};

int main() {
	vector<vector<char>> board = {	{'X', 'X', 'X', 'X'},
									{'X', 'O', 'O', 'X'},
									{'X', 'X', 'O', 'X'},
									{'X', 'O', 'X', 'X'}  };
	Solution s;
	s.solve(board);

	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[i].size(); ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}

	return 0;
}
