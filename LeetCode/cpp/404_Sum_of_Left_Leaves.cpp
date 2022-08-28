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
	void find_sum(TreeNode* root, int& sum, bool is_left) {
		if (root == nullptr) {
			return;
		}

		if (root->left == nullptr && root->right == nullptr && is_left) {
			sum += root->val;
			return;
		}

		find_sum(root->left, sum, true);
		find_sum(root->right, sum, false);
	}

	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		bool is_left = false;
		find_sum(root, sum, is_left);

		return sum;
	}
};