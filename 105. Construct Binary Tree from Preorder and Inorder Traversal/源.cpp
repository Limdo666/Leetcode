/*
Given preorder and inorder traversal of a tree, construct the binary tree.
*/


#include<vector>

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
	int preorderIndx = 0;
	int search(vector<int>&arr, int s, int e, int val) {
		int i = s;
		for (;i <= e;i++) {
			if (arr[i] == val) break;
		}
		return i;
	}
	TreeNode * buildTreeHlper(vector<int>& preorder, vector<int>& inorder, int start, int end) {

		if (start>end) return NULL;

		TreeNode* tnode = new TreeNode(preorder[preorderIndx++]);

		if (start == end) return tnode;

		int Inindx = search(inorder, start, end, tnode->val);

		tnode->left = buildTreeHlper(preorder, inorder, start, Inindx - 1);
		tnode->right = buildTreeHlper(preorder, inorder, Inindx + 1, end);

		return tnode;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		return buildTreeHlper(preorder, inorder, 0, inorder.size() - 1);
	}
};