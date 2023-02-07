class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int answer = INT_MIN;
		int max_num = nums[0];
		int min_num = nums[0];

		answer = max(answer, max(max_num, min_num));

		for (int i = 1; i < nums.size(); i++) {
			int temp_max_num = max_num;

			max_num = max(nums[i], max(max_num * nums[i], min_num * nums[i]));
			min_num = min(nums[i], min(min_num * nums[i], temp_max_num * nums[i]));

			answer = max(answer, max(max_num, min_num));
		}

		return answer;
	}
};