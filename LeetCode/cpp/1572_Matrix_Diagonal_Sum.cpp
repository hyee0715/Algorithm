class Solution {
public:
	int diagonalSum(vector<vector<int>>& mat) {
		int answer = 0;

		for (int i = 0; i < mat.size(); i++) {
			answer += mat[i][i];
			answer += mat[i][mat.size() - 1 - i];
		}

		if (mat.size() % 2 == 1) {
			int sub = mat.size() / 2;
			answer -= mat[sub][sub];
		}

		return answer;
	}
};