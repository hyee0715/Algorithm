class Solution {
public:
	int maxAscendingSum(vector<int>& nums) {
		int answer = -1;

		int sum = nums[0];
		int cur = nums[0];

		answer = max(answer, sum);

		for (int i = 1; i < nums.size(); i++) {
			if (cur < nums[i]) {
				cur = nums[i];
				sum += nums[i];
				answer = max(answer, sum);

			}
			else {
				cur = nums[i];
				sum = 0;
				sum += nums[i];
				answer = max(answer, sum);
			}
		}

		return answer;
	}
};