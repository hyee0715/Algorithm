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
	void check(TreeNode* root, int k, set<int>& st, bool& flag) {
		if (root == nullptr) {
			return;
		}

		if (st.find(root->val) == st.end()) {
			st.insert(k - root->val);

			check(root->left, k, st, flag);
			check(root->right, k, st, flag);
		}
		else {
			flag = true;
			return;
		}
	}

	bool findTarget(TreeNode* root, int k) {
		set<int> st;
		bool flag = false;

		check(root, k, st, flag);

		if (flag)
			return true;
		return false;
	}
};