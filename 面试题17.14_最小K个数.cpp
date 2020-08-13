#include <iostream>
#include <vector>

using namespace std;

//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

class Solution {
public:
	// 堆排序(容器)
	void heapInsert(std::vector<int> &vect, int index) {
		while (vect[index] > vect[(index - 1) / 2]) {	// i>(i-1)/2 -> 子类大于父类时进行交换，也就是保证父类大于子类
			std::swap(vect[index], vect[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	// 改变一个值，使其依旧是大根堆
	void heapify(std::vector<int> &vect, int index, int heapSize) {
		int left = index * 2 + 1;	//index = (left - 1) / 2 -> left:子类
		while (left < heapSize) {
			int largest = left + 1 < heapSize && vect[left + 1] > vect[left]	// left+1为右孩子的索引
				? left + 1 : left;		//选取子类的最大值，返回该位置的索引
			largest = vect[largest] > vect[index] ? largest : index;	//最大值跟父类比较，返回索引
			if (largest == index) {		//如果最大值就为父类，则不交换，跳出循环
				break;
			}
			std::swap(vect[index], vect[largest]);		//将找出的最大值与父类交换
			index = largest;
			left = index * 2 + 1;
		}
	}
	void heapSort(std::vector<int> &vect) {
		if (vect.size() < 2) return;
		for (unsigned int i = 0; i < vect.size(); i++) {		//对于数组中的数据，转换成大根堆
			heapInsert(vect, i);
		}
		// 到这里虽然成为了大根堆但是并没有排序
		int heapSize = vect.size();
		while (heapSize > 0) {
			std::swap(vect[0], vect[--heapSize]);	//将大根堆最大值交换到最后。这样就变成了从小到大
			heapify(vect, 0, heapSize);		//剩下的继续调整为大根堆
		}
	}
	vector<int> smallestK(vector<int>& arr, int k) {
		heapSort(arr);
		vector<int> res(k, 0);
		for (int i = 0; i < k; ++i) {
			res[i] = arr[i];
		}
		return res;
	}
};

int main() {
	vector<int> arr = { 1, 3, 5, 7, 2, 4, 6, 8 };
	int k = 4;

	Solution s;
	vector<int> res = s.smallestK(arr, k);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}

	return 0;
}
