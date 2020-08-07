#include <iostream>
#include <vector>

using namespace std;

//������ת���顣����һ�����������飬����n��������
//����������ѱ���ת���ܶ���ˣ��������ꡣ���д�����ҳ������е�ĳ��Ԫ�أ�
//��������Ԫ��ԭ���ǰ��������еġ����ж����ͬԪ�أ���������ֵ��С��һ����

class Solution {
public:
	int binarySearch(vector<int> &arr, int low, int high, int key)
	{
		while (low <= high)
		{
			int mid = (low + high) >> 1;
			if (key == arr[mid])
				return mid;
			else if (key > arr[mid])
				low = mid + 1;
			else
				high = mid - 1;
		}
		return -1;
	}


	int search(vector<int>& arr, int target) {
		// 1. �۰����
		int left = 0; 
		int right = arr.size() - 1;
		int mid = (left + right) >> 1;

		while (left < right) {

		}
		

		//// 2. Ͱ����
		//int vSize = arr.size();
		//int max = INT_MIN;
		//int min = INT_MAX;
		//for (int i = 0; i < vSize; ++i) {
		//	min = min < arr[i] ? min : arr[i];
		//	max = max > arr[i] ? max : arr[i];
		//}
		//if (target < min || target > max) return -1;
		//int diff = max - min;
		//int bLength = diff + 1;	// ������ max ��Ͱ
		//std::vector<int> buckets(bLength, -1);
		//std::vector<bool> bucketsHasNum(bLength, false);
		//int bIdx = 0;	// ȥ����Ͱ
		//for (int i = 0; i < vSize; ++i) {
		//	bIdx = arr[i] - min;
		//	if (!bucketsHasNum[bIdx]) {
		//		buckets[bIdx] = i;	// ����������
		//		bucketsHasNum[bIdx] = true;
		//	}
		//	else {	// ˵�����Ͱ�Ѿ���Ԫ����
		//		// �Ƚ�������С
		//		buckets[bIdx] = buckets[bIdx] < i ? buckets[bIdx] : i;
		//	}
		//	
		//}
		//int tarIdx = target - min;	// ����ȥ����Ͱ
		//return buckets[tarIdx];
	}
};

int main() {
	int target1 = 5;
	vector<int> arr1 = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	int target2 = 11;
	vector<int> arr2 = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	int target3 = 5;
	vector<int> arr3 = { 5, 5, 5, 1, 2, 3, 4, 5, 5 };
	int target4 = 4;
	vector<int> arr4 = { 21, 21, -21, -20, -17, -8, -6, -2, -2, -1, 0, 2, 3, 4, 4, 6, 11, 13, 14, 16, 17, 18, 20 };

	
	Solution s;
	int res1 = s.search(arr1, target1);
	cout << res1 << endl;
	int res2 = s.search(arr2, target2);
	cout << res2 << endl;
	int res3 = s.search(arr3, target3);
	cout << res3 << endl;
	int res4 = s.search(arr4, target4);
	cout << res4 << endl;

	return 0;
}
