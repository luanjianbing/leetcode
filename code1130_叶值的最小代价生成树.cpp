#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
//
//	每个节点都有 0 个或是 2 个子节点。
//	数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。
//		（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
//	每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
//在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。
//这个和的值是一个 32 位整数。

class Solution {
public:
	int mctFromLeafValues(vector<int>& arr) {
		//// 1. 贪心算法维护单调递减栈
		//int res = 0;
		//stack<int> myStk;
		//myStk.push(INT_MAX);
		//for (int e : arr) {
		//	while (e >= myStk.top()) {
		//		int oldTop = myStk.top();
		//		myStk.pop();
		//		res += oldTop * min(e, myStk.top());
		//	}
		//	myStk.push(e);
		//}
		//while (myStk.size() > 2) {
		//	int oldTop = myStk.top();
		//	myStk.pop();
		//	res += oldTop * myStk.top();
		//}
		//return res;

		// 2. 动态规划(有问题)
		int n = arr.size();
		vector<vector<int>> mx(n, vector<int>(n, 0));
		// 求出(i, j)间的元素最大值，保存在mx[i][j]中
		for (int i = 0; i < n; ++i) {
			int tmp = arr[i];
			for (int j = i; j < n; ++j) {
				mx[i][j] = max(tmp, arr[j]);
			}
		}
		// 动态规划，记录(i, j)间的最小值
		vector<vector<int>> dp(n, vector<int>(n, 0));
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				dp[i][j] = INT_MAX;
				for (int k = i; k < j; ++k) {
					dp[i][j] = min(dp[i][j], 
						dp[i][k] + dp[k + 1][j] + mx[i][k] * mx[k + 1][j]);
				}
			}
		}
		return dp[0][n - 1];
	}
};

int main() {
	vector<int> arr = { 6, 2, 4 };

	Solution s;
	cout << s.mctFromLeafValues(arr) << endl;

	return 0;
}