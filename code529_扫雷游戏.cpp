﻿#include <iostream>
#include <vector>

using namespace std;

//我们一起来玩扫雷游戏！
//
//给定一个代表游戏板的二维字符矩阵。 
//'M' 代表一个未挖出的地雷，
//'E' 代表一个未挖出的空方块，
//'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
//数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
//
//现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），
//根据以下规则，返回相应位置被点击后对应的面板：
//
//如果一个地雷（'M'）被挖出，游戏就结束了 - 把它改为 'X'。
//如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
//如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
//如果在此次点击中，若无更多方块可被揭露，则返回面板。


class Solution {
public:
	int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
	int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };

	void dfs(vector<vector<char>>& board, int x, int y) {
		int cnt = 0;
		for (int i = 0; i < 8; ++i) {
			int tx = x + dir_x[i];
			int ty = y + dir_y[i];
			if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
				continue;
			}
			// 不用判断 M，因为如果有 M 的话游戏已经结束了
			cnt += board[tx][ty] == 'M';
		}
		if (cnt > 0) {
			// 规则 3
			board[x][y] = cnt + '0';
		}
		else {
			// 规则 2
			board[x][y] = 'B';
			for (int i = 0; i < 8; ++i) {
				int tx = x + dir_x[i];
				int ty = y + dir_y[i];
				// 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
				if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
					continue;
				}
				dfs(board, tx, ty);
			}
		}
	}

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		int x = click[0], y = click[1];
		if (board[x][y] == 'M') {
			// 规则 1
			board[x][y] = 'X';
		}
		else {
			dfs(board, x, y);
		}
		return board;
	}
};

int main() {

	return 0;
}
