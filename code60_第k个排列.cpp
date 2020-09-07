#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factorial(n);
		factorial[0] = 1;
		// factorial�б������i!
		for (int i = 1; i < n; ++i) {
			factorial[i] = factorial[i - 1] * i;
		}

		//for (int i = 0; i < factorial.size(); ++i)
		//	cout << factorial[i] << endl;

		--k;
		string ans;
		vector<int> valid(n + 1, 1);	// ��¼ÿһ��Ԫ���Ƿ�ʹ�ù�
		for (int i = 1; i <= n; ++i) {
			int order = k / factorial[n - i] + 1;	// ����ڼ�����
			for (int j = 1; j <= n; ++j) {
				order -= valid[j];
				if (!order) {
					ans += (j + '0');
					valid[j] = 0;
					break;
				}
			}
			k %= factorial[n - i];
		}
		return ans;
	}
};

int main() {
	int n = 4;
	int k = 9;

	Solution s;
	cout << s.getPermutation(n, k) << endl;

	return 0;
}
