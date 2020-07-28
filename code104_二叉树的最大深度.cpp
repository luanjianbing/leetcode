#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int maxDepth(TreeNode* root) {
		//// 1. �ݹ����ҽڵ㣬��������ķ�֧
		//if (root == nullptr) return 0;
		//return max(maxDepth(root->left), maxDepth(root->right)) + 1;
		
		// 2. �������������һ������
		queue<TreeNode *> thisQueue;
		thisQueue.push(root);	// ��ѹ����ڵ�
		int ans = 0;
		while (!thisQueue.empty())
		{
			int qSize = thisQueue.size();
			while (qSize > 0)
			{
				qSize--;
				TreeNode *node = thisQueue.front();
				if (node->left != nullptr) thisQueue.push(node->left);
				if (node->right != nullptr) thisQueue.push(node->right);
				thisQueue.pop();
			}
			ans++;
		}
		return ans;
	}
};

int main() {
	Solution s;

	TreeNode *head = new TreeNode(3);
	head->left = new TreeNode(9);
	head->right = new TreeNode(20);
	head->right->left = new TreeNode(15);
	head->right->right = new TreeNode(7);

	int depth = s.maxDepth(head);
	cout << depth << endl;

	return 1;
}