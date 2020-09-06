#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//����һ����������������ڵ�ֵ�Ե����ϵĲ�α����� 
//��������Ҷ�ӽڵ����ڲ㵽���ڵ����ڵĲ㣬���������ұ�����

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
		if (root == nullptr) return ans;
		queue<TreeNode *> myQueue;
		myQueue.push(root);

		while (!myQueue.empty()) {
			vector<int> level;
			int size = myQueue.size();	// ������ȷ��ÿһ��ÿһ��ı���
			for (int i = 0; i < size; ++i) {
				TreeNode *node = myQueue.front();
				myQueue.pop();
				level.push_back(node->val);
				if (node->left != nullptr) myQueue.push(node->left);
				if (node->right != nullptr) myQueue.push(node->right);
			}
			ans.push_back(level);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);

	Solution s;
	vector<vector<int>> res = s.levelOrderBottom(root);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}

	return 0;
}
