#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//给你一个整数数组 target 和一个数组 initial ，initial 数组与 target  
//数组有同样的维度，且一开始全部为 0 。
//
//请你返回从 initial 得到  target 的最少操作次数，每次操作需遵循以下规则：
//
//在 initial 中选择 任意 子数组，并将子数组中每个元素增加 1 。
//答案保证在 32 位有符号整数以内。


class Solution {
public:
	// 1. 超时
	// 以0来划分看看这个数组共有几个存在有值的区间
	int findThrdZero(vector<int> &target) {
		int sizeT = target.size();
		int notZeroNum = 0;
		if (target[0] == 0)	// 起始为0
		{
			for (int i = 0; i < sizeT - 1; ++i) {
				if (target[i] == 0 && target[i + 1] != 0)
					notZeroNum++;
			}
		}
		else {
			notZeroNum++;
			for (int i = 0; i < sizeT - 1; ++i) {
				if (target[i] == 0 && target[i + 1] != 0)
					notZeroNum++;
			}
		}
		return notZeroNum;
	}

	int minNumberOperations(vector<int>& target) {
		int ans = 0;
		int sizeT = target.size();
		int minVal = INT_MAX;
		int maxVal = INT_MIN;
		int maxIdx = 0;
		for (int i = 0; i < sizeT; ++i) {
			minVal = target[i] < minVal ? target[i] : minVal;
			if (target[i] > maxVal) {
				maxIdx = i;
				maxVal = target[i];
			}
		}
		for (int i = 0; i < sizeT; ++i)
			target[i] -= minVal;	// 保证都大于0，最后结果需要+1
		if (minVal != 0) ans += abs(minVal);
		// 然后不停将所有元素减1，按0分割有几个区间就加几，直到都为0
		minVal = INT_MAX;
		while (target[maxIdx] != 0) {
			
			for (int i = 0; i < sizeT; ++i) {
				if (target[i] > 0)
					minVal = target[i] < minVal ? target[i] : minVal;
			}
			ans += findThrdZero(target) * minVal;
			for (int i = 0; i < sizeT; ++i) {
				if (target[i] > 0)
					target[i] -= minVal;
			}
			//// 一个个+超时
			//for (int i = 0; i < sizeT; ++i) {
			//	if (target[i] > 0)
			//		target[i] -= 1;
			//}
			
		}
		return ans;

		// 2.使用差分数组的想法
		int n = target.size();
		int ans = target[0];
		for (int i = 1; i < n; ++i)
			ans += max(target[i] - target[i - 1], 0);
		return ans;
	}

	
};

int main() {
	Solution s;

	vector<int> target_1 = { 1, 2, 3, 2, 1 };
	vector<int> target_2 = { 3, 1, 1, 2 };
	vector<int> target_3 = { 3, 1, 5, 4, 2 };
	vector<int> target_4 = { 3, 4, 2, 5, 6 };

	int res1 = s.minNumberOperations(target_1);
	cout << res1 << endl;
	int res2 = s.minNumberOperations(target_2);
	cout << res2 << endl;
	int res3 = s.minNumberOperations(target_3);
	cout << res3 << endl;
	int res4 = s.minNumberOperations(target_4);
	cout << res4 << endl;

	return 0;
}
