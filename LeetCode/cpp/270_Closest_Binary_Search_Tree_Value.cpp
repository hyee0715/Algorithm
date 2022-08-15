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
	void travel_tree(TreeNode* root, double target, double& min_value, int& min_node_num) {
		if (root == nullptr)
			return;

		if (min_value > abs(root->val - target)) {
			min_value = abs(root->val - target);
			min_node_num = root->val;
		}


		travel_tree(root->left, target, min_value, min_node_num);
		travel_tree(root->right, target, min_value, min_node_num);
	}

	int closestValue(TreeNode* root, double target) {
		double min_value = 1000000001;
		int min_node_num = 0;

		travel_tree(root, target, min_value, min_node_num);

		return min_node_num;
	}
};