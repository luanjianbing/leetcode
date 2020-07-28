#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

// �����Ƿ����num[i]��num[j]�Ĳ�ľ���ֵС�ڵ���k
// ����i��j�Ĳ�ľ���ֵС�ڵ���t

class Solution {
public:
	inline long getBucketId(long value, long bucketWidth)
	{
		return value >= 0 ? value / bucketWidth : (value) / (bucketWidth)-1;
	}

	bool containsNearbyAlmostDuplicate(vector<int> nums, int k, int t){
		//// 1. ��������
		//for (int i = 0; i < nums.size(); ++i) {	// �������α���
		//	// ��֤i - j����ֵ��t�ķ�Χ��
		//	for (int j = abs(i - t); j < i; ++j) {
		//		if (abs(nums[i] - nums[j] <= k))
		//			return true;
		//	}
		//}
		//return false;

		//// 2. ��ƽ��BST
		//set<int> thisSet;	// ʹ�õ㼯����ʵ��Ϊ�����
		//for (int i = 0; i < nums.size(); ++i) {
		//	auto s = thisSet.lower_bound(nums[i] - t);	// ���ҵ�һ����С�ڴ�������ֵ����s >= (nums[i] - t)
		//	if (s != thisSet.end() && *s <= (nums[i] + t))	// s <= nums[i] - t�����ҵ�����ֵ
		//		return true;
		//	// û�ҵ���ά��һ������Ϊk�ĵ㼯
		//	thisSet.insert(nums[i]);
		//	if (thisSet.size() > k) {	// ɾ�����Ȳ����
		//		thisSet.erase(nums[i - k]);
		//	}
		//}
		//return false;

		// 3. Ͱ
		unordered_map<long, long> bucket;
		int numsSize = nums.size();
		long bucketWidth = (long)t + 1;
		for (int i = 0; i != numsSize; i++) {
			long currentValue = nums[i];
			long bucketId = getBucketId(currentValue, bucketWidth);
			if (bucket.count(bucketId)) {
				//ֱ������
				return true;
			}
			if (bucket.count(bucketId + 1) && bucket[bucketId + 1] - currentValue <= t) {
				//��Ͱ����
				return true;
			}
			if (bucket.count(bucketId - 1) && currentValue - bucket[bucketId - 1] <= t) {
				//ǰͰ����
				return true;
			}
			//�Ѵ�������������Ԫ���Ƴ�����
			if (i >= k) {
				bucket.erase(getBucketId(nums[i - k], bucketWidth));
			}
			//��ǰԪ����Ͱ
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
