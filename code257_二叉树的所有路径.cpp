#include <iostream>
#include <vector>
#include <sstream>
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
	void dfs(vector<string> &ans, TreeNode *node, string curString) {
		if (node != nullptr) {
			curString += to_string(node->val);
			if (node->left == nullptr && node->right == nullptr) {	// 当前节点是叶子节点
				ans.push_back(curString);	// 答案加入ans中
			}
			else {	// 当前节点不是叶子节点
				curString += "->";	
				dfs(ans, node->left, curString);
				dfs(ans, node->right, curString);
			}
		}
	}

	vector<string> binaryTreePaths(TreeNode* root) {
		//// 1. dfs
		//vector<string> ans;
		//string curString = "";
		//dfs(ans, root, curString);
		//return ans;

		// 2. bfs
		vector<string> paths;
		if (root == nullptr) return paths;

		queue<TreeNode *> node_queue;
		queue<string> path_queue;

		node_queue.push(root);
		path_queue.push(to_string(root->val));

		while (!node_queue.empty()) {
			TreeNode *node = node_queue.front();
			string path = path_queue.front();
			node_queue.pop();
			path_queue.pop();

			if (node->left == nullptr && node->right == nullptr) {
				paths.push_back(path);
			}
			else {
				if (node->left != nullptr) {
					node_queue.push(node->left);
					path_queue.push(path + "->" + to_string(node->left->val));
				}
				if (node->right != nullptr) {
					node_queue.push(node->right);
					path_queue.push(path + "->" + to_string(node->right->val));
				}
			}
		}
		return paths;
	}
};

int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(5);

	Solution s;
	vector<string> res = s.binaryTreePaths(root);

	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << endl;

	return 0;
}
