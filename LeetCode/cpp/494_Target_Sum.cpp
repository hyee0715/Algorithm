class Solution {
public:
	int check(vector<int>& nums, int target, int idx, int sum, vector<vector<int>>& memo) {
		if (idx == nums.size()) {
			if (sum == target) {
				return 1;
			}
			return 0;
		}

		if (memo[idx][sum + 1000] != -1) {
			return memo[idx][sum + 1000];
		}

		memo[idx][sum + 1000] = check(nums, target, idx + 1, sum - nums[idx], memo);

		memo[idx][sum + 1000] += check(nums, target, idx + 1, sum + nums[idx], memo);

		return memo[idx][sum + 1000];
	}

	int findTargetSumWays(vector<int>& nums, int target) {
		vector<vector<int>> memo(nums.size(), vector<int>(2001, -1));

		return check(nums, target, 0, 0, memo);
	}
};