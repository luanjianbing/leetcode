#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，
//满足 N 是 M 的两倍（即，N = 2 * M）。
//
//更正式地，检查是否存在两个下标 i 和 j 满足：
//
//i != j
//0 <= i, j < arr.length
//arr[i] == 2 * arr[j]


class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		if (arr.empty()) return false;
		unordered_map<int, int> pairs;
		int countZero = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0)countZero++;
			else pairs.insert(pair<int, int>(arr[i], arr[i] * 2));
		}
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] == 0) {
				if (countZero > 1)
					return true;
			}
			else {
				if (pairs.count(pairs[arr[i]]))
					return true;
			}
		}
		return false;
	}
};

int main() {
	vector<int> arr = { 7, 1, 14, 11 };
	Solution s;
	cout << s.checkIfExist(arr) << endl;

	return 0;
}
