#include <iostream>
#include <queue>

using namespace std;

//给定两个二叉树，编写一个函数来检验它们是否相同。
//
//如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// 1.bfs
		if (p == nullptr || q == nullptr) {
			if (p == nullptr && q == nullptr)
				return true;
			return false;
		}
		queue<TreeNode *> myQueue_1;
		queue<TreeNode *> myQueue_2;
		myQueue_1.push(p);
		myQueue_2.push(q);
		while (!myQueue_1.empty() && !myQueue_2.empty()) {
			TreeNode *top_1 = myQueue_1.front();
			TreeNode *top_2 = myQueue_2.front();
			if (top_1->val != top_2->val)
				return false;
			if (top_1->left != nullptr && top_2->left != nullptr
				|| top_1->left == nullptr && top_2->left == nullptr) {
				if (top_1->left != nullptr) {
					myQueue_1.push(top_1->left);
					myQueue_2.push(top_2->left);
				}
			}
			else {
				return false;
			}
			if (top_1->right != nullptr && top_2->right != nullptr
				|| top_1->right == nullptr && top_2->right == nullptr) {
				if (top_1->right != nullptr) {
					myQueue_1.push(top_1->right);
					myQueue_2.push(top_2->right);
				}
			}
			else {
				return false;
			}
			myQueue_1.pop();
			myQueue_2.pop();
		}
		return true;

		// 2.dfs
		if (p == nullptr && q == nullptr) {
			return true;
		}
		else if (p == nullptr || q == nullptr) {
			return false;
		}
		else if (p->val != q->val) {
			return false;
		}
		else {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
	}
};

int main() {
	TreeNode *head1_1 = new TreeNode(1);
	head1_1->left = new TreeNode(2);
	head1_1->right = new TreeNode(3);
	TreeNode *head1_2 = new TreeNode(1);
	head1_2->left = new TreeNode(2);
	head1_2->right = new TreeNode(3);

	TreeNode *head2_1 = new TreeNode(1);
	head2_1->left = new TreeNode(2);
	TreeNode *head2_2 = new TreeNode(1);
	head2_2->right = new TreeNode(2);

	TreeNode *head3_1 = new TreeNode(1);
	head3_1->left = new TreeNode(2);
	head3_1->right = new TreeNode(1);
	TreeNode *head3_2 = new TreeNode(1);
	head3_2->left = new TreeNode(1);
	head3_2->right = new TreeNode(2);

	Solution s;
	bool res1 = s.isSameTree(head1_1, head1_2);
	cout << res1 << endl;
	bool res2 = s.isSameTree(head2_1, head2_2);
	cout << res2 << endl;
	bool res3 = s.isSameTree(head3_1, head3_2);
	cout << res3 << endl;

	return 0;
}
