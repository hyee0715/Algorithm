class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount + 1, INT_MAX - 1);

		dp[0] = 0;

		for (int coin : coins) {
			for (int i = coin; i <= amount; i++) {
				dp[i] = min(dp[i - coin] + 1, dp[i]);
			}
		}

		for (int i = 0; i < dp.size(); i++) {
			if (dp[i] == INT_MAX - 1) {
				dp[i] = -1;
			}
		}

		return dp[amount];
	}
};