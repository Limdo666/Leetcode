#include <vector>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> nodes;
		vector<int> res;
		if (root != nullptr)
			nodes.push(root);
		while (!nodes.empty())
		{
			TreeNode * node = nodes.top();
			nodes.pop();
			res.push_back(node->val);
			if (node->right != nullptr)
				nodes.push(node->right);
			if (node->left != nullptr)
				nodes.push(node->left);
		}
		return res;
	}
};
