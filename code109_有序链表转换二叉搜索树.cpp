#include <iostream>

//给定一个单链表，其中的元素按升序排序，
//将其转换为高度平衡的二叉搜索树。
//
//本题中，一个高度平衡二叉树是指一个二叉树每个节点 
//的左右两个子树的高度差的绝对值不超过 1。



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
;

class Solution {
public:
	// 首先需要找到链表的中的中间节点，奇数的话就为中间
	// 偶数的话任一都可
	ListNode* getMedian(ListNode *left, ListNode *right) {
		ListNode* fast = left;
		ListNode* slow = left;
		while (fast != right && fast->next != right) {
			// 快指针移动两次，慢指针移动一次
			fast = fast->next;
			fast = fast->next;
			slow = slow->next;
		}
		// 退出循环时，快指针到右侧，当前慢指针即为mid
		return slow;
	}

	TreeNode* buildTree(ListNode* left, ListNode* right) {
		if (left == right)
			return nullptr;
		ListNode* mid = getMedian(left, right);	// 找到根节点
		TreeNode* root = new TreeNode(mid->val);
		// 左右建树
		root->left = buildTree(left, mid);
		root->right = buildTree(mid->next, right);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		// 排完序
		// 找到中间节点作为根节点
		// 然后左右以此建树
		return buildTree(head, nullptr);
	}
};

int main() {

	return 0;
}
