class Solution {
public:
	bool check(vector<vector<int>>& mat, int a, int b) {
		for (int i = 0; i < mat.size(); i++) {
			if (i == a) continue;

			if (mat[i][b] != 0)
				return false;
		}

		for (int j = 0; j < mat[a].size(); j++) {
			if (j == b) continue;

			if (mat[a][j] != 0)
				return false;
		}

		return true;
	}

	int numSpecial(vector<vector<int>>& mat) {
		int answer = 0;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 1) {
					if (check(mat, i, j))
						answer++;
				}
			}
		}

		return answer;
	}
};