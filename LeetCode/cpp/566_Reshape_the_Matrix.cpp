class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		if (r * c != mat.size() * mat[0].size()) {
			return mat;
		}

		vector<vector<int>> answer(r, vector<int>(c));

		int rIdx = 0;
		int cIdx = 0;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[0].size(); j++) {
				answer[rIdx][cIdx++] = mat[i][j];

				if (cIdx == c) {
					rIdx++;
					cIdx = 0;
				}
			}
		}

		return answer;
	}
};