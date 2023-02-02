class Solution {
public:
	long long find_subarray(vector<long long>& dp, int zero_cnt) {
		if (zero_cnt == 1) {
			return 1;
		}

		if (dp[zero_cnt] != -1) {
			return dp[zero_cnt];
		}

		return dp[zero_cnt] = find_subarray(dp, zero_cnt - 1) + zero_cnt;
	}

	long long zeroFilledSubarray(vector<int>& nums) {
		long long answer = 0;
		vector<long long> dp(nums.size() + 1, -1);

		int zero_cnt = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == nums[i] && nums[i] == 0) {
				zero_cnt++;
				continue;
			}

			if (nums[i - 1] != nums[i] && nums[i - 1] == 0) {
				answer += find_subarray(dp, zero_cnt);
			}

			zero_cnt = 1;
		}

		if (nums[nums.size() - 1] == 0) {
			answer += find_subarray(dp, zero_cnt);
		}

		return answer;
	}
};