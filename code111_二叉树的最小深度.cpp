#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

//给定一个二叉树，找出其最小深度。
//
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//
//说明 : 叶子节点是指没有子节点的节点。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//int minDepth(TreeNode *root) {
	//	if (root == nullptr) {
	//		return 0;
	//	}

	//	if (root->left == nullptr && root->right == nullptr) {
	//		return 1;
	//	}

	//	int min_depth = INT_MAX;
	//	if (root->left != nullptr) {
	//		min_depth = min(minDepth(root->left), min_depth);
	//	}
	//	if (root->right != nullptr) {
	//		min_depth = min(minDepth(root->right), min_depth);
	//	}

	//	return min_depth + 1;
	//}

	int minDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		queue<pair<TreeNode *, int> > que;
		que.emplace(root, 1);
		while (!que.empty()) {
			TreeNode *node = que.front().first;
			int depth = que.front().second;
			que.pop();
			if (node->left == nullptr && node->right == nullptr) {
				return depth;
			}
			if (node->left != nullptr) {
				que.emplace(node->left, depth + 1);
			}
			if (node->right != nullptr) {
				que.emplace(node->right, depth + 1);
			}
		}

		return 0;
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->left->left = new TreeNode(15);
	root->left->right = new TreeNode(7);


	TreeNode * root1 = new TreeNode(1);
	root1->left = new TreeNode(2);

	Solution s;
	cout << s.minDepth(root1) << endl;

	return 0;
}
