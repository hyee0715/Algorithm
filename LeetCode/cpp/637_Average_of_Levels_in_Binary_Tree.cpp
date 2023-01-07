﻿/**
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
	vector<double> check(TreeNode* root) {
		vector<double> answer;
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {
			int size = q.size();
			double sum = 0;

			for (int k = 0; k < size; k++) {
				TreeNode* node = q.front();
				q.pop();

				sum += node->val;

				if (node->left != nullptr) {
					q.push(node->left);
				}

				if (node->right != nullptr) {
					q.push(node->right);
				}
			}

			answer.push_back((double)sum / size);
		}

		return answer;
	}

	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> answer = check(root);

		return answer;
	}
};