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
	void check(TreeNode* root, unordered_map<int, int>& um, int depth) {
		if (root == NULL) {
			return;
		}

		um[depth] = um[depth] + root->val;

		check(root->left, um, depth + 1);
		check(root->right, um, depth + 1);
	}

	int deepestLeavesSum(TreeNode* root) {
		int answer = 0;
		unordered_map<int, int> um;

		check(root, um, 0);

		int maxNum = -1;

		for (auto m : um) {
			if (m.first > maxNum) {
				maxNum = m.first;
				answer = m.second;
			}
		}

		return answer;
	}
};