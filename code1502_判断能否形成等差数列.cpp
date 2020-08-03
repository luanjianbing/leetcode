#include <iostream>
#include <vector>

using namespace std;

//给你一个数字数组 arr 。
//
//如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
//
//如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		int vSize = arr.size();
		int max = INT_MIN;
		int min = INT_MAX;
		for (int i = 0; i < vSize; ++i) {
			min = min < arr[i] ? min : arr[i];
			max = max > arr[i] ? max : arr[i];
		}
		int diff = max - min;
		if (diff == 0) return true;	// 出现都是一个数的情况，直接返回true
		// 划分vSize个桶
		vector<bool> hasBuckets(vSize, false);
		vector<int> buckets(vSize, 0);
		int bIdx = 0;
		for (int i = 0; i < vSize; ++i) {
			// 索引预测修改
			bIdx = (vSize - 1) * (arr[i] - min) / diff;
			if (!hasBuckets[bIdx]) {
				hasBuckets[bIdx] = true;
				buckets[bIdx] = arr[i];
			}
			else
				return false;
		}
		for (int i = 0; i < vSize - 2; ++i) {
			if (buckets[i] - buckets[i + 1] != buckets[i + 1] - buckets[i + 2])
				return false;
		}
		return true;

	}
};

int main() {
	vector<int> arr1 = { 3, 5, 1 };
	vector<int> arr2 = { 1, 2, 4 };
	vector<int> arr3 = { 21, 11, 17, -2 };

	Solution s;
	bool res1 = s.canMakeArithmeticProgression(arr1);
	bool res2 = s.canMakeArithmeticProgression(arr2);
	bool res3 = s.canMakeArithmeticProgression(arr3);

	cout << res1 << endl;
	cout << res2 << endl;
	cout << res3 << endl;

	return 0;
}

