#include <iostream>
#include <vector>

using namespace std;

//�� N �����䣬��ʼʱ��λ�� 0 �ŷ��䡣
//ÿ�������в�ͬ�ĺ��룺0��1��2��...��N - 1��
//���ҷ����������һЩԿ����ʹ�������һ�����䡣
//
//����ʽ�ϣ�����ÿ������ i ����һ��Կ���б� rooms[i]��
//ÿ��Կ�� rooms[i][j] ��[0, 1��...��N - 1] �е�һ��������ʾ��
//���� N = rooms.length�� Կ�� rooms[i][j] = v ���Դ򿪱��Ϊ v �ķ��䡣
//
//������� 0 �ŷ�������������з��䶼����ס��
//
//��������ɵ��ڷ���֮�������߶���
//
//����ܽ���ÿ�����䷵�� true�����򷵻� false��

class Solution {
public:
	void dfs(vector<vector<int>> &rooms, vector<bool> &hasVisited, int i) {
		if (hasVisited[i]) return;
		hasVisited[i] = true;
		for (int j = 0; j < rooms[i].size(); ++j) {
			dfs(rooms, hasVisited, rooms[i][j]);
		}
	}

	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		// ���Ϊ����ͼ�ж���û�й�����
		int nSize = rooms.size();
		vector<bool> hasVisited(nSize, false);

		dfs(rooms, hasVisited, 0);

		for (int i = 0; i < hasVisited.size(); ++i) {
			if (!hasVisited[i]) return false;
		}
		return true;
	}
};

int main() {
	vector<vector<int>> rooms = { {1, 3}, {3, 0, 1}, {2}, {0} };
	vector<vector<int>> rooms1 = { { 1 },{ 2 },{ 3 },{  } };

	Solution s;
	cout << s.canVisitAllRooms(rooms1) << endl;

	return 0;
}
