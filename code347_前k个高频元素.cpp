#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

class Solution {
public:
	static bool cmp(pair<int, int>& m, pair<int, int>& n) {
		return m.second > n.second;
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> occurrences;
		for (auto& v : nums) {
			occurrences[v]++;
		}

		// pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
		for (auto& kv: occurrences) {
			if (q.size() == k) {
				if (q.top().second < kv.second) {
					q.pop();
					q.emplace(kv.first, kv.second);
				}
			}
			else {
				q.emplace(kv.first, kv.second);
			}
		}
		vector<int> ret;
		while (!q.empty()) {
			ret.emplace_back(q.top().first);
			q.pop();
		}
		return ret;
	}

	//// 快排小的在左边，大的在右边
	//void qsort(vector<pair<int, int>> &v, int start, int end, vector<int> & ret, int k) {
	//	int picked = rand() % (end - start + 1) + start; // 任意选取一个数
	//	swap(v[picked], v[start]);	// 交换选择点和起始点位置

	//	int pivot = v[start].second;
	//	int index = start;
	//	for (int i = start + 1; i <= end; ++i) {
	//		if (v[i].second >= pivot) {
	//			swap(v[index + 1], v[i]);
	//			index++;
	//		}
	//	}
	//	swap(v[start], v[index]);

	//	if (k <= index - start) {
	//		qsort(v, start, index - 1, ret, k);
	//	}
	//	else {
	//		for (int i = start; i <= index; i++) {
	//			ret.push_back(v[i].first);
	//		}
	//		if (k > index - start + 1) {
	//			qsort(v, index + 1, end, ret, k - (index - start + 1));
	//		}
	//	}
	//}

	//vector<int> topKFrequent(vector<int>& nums, int k) {
	//	// 1. 哈希表统计 + 排序
	//	unordered_map<int, int> pairs;
	//	for (int i = 0; i < nums.size(); ++i) {
	//		if (pairs.find(nums[i]) == pairs.end()) {
	//			pairs.insert(make_pair(nums[i], 1));
	//		}
	//		else {
	//			pairs[nums[i]]++;
	//		}
	//	}

	//	vector<pair<int, int>> values;
	//	for (auto &kv : pairs) {
	//		values.push_back(kv);
	//	}
	//	vector<int> ret;
	//	qsort(values, 0, values.size() - 1, ret, k);
	//	return ret;
	//}
};

int main() {
	return 0;
}
