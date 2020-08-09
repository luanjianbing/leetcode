#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

//���ϴδ����һ���ֵ�֮���һȦ���ݺ�С͵�ַ�����һ���µĿ����Եĵ�����
//�������ֻ��һ����ڣ����ǳ�֮Ϊ�������� 
//���ˡ�����֮�⣬ÿ����������ֻ��һ��������������֮������
//һ�����֮�󣬴�����С͵��ʶ��������ط������з��ݵ�����������һ�ö��������� 
//�������ֱ�������ķ�����ͬһ�����ϱ���٣����ݽ��Զ�������
//
//�����ڲ���������������£�С͵һ���ܹ���ȡ����߽�


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

