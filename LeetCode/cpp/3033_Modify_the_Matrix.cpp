class Solution {
public:
	vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
		vector<int> colMax(matrix[0].size(), 0);

		for (int j = 0; j < matrix[0].size(); j++) {
			int maxNum = -1;

			for (int i = 0; i < matrix.size(); i++) {
				maxNum = max(maxNum, matrix[i][j]);
			}

			for (int i = 0; i < matrix.size(); i++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = maxNum;
				}
			}
		}

		return matrix;
	}
};