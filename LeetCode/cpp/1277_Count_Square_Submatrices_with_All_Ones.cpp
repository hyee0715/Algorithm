class Solution {
public:
	bool check(vector<vector<int>>& matrix, int x, int y, int length) {
		for (int a = 0; a < length; a++) {
			for (int b = 0; b < length; b++) {
				if (matrix[x + a][y + b] == 0) {
					return false;
				}
			}
		}

		return true;
	}

	int countSquares(vector<vector<int>>& matrix) {
		int answer = 0;
		int minLength = min(matrix.size(), matrix[0].size());

		for (int i = 1; i <= minLength; i++) {
			for (int j = 0; j <= matrix.size() - i; j++) {
				for (int k = 0; k <= matrix[j].size() - i; k++) {
					if (check(matrix, j, k, i)) {
						answer++;
					}
				}
			}
		}

		return answer;
	}
};