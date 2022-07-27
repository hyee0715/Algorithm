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
	bool find_univalued_tree(TreeNode* root, int& n) {
		if (root == nullptr)
			return true;

		if (root->val == n) {
			if (!find_univalued_tree(root->left, n) || !find_univalued_tree(root->right, n))
				return false;
		}
		else
			return false;

		return true;
	}

	bool isUnivalTree(TreeNode* root) {
		if (find_univalued_tree(root, root->val))
			return true;

		return false;
	}
};