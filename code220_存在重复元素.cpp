#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

// 数组是否存在num[i]与num[j]的差的绝对值小于等于k
// 并且i与j的差的绝对值小于等于t

class Solution {
public:
	inline long getBucketId(long value, long bucketWidth)
	{
		return value >= 0 ? value / bucketWidth : (value) / (bucketWidth)-1;
	}

	bool containsNearbyAlmostDuplicate(vector<int> nums, int k, int t){
		//// 1. 线性搜索
		//for (int i = 0; i < nums.size(); ++i) {	// 首先依次遍历
		//	// 保证i - j绝对值在t的范围内
		//	for (int j = abs(i - t); j < i; ++j) {
		//		if (abs(nums[i] - nums[j] <= k))
		//			return true;
		//	}
		//}
		//return false;

		//// 2. 自平衡BST
		//set<int> thisSet;	// 使用点集基础实现为红黑树
		//for (int i = 0; i < nums.size(); ++i) {
		//	auto s = thisSet.lower_bound(nums[i] - t);	// 查找第一个不小于此数的数值，即s >= (nums[i] - t)
		//	if (s != thisSet.end() && *s <= (nums[i] + t))	// s <= nums[i] - t，即找到绝对值
		//		return true;
		//	// 没找到就维护一个长度为k的点集
		//	thisSet.insert(nums[i]);
		//	if (thisSet.size() > k) {	// 删除最先插入的
		//		thisSet.erase(nums[i - k]);
		//	}
		//}
		//return false;

		// 3. 桶
		unordered_map<long, long> bucket;
		int numsSize = nums.size();
		long bucketWidth = (long)t + 1;
		for (int i = 0; i != numsSize; i++) {
			long currentValue = nums[i];
			long bucketId = getBucketId(currentValue, bucketWidth);
			if (bucket.count(bucketId)) {
				//直接命中
				return true;
			}
			if (bucket.count(bucketId + 1) && bucket[bucketId + 1] - currentValue <= t) {
				//后桶命中
				return true;
			}
			if (bucket.count(bucketId - 1) && currentValue - bucket[bucketId - 1] <= t) {
				//前桶命中
				return true;
			}
			//把窗口中最早进入的元素移除掉。
			if (i >= k) {
				bucket.erase(getBucketId(nums[i - k], bucketWidth));
			}
			//当前元素入桶
			bucket[bucketId] = currentValue;
		
		}
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 1 };
	int k = 3, t = 1;

	Solution s;
	bool res = s.containsNearbyAlmostDuplicate(nums, k, t);
	cout << res << endl;

	return 0;
}
