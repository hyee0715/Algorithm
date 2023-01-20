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
	int check(TreeNode* root, int low, int high) {
		if (root == nullptr) {
			return 0;
		}

		if (root->val >= low && root->val <= high) {
			return check(root->left, low, high) + root->val + check(root->right, low, high);
		}
		else {
			return check(root->left, low, high) + check(root->right, low, high);
		}
	}

	int rangeSumBST(TreeNode* root, int low, int high) {
		int answer = check(root, low, high);

		return answer;
	}
};