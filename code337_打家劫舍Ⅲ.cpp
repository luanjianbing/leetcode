#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
//这个地区只有一个入口，我们称之为“根”。 
//除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
//一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
//如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
//
//计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Solution {
public:
	unordered_map <TreeNode*, int> f, g;

	void dfs(TreeNode* o) {
		if (!o) {
			return;
		}
		dfs(o->left);
		dfs(o->right);
		f[o] = o->val + g[o->left] + g[o->right];
		g[o] = max(f[o->left], g[o->left]) + max(f[o->right], g[o->right]);
	}

	int rob(TreeNode* o) {
		dfs(o);
		return max(f[o], g[o]);
	}

};

int main() {
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(3);
	root->right->right = new TreeNode(1);

	Solution s;
	int res = s.rob(root);
	cout << res << endl;

	return 0;
}

