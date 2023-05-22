class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int answer = INT_MAX;
		vector<vector<int>> dp(200, vector<int>(200, 0));

		if (triangle.size() == 1) {
			return triangle[0][0];
		}
		else if (triangle.size() == 2) {
			answer = min(triangle[0][0] + triangle[1][0], triangle[0][0] + triangle[1][1]);
			return answer;
		}

		dp[0][0] = triangle[0][0];
		dp[1][0] = dp[0][0] + triangle[1][0];
		dp[1][1] = dp[0][0] + triangle[1][1];

		for (int i = 2; i < triangle.size(); i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					dp[i][j] = dp[i - 1][j] + triangle[i][j];
				}
				else if (j == i) {
					dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				}
				else {
					dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
				}
			}
		}

		for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
			answer = min(answer, dp[triangle.size() - 1][i]);
		}

		return answer;
	}
};