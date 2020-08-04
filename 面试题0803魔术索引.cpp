#include <iostream>
#include <vector>

using namespace std;

//魔术索引。 在数组A[0...n - 1]中，有所谓的魔术索引，满足条件A[i] = i。
//给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，
//如果没有，则返回 - 1。若有多个魔术索引，返回索引值最小的一个。



class Solution {
public:
	int getAnswer(vector<int> nums, int left, int right) {
		if (left > right)	// 找不到推出条件
			return -1;
		int mid = (right - left) / 2 + left;
		int leftAnswer = getAnswer(nums, left, mid - 1);
		if (leftAnswer != -1) {	// 说明找到了一个
			return leftAnswer;
		}
		else if (nums[mid] == mid) {
			return mid;
		}
		return getAnswer(nums, mid + 1, right);
	}

	int findMagicIndex(vector<int>& nums) {
		//// 1. 线性搜索
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (i == nums[i]) return i;
		//}
		//return -1;

		// 2. 二分剪枝（某些情况下有不错的表现）
		// 如果当前中点是魔术索引，则只考虑左边部分，如果不是则两边都得考虑
		return getAnswer(nums, 0, (int)nums.size() - 1);
	}
};

int main()
{
	vector<int> nums = {0, 2, 3, 4, 5};
	Solution s;
	int res = s.findMagicIndex(nums);
	cout << res << endl;

	return 0;
}