#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
	static constexpr int SEG_COUNT = 4;

	vector<string> ans;
	vector<int> segments;

public:
	// dfs(segId, segStart)��ʾ����segStart��ʼ����ip��ַ�е�segid��
	void dfs(const string& s, int segId, int segStart) {
		// ����ҵ��� 4 �� IP ��ַ���ұ��������ַ�������ô����һ�ִ�
		if (segId == SEG_COUNT) {
			if (segStart == s.size()) {
				string ipAddr;
				for (int i = 0; i < SEG_COUNT; ++i) {
					ipAddr += to_string(segments[i]);
					if (i != SEG_COUNT - 1) {
						ipAddr += ".";
					}
				}
				ans.push_back(move(ipAddr));
			}
			return;	// �Ѿ����˵��Ķε��ǻ�û����
		}

		// �����û���ҵ� 4 �� IP ��ַ���Ѿ����������ַ�������ô��ǰ����
		if (segStart == s.size()) {
			return;
		}

		// ���ڲ�����ǰ���㣬�����ǰ����Ϊ 0����ô��һ�� IP ��ַֻ��Ϊ 0
		if (s[segStart] == '0') {
			segments[segId] = 0;
			dfs(s, segId + 1, segStart + 1);
		}

		// һ�������ö��ÿһ�ֿ����Բ��ݹ�
		int addr = 0;
		for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
			addr = addr * 10 + (s[segEnd] - '0');
			if (addr > 0 && addr <= 0xFF) {
				segments[segId] = addr;
				dfs(s, segId + 1, segEnd + 1);
			}
			else {
				break;
			}
		}
	}

	vector<string> restoreIpAddresses(string s) {
		segments.resize(SEG_COUNT);
		dfs(s, 0, 0);
		return ans;
	}
};

int main() {
	string str = "25525511135";
	Solution s;
	vector<string> res = s.restoreIpAddresses(str);

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}
