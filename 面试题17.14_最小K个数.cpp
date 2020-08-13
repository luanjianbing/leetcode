#include <iostream>
#include <vector>

using namespace std;

//���һ���㷨���ҳ���������С��k������������˳�򷵻���k�������ɡ�

class Solution {
public:
	// ������(����)
	void heapInsert(std::vector<int> &vect, int index) {
		while (vect[index] > vect[(index - 1) / 2]) {	// i>(i-1)/2 -> ������ڸ���ʱ���н�����Ҳ���Ǳ�֤�����������
			std::swap(vect[index], vect[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}
	// �ı�һ��ֵ��ʹ�������Ǵ����
	void heapify(std::vector<int> &vect, int index, int heapSize) {
		int left = index * 2 + 1;	//index = (left - 1) / 2 -> left:����
		while (left < heapSize) {
			int largest = left + 1 < heapSize && vect[left + 1] > vect[left]	// left+1Ϊ�Һ��ӵ�����
				? left + 1 : left;		//ѡȡ��������ֵ�����ظ�λ�õ�����
			largest = vect[largest] > vect[index] ? largest : index;	//���ֵ������Ƚϣ���������
			if (largest == index) {		//������ֵ��Ϊ���࣬�򲻽���������ѭ��
				break;
			}
			std::swap(vect[index], vect[largest]);		//���ҳ������ֵ�븸�ཻ��
			index = largest;
			left = index * 2 + 1;
		}
	}
	void heapSort(std::vector<int> &vect) {
		if (vect.size() < 2) return;
		for (unsigned int i = 0; i < vect.size(); i++) {		//���������е����ݣ�ת���ɴ����
			heapInsert(vect, i);
		}
		// ��������Ȼ��Ϊ�˴���ѵ��ǲ�û������
		int heapSize = vect.size();
		while (heapSize > 0) {
			std::swap(vect[0], vect[--heapSize]);	//����������ֵ��������������ͱ���˴�С����
			heapify(vect, 0, heapSize);		//ʣ�µļ�������Ϊ�����
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
