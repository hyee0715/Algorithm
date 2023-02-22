class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& matrix) {
		vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
		int answer = INT_MAX;

		for (int i = 0; i < matrix[0].size(); i++) {
			dp[0][i] = matrix[0][i];
		}

		for (int i = 1; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				if (j == 0) {
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i][j];
				}
				else if (j == matrix[i].size() - 1) {
					dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i][j];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1])) + matrix[i][j];
				}
			}
		}

		for (int i = 0; i < dp[0].size(); i++) {
			answer = min(answer, dp[dp.size() - 1][i]);
		}

		return answer;
	}
};