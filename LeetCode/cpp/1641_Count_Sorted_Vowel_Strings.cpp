class Solution {
public:
	int countVowelStrings(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(5, 0));
		int answer = 0;

		for (int i = 0; i <= 4; i++) {
			dp[1][i] = 1;
		}

		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 4; j++) {
				for (int k = j; k <= 4; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}

		for (int i = 0; i <= 4; i++) {
			answer += dp[n][i];
		}

		return answer;
	}
};