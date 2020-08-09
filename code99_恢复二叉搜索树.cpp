#include <iostream>
#include <vector>

using namespace std;

//�����������е������ڵ㱻����ؽ�����
//
//���ڲ��ı���ṹ������£��ָ��������

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
	// 1. ��ʾ�������
	// ���ڶ�����������������ķ����õ�һ������������
	// �ݹ�������������������һ��������ȥ
	void inorder(TreeNode* root, vector<int>& nums) {
		if (root == nullptr) {
			return;
		}
		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
	}
	// �ҵ���Ҫ��������������ڵ�
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

	// ���±���ԭ����������
	// �ҵ���Ӧx��y��ֵ�����н���
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
		inorder(root, nums);	// �����������������
		pair<int, int> swapped = findTwoSwapped(nums);	// �ҵ���Ҫ�����������ڵ�
		recover(root, 2, swapped.first, swapped.second);	// ���н���
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
