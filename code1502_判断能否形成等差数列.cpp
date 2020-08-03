#include <iostream>
#include <vector>

using namespace std;

//����һ���������� arr ��
//
//���һ�������У�������������Ĳ��ܵ���ͬһ����������ô������оͳ�Ϊ �Ȳ����� ��
//
//��������������������γɵȲ����У��뷵�� true �����򣬷��� false ��

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
		if (diff == 0) return true;	// ���ֶ���һ�����������ֱ�ӷ���true
		// ����vSize��Ͱ
		vector<bool> hasBuckets(vSize, false);
		vector<int> buckets(vSize, 0);
		int bIdx = 0;
		for (int i = 0; i < vSize; ++i) {
			// ����Ԥ���޸�
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

