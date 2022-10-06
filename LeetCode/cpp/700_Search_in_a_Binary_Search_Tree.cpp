/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	void search(TreeNode* root, int val, TreeNode*& answer) {
		if (root == nullptr)
			return;

		if (root->val == val) {
			answer = root;
			return;
		}

		search(root->left, val, answer);
		search(root->right, val, answer);
	}

	TreeNode* searchBST(TreeNode* root, int val) {
		TreeNode* answer = nullptr;
		search(root, val, answer);

		return answer;
	}
};