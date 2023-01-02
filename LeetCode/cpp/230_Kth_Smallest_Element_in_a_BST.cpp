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
	priority_queue<int, vector<int>, greater<>> check(TreeNode* root, priority_queue<int, vector<int>, greater<>>& low) {
		if (root == nullptr) {
			return low;
		}

		low.push(root->val);
		check(root->left, low);
		check(root->right, low);

		return low;
	}

	int kthSmallest(TreeNode* root, int k) {
		priority_queue<int, vector<int>, greater<>> low;

		check(root, low);

		int answer = 0;

		for (int i = 0; i < k; i++) {
			answer = low.top();
			low.pop();
		}

		return answer;
	}
};