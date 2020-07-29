#include <iostream>
#include <vector>
#include <queue>
//
//���ǵõ���һ���ر�ͼ���ر�ͼ��ʾ����һ���Թ��д�����δ�����˷��ֵı��ء�
//
//�Թ���һ����ά������һ���ַ��������ʾ������ʶ��Ψһ����ڣ��� 'S' ��ʾ������Ψһ�ı��صص㣨�� 'T' ��ʾ�������ǣ����ر�һЩ���εĻ��ر������������ڵ�ͼ�������ɸ����ص㣨�� 'M' ��ʾ����ֻ�����л��ؾ����������ſ����õ����ء�
//
//Ҫ���ֻ��صĴ�������Ҫ��һ����ʯ�������档�Թ��������ɸ�ʯ�ѣ��� 'O' ��ʾ����ÿ��ʯ�Ѷ������޸��㹻�������ص���ʯ����������ʯͷ̫�أ�����һ��ֻ�ܰ�һ��ʯͷ��ָ���ص㡣
//
//�Թ���ͬ����һЩǽ�ڣ��� '#' ��ʾ�������ǲ�������ǽ�ڡ�ʣ��Ķ��ǿ�����ͨ�еĵ㣨�� '.' ��ʾ����ʯ�ѡ����ء������յ㣨�����Ƿ����õ����أ�Ҳ�ǿ���ͨ�еġ�
//
//����ÿ������ѡ������ / ���� / ���� / �����ƶ�һ�񣬲��Ҳ����Ƴ��Թ�������ʯͷ�ͷ���ʯͷ���㲽������ô������㿪ʼ������������Ҫ���ٲ���������õ������أ�����޷��õ����أ����� - 1 ��


using namespace std;

class Solution {
public:
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };
	int n, m;	// ԭmaze��Сrow/col

	bool inBound(int x, int y) {
		return x >= 0 && x < n && y >= 0 && y < m;
	}

	vector<vector<int>> bfs(int x, int y, vector<string>& maze) {
		vector<vector<int>> ret(n, vector<int>(m, -1));	// ��ʼ��ԭmaze��Сvector
		ret[x][y] = 0;	// ��ʼ����Ϊ0
		queue<pair<int, int>> Q;
		Q.push({ x, y });	// ����ѹ����ʼ��
		while (!Q.empty()) {
			auto p = Q.front();
			Q.pop();
			int x = p.first, y = p.second;	// �õ�����ǰ�˵�����
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];	// ��һ����ʵҲ�����ҵ���ǰ�����Χ�ĸ��㣬bfs
				if (inBound(nx, ny) && maze[nx][ny] != '#' && ret[nx][ny] == -1) {
					ret[nx][ny] = ret[x][y] + 1;	// ����õ㵽������ǽ��Ĳ��������룩
					Q.push({ nx, ny });
				}
			}
		}
		return ret;
	}

	int minimalSteps(vector<string>& maze) {
		n = maze.size(), m = maze[0].size();	// n = ����, m = ����
		// ���� & ʯͷ
		vector<pair<int, int>> buttons, stones;
		// ��� & �յ�
		int sx, sy, tx, ty;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (maze[i][j] == 'M') {		// �ҵ����л���λ��
					buttons.push_back({ i, j });
				}
				if (maze[i][j] == 'O') {		// �ҵ�����ʯͷλ��
					stones.push_back({ i, j });
				}
				if (maze[i][j] == 'S') {		// �ҵ���ʼ��λ��
					sx = i, sy = j;			// <startx, starty>
				}
				if (maze[i][j] == 'T') {		// �ҵ��յ�λ��
					tx = i, ty = j;			// <terminalx, terminaly>
				}
			}
		}
		int nb = buttons.size();	// ����õ���������
		int ns = stones.size();		// ����õ�ʯͷ����
		vector<vector<int>> start_dist = bfs(sx, sy, maze);	// ��һ���õ���ʼ�㵽����ǽ��Ĳ���������bfs

		cout << "start_dist��ʼ�㵽���ܵ�������" << endl;
		for (int i = 0; i < start_dist.size(); i++) {
			for (int j = 0; j < start_dist[i].size(); ++j) {
				cout << start_dist[i][j] << " ";
			}
			cout << endl;
		}

		// �߽������û�л���
		if (nb == 0) {
			return start_dist[tx][ty];	// û�л���ֱ����ȥ�յ�
		}
		// ��ĳ�����ص��������� / ������յ����̾��롣
		vector<vector<int>> dist(nb, vector<int>(nb + 2, -1));
		// �м���
		vector<vector<vector<int>>> dd(nb);
		for (int i = 0; i < nb; i++) {
			vector<vector<int>> d = bfs(buttons[i].first, buttons[i].second, maze);
			dd[i] = d;	// ĳ�����ص�����ǽ��ľ�����Ϣ
			// ��ĳ���㵽�յ㲻��Ҫ��ʯͷ
			dist[i][nb + 1] = d[tx][ty];	// ĳ�����ص��յ�ľ���
		}

		cout << "dist���ص㵽�յ�ľ���" << endl;
		for (int i = 0; i < dist.size(); i++) {
			for (int j = 0; j < dist[i].size(); ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < nb; i++) {	// �����������ص�
			int tmp = -1;
			for (int k = 0; k < ns; k++) {
				int mid_x = stones[k].first, mid_y = stones[k].second;
				if (dd[i][mid_x][mid_y] != -1 && start_dist[mid_x][mid_y] != -1) {	// �û��ص���Ե����ʯͷ�� �Լ� ��ʯͷ���������㵽��
					if (tmp == -1 || tmp > dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y]) {
						tmp = dd[i][mid_x][mid_y] + start_dist[mid_x][mid_y];	
					}
				}
			}
			dist[i][nb] = tmp;// ��һ��֮��õ�����㵽ʯͷ��+��ʯͷ�㵽�û��ص���С�ľ���
			for (int j = i + 1; j < nb; j++) {
				int mn = -1;
				for (int k = 0; k < ns; k++) {
					int mid_x = stones[k].first, mid_y = stones[k].second;
					if (dd[i][mid_x][mid_y] != -1 && dd[j][mid_x][mid_y] != -1) {
						if (mn == -1 || mn > dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y]) {
							mn = dd[i][mid_x][mid_y] + dd[j][mid_x][mid_y];	
						}
					}
				}
				dist[i][j] = mn;	// ��һ��֮���ҵ��û��ص㵽��һ�����ص���С����
				dist[j][i] = mn;
			}
		}

		cout << "dist���ص�����ص�֮������ʯͷ��С·������ʼ������ʯͷ�����ص���С·��" << endl;
		for (int i = 0; i < dist.size(); i++) {
			for (int j = 0; j < dist[i].size(); ++j) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}

		// �޷���ɵ�����
		for (int i = 0; i < nb; i++) {	// ��˵���л����޷�����㵽������л����޷������յ㣬�޷��������л��ش�����
			if (dist[i][nb] == -1 || dist[i][nb + 1] == -1) return -1;
		}

		// dp ���飬 -1 ����û�б�����
		vector<vector<int>> dp(1 << nb, vector<int>(nb, -1));
		for (int i = 0; i < nb; i++) {
			dp[1 << i][i] = dist[i][nb];	// �����Ϣ
		}

		cout << "dp" << endl;
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		// ��ʼ��->����+����->��һ������->������
		// ���ڸ��µ�״̬����δ���µĴ�����ֱ�Ӵ�С�����������
		for (int mask = 1; mask < (1 << nb); mask++) {
			for (int i = 0; i < nb; i++) {
				// ��ǰ dp �ǺϷ���
				if (mask & (1 << i)) {
					for (int j = 0; j < nb; j++) {
						// j ���� mask ��
						if (!(mask & (1 << j))) {
							int next = mask | (1 << j);
							if (next == 7) cout << "next = 7 : "<< mask << " " << i << " "<< j << endl;
							else cout << "next = " << next << " " << mask << " " << i << " " << j << endl;
							if (dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dist[i][j]) {
								dp[next][j] = dp[mask][i] + dist[i][j];	// ��㵽��һ������+���ص���һ������
							}
						}
					}
				}
			}
		}

		cout << "dp" << endl;
		for (int i = 0; i < dp.size(); i++) {
			for (int j = 0; j < dp[i].size(); ++j) {
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		// ��ʼ��->����+����->��һ������->������+���һ������->�յ�
		int ret = -1;
		int final_mask = (1 << nb) - 1;
		for (int i = 0; i < nb; i++) {
			if (ret == -1 || ret > dp[final_mask][i] + dist[i][nb + 1]) {
				ret = dp[final_mask][i] + dist[i][nb + 1];
			}
		}

		return ret;
	}
};

int main() {
	vector<string> maze = { "S#OM", "M...", "M.T." };	// �����ַ�һά����Ҳ������vect[i][j]����
	Solution s;
	int res = s.minimalSteps(maze);
	cout << res << endl;
	return 0;
}

