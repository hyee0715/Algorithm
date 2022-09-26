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
	void check(TreeNode* root, int depth, int& answer) {
		if (root == nullptr)
			return;

		if (root->left == nullptr && root->right == nullptr) {
			answer = max(answer, depth);
		}

		check(root->left, depth + 1, answer);
		check(root->right, depth + 1, answer);
	}

	int maxDepth(TreeNode* root) {
		int answer = 0;

		check(root, 1, answer);

		return answer;
	}
};