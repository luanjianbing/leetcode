#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		// 删除一个节点，即将上层节点直接指向下层节点即可
		// 用一个长度为n+1的窗口逐个滑动，
		// 首先需要在头结点之前再加一个节点
		ListNode *bHead = new ListNode(0);
		bHead->next = head;
		ListNode *start = new ListNode(0);	// 滑动窗口起始节点
		ListNode *end = new ListNode(0);	// 滑动窗口截止节点
		// 首先start指向bhead
		start = bHead;
		// 计算end指向
		end = start;
		while (n > 0) {
			end = end->next;
			n--;
		}
		
		while (end->next != nullptr) {
			start = start->next;
			end = end->next;
		}
		if (end->next == nullptr && start == bHead) return head->next;	// 删除的是根节点
		else if (start->next = end) start->next = nullptr;	// 删除的是最后一个节点
		else {	// 删除的是中间的节点
			start->next->next = nullptr;
			start->next = end;
			return head;
		}
	}
};

int main() {
	Solution s;

	int n = 2;
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);

	ListNode *res = s.removeNthFromEnd(root, n);
	cout << (res == root) << endl;


	return 0;
}

