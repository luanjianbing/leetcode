#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//�������� ��ͨ ͼ��һ���ڵ�����ã����㷵�ظ�ͼ�� �������¡����
//
//ͼ�е�ÿ���ڵ㶼��������ֵ val��int�� �����ھӵ��б�list[Node]����

// Definition for a Node.
class Node {
public:
	int val;
	vector<Node *> neighbors;

	Node() {
		val = 0;
		neighbors = vector<Node *>();
	}

	Node(int _val) {
		val = _val;
		neighbors = vector<Node *>();
	}

	Node(int _val, vector<Node *> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};


class Solution {
public:
	unordered_map<Node *, Node *> visited;
	Node* cloneGraph(Node* node) {
		if (node == nullptr) {
			return node;
		}

		// ����ýڵ��Ѿ������ʹ��ˣ���ֱ�Ӵӹ�ϣ����ȡ����Ӧ�Ŀ�¡�ڵ㷵��
		if (visited.find(node) != visited.end()) {
			return visited[node];
		}

		// ��¡�ڵ㣬ע�⵽Ϊ��������ǲ����¡�����ھӵ��б�
		Node* cloneNode = new Node(node->val);
		// ��ϣ��洢
		visited[node] = cloneNode;

		// �����ýڵ���ھӲ����¿�¡�ڵ���ھ��б�
		for (auto& neighbor : node->neighbors) {
			cloneNode->neighbors.emplace_back(cloneGraph(neighbor));
		}
		return cloneNode;
	}
};

int main() {
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);

	n1->neighbors.push_back(n2);
	n1->neighbors.push_back(n4);

	n2->neighbors.push_back(n1);
	n2->neighbors.push_back(n3);

	n3->neighbors.push_back(n2);
	n3->neighbors.push_back(n4);

	n4->neighbors.push_back(n1);
	n4->neighbors.push_back(n3);

	Solution s;
	Node *res = s.cloneGraph(n1);
	cout << res->val << endl;
	cout << res->neighbors[0]->val << endl;
	cout << res->neighbors[0]->neighbors[1]->val << endl;
	cout << res->neighbors[1]->val << endl;

	return 0;
}

