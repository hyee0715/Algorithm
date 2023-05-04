class Solution {
public:
	int knightDialer(int n) {
		if (n == 1) {
			return 10;
		}

		int MOD = 1000000007;

		vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, 0)));

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				dp[i][j][1] = 1;
			}
		}

		for (int i = 2; i <= n; i++) {
			dp[0][0][i] = (dp[1][2][i - 1] + dp[2][1][i - 1]) % MOD;
			dp[0][1][i] = (dp[2][0][i - 1] + dp[2][2][i - 1]) % MOD;
			dp[0][2][i] = (dp[1][0][i - 1] + dp[2][1][i - 1]) % MOD;
			dp[1][0][i] = (dp[0][2][i - 1] + (dp[2][2][i - 1] + dp[3][1][i - 1]) % MOD) % MOD;
			dp[1][1][i] = 0;
			dp[1][2][i] = (dp[0][0][i - 1] + (dp[2][0][i - 1] + dp[3][1][i - 1]) % MOD) % MOD;
			dp[2][0][i] = (dp[0][1][i - 1] + dp[1][2][i - 1]) % MOD;
			dp[2][1][i] = (dp[0][0][i - 1] + dp[0][2][i - 1]) % MOD;
			dp[2][2][i] = (dp[0][1][i - 1] + dp[1][0][i - 1]) % MOD;
			dp[3][1][i] = (dp[1][0][i - 1] + dp[1][2][i - 1]) % MOD;
		}

		int answer = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				answer = (answer + dp[i][j][n]) % MOD;
			}
		}

		return answer;
	}
};