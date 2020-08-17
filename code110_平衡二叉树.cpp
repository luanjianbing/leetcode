#include <iostream>
#include <vector>
#include <algorithm>

//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	//int dfsMax(TreeNode *node, int n) {
	//	if (node == NULL) return n;
	//	return max(dfsMax(node->left, n + 1), dfsMax(node->right, n + 1));
	//}

	//int dfsMin(TreeNode *node, int n) {
	//	if (node == NULL) return n;
	//	return min(dfsMax(node->left, n + 1), dfsMax(node->right, n + 1));
	//}

	//bool isBalanced(TreeNode* root) {
	//	int maxDepth = dfsMax(root, 0);
	//	int minDepth = dfsMin(root, 0);
	//	cout << maxDepth << " " << minDepth << endl;
	//	return (maxDepth - minDepth) < 2 ? true : false;
	//}

	int height(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		else {
			return max(height(root->left), height(root->right)) + 1;
		}
	}

	bool isBalanced(TreeNode* root) {
		if (root == NULL) {
			return true;
		}
		else {
			return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
		}
	}
};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);


	Solution s;
	cout << s.isBalanced(root) << endl;

	return 0;
}
