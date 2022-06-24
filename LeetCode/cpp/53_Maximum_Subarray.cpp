class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp;
		int max_num = -10001;

		dp.push_back(nums[0]);
		max_num = max(max_num, dp[0]);

		if (nums.size() == 1)
			return dp[0];
		else if (nums.size() == 0)
			return 0;

		for (int i = 1; i < nums.size(); i++) {
			dp.push_back(max(nums[i], dp[i - 1] + nums[i]));

			max_num = max(max_num, dp[i]);
		}

		return max_num;
	}
};