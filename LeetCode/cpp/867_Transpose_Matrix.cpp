﻿class Solution {
public:
	vector<vector<int>> transpose(vector<vector<int>>& matrix) {
		vector<vector<int>> answer;
		vector<int> temp;

		for (int i = 0; i < matrix[0].size(); i++) {
			temp.clear();

			for (int j = 0; j < matrix.size(); j++) {
				temp.push_back(matrix[j][i]);
			}

			answer.push_back(temp);
		}

		return answer;
	}
};