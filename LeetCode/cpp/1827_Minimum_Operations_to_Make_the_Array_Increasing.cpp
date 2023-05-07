class Solution {
public:
	int minOperations(vector<int>& nums) {
		int answer = 0;

		int prev = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (prev >= nums[i]) {
				answer += ((prev + 1) - nums[i]);
				prev = prev + 1;
			}
			else {
				prev = nums[i];
			}
		}

		return answer;
	}
};