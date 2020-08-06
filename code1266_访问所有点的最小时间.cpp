#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi]。请你计算访问所有这些点需要的最小时间（以秒为单位）。
//
//你可以按照下面的规则在平面上移动：
//
//每一秒沿水平或者竖直方向移动一个单位长度，或者跨过对角线（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
//必须按照数组中出现的顺序来访问这些点。


class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		// 理解为计算各坐标两点横坐标与纵坐标的最大值（切比雪夫距离）
		int res = 0;
		for (int i = 0; i < points.size() - 1; ++i) {
			int diffX = abs(points[i][0] - points[i + 1][0]);
			int diffY = abs(points[i][1] - points[i + 1][1]);
			res += diffX < diffY ? diffY : diffX;
			
		}
		return res;
	}
};

int main() {
	vector<vector<int>> points = { {1, 1}, {3, 4}, {-1, 0} };

	Solution s;
	int res = s.minTimeToVisitAllPoints(points);
	cout << res << endl;

	return 0;
}
