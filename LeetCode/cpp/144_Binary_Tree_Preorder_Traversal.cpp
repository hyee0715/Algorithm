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
	vector<int> travel(TreeNode* root, vector<int>& answer) {
		if (root == nullptr) {
			return answer;
		}

		answer.push_back(root->val);

		travel(root->left, answer);
		travel(root->right, answer);

		return answer;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> v;
		vector<int> answer = travel(root, v);

		return answer;
	}
};