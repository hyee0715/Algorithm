class Solution {
public:
	int sumOfSquares(vector<int>& nums) {
		int answer = 0;
		int num = nums.size();

		for (int i = 1; i <= nums.size(); i++) {
			if (num % i == 0) {
				answer += nums[i - 1] * nums[i - 1];
			}
		}

		return answer;
	}
};