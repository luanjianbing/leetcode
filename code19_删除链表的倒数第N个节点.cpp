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
		// ɾ��һ���ڵ㣬�����ϲ�ڵ�ֱ��ָ���²�ڵ㼴��
		// ��һ������Ϊn+1�Ĵ������������
		// ������Ҫ��ͷ���֮ǰ�ټ�һ���ڵ�
		ListNode *bHead = new ListNode(0);
		bHead->next = head;
		ListNode *start = new ListNode(0);	// ����������ʼ�ڵ�
		ListNode *end = new ListNode(0);	// �������ڽ�ֹ�ڵ�
		// ����startָ��bhead
		start = bHead;
		// ����endָ��
		end = start;
		while (n > 0) {
			end = end->next;
			n--;
		}
		
		while (end->next != nullptr) {
			start = start->next;
			end = end->next;
		}
		if (end->next == nullptr && start == bHead) return head->next;	// ɾ�����Ǹ��ڵ�
		else if (start->next = end) start->next = nullptr;	// ɾ���������һ���ڵ�
		else {	// ɾ�������м�Ľڵ�
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

