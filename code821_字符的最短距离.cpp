#include <iostream>
#include <vector>

using namespace std;

//����һ���ַ��� S ��һ���ַ� C��
//����һ�������ַ��� S ��ÿ���ַ����ַ��� S �е��ַ� C ����̾�������顣

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		int sz = S.length();
		vector<int> ans(sz);
		if (sz == 0) return ans;
		// ����ÿһ���ַ�������Ѱ�ң��ҵ�һ�������C��Ϊ���
		bool findLeft = true;
		bool findRight = true;
		for (int i = 0; i < sz; ++i) {
			
			if (S.at(i) == C) {
				ans[i] = 0;
				continue;
			}
			findLeft = true;
			findRight = true;

			int left = i - 1;
			int right = i + 1;
			if (left < 0) { left = 0; findLeft = false; }
			if (right > sz - 1) { right = sz - 1; findRight = false; }

			while (findLeft || findRight)
			{
				if (findLeft) {
					if (S.at(left) == C) {
						ans[i] = i - left;
						break;
					}
					else {
						left--;
						if (left < 0) 
							findLeft = false; 
					}
				}
				if (findRight) {
					if (S.at(right) == C) {
						ans[i] = right - i;
						break;
					}
					else {
						right++;
						if (right > sz - 1) 
							findRight = false;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	string S = "loveleetcode";
	char C = 'e';

	Solution s;
	vector<int> ans = s.shortestToChar(S, C);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}

	return 0;
}
