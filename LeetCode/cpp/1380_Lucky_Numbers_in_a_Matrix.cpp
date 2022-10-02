class Solution {
public:
	bool check(vector<vector<int>>& matrix, int num, int a, int b) {
		for (int i = 0; i < matrix.size(); i++) {
			if (matrix[i][b] > num) {
				return false;
			}
		}

		for (int i = 0; i < matrix[0].size(); i++) {
			if (matrix[a][i] < num) {
				return false;
			}
		}

		return true;
	}

	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		//행의 최소 요소, 열의 최대 요소
		vector<int> answer;

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (check(matrix, matrix[i][j], i, j)) {
					answer.push_back(matrix[i][j]);
				}
			}
		}

		return answer;
	}
};