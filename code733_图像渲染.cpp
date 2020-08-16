#include <iostream>
#include <vector>

using namespace std;

//有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
//
//给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
//
//为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
//接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，
//重复该过程。将所有有记录的像素点的颜色值改为新的颜色值。
//
//最后返回经过上色渲染后的图像


class Solution {
public:
	void ff(vector<vector<int>>& image, int x, int y, int color, int initialColor, int xSize, int ySize) {
		image[x][y] = color;
		if (x > 0 && image[x - 1][y] == initialColor) ff(image, x - 1, y, color, initialColor, xSize, ySize);
		if (y > 0 && image[x][y - 1] == initialColor) ff(image, x, y - 1, color, initialColor, xSize, ySize);
		if (x < xSize && image[x + 1][y] == initialColor) ff(image, x + 1, y, color, initialColor, xSize, ySize);
		if (y < ySize && image[x][y + 1] == initialColor) ff(image, x, y + 1, color, initialColor, xSize, ySize);
	}

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		if (image.empty()) return image;
		int xSize = image.size() - 1;
		int ySize = image[0].size() - 1;
		ff(image, sr, sc, -1, image[sr][sc], xSize, ySize);	// 使用-1标记不同
		// 遍历数组 -1 为newcolor
		for (int i = 0; i < image.size(); ++i) {
			for (int j = 0; j < image[i].size(); ++j)
				image[i][j] = image[i][j] == -1 ? newColor : image[i][j];
		}
		return image;
	}
};

int main() {
	vector<vector<int>> image = {	{0, 0, 0 },
									{0, 1, 1 } };
	int sr = 1, sc = 1, newColor = 1;

	Solution s;
	vector<vector<int>> res = s.floodFill(image, sr, sc, newColor);

	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}
