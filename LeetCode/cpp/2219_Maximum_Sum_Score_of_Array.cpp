class Solution {
public:
	long long maximumSumScore(vector<int>& nums) {
		long long answer = -100001;

		long long firstSum = 0;
		long long lastSum = 0;

		for (int n : nums) {
			lastSum += n;
		}

		for (int i = 0; i < nums.size(); i++) {
			firstSum += nums[i];

			answer = max(answer, max(firstSum, lastSum));

			lastSum -= nums[i];
		}

		return answer;
	}
};