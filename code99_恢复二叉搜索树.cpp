#include <iostream>
#include <vector>

using namespace std;

//二叉搜索树中的两个节点被错误地交换。
//
//请在不改变其结构的情况下，恢复这棵树。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	// 1. 显示中序遍历
	// 对于二叉搜索树中序遍历的方法得到一个递增的序列
	// 递归中序遍历，将结果存入一个数组中去
	void inorder(TreeNode* root, vector<int>& nums) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
	}
	// 找到需要交换的两个错误节点
	pair<int, int> findTwoSwapped(vector<int>& nums) {
		int n = nums.size();
		int x = -1, y = -1;
		for (int i = 0; i < n - 1; ++i) {
			if (nums[i + 1] < nums[i]) {
				y = nums[i + 1];
				if (x == -1) {
					x = nums[i];
				}
				else break;
			}
		}
		return{ x, y };
	}

	// 重新遍历原二叉搜索树
	// 找到对应x和y的值，进行交换
	void recover(TreeNode* r, int count, int x, int y) {
		if (r != nullptr) {
			if (r->val == x || r->val == y) {
				r->val = r->val == x ? y : x;
				if (--count == 0) {
					return;
				}
			}
			recover(r->left, count, x, y);
			recover(r->right, count, x, y);
		}
	}

	void recoverTree(TreeNode* root) {
		vector<int> nums;
		inorder(root, nums);	// 中序遍历二叉搜索树
		pair<int, int> swapped = findTwoSwapped(nums);	// 找到需要交换的两个节点
		recover(root, 2, swapped.first, swapped.second);	// 进行交换
	}

	
};

int main() {
	Solution s;

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(3);
	root->left->right = new TreeNode(2);

	s.recoverTree(root);


	return 0;
}
