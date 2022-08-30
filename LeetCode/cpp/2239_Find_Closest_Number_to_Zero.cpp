class Solution {
public:
	int findClosestNumber(vector<int>& nums) {
		int answer = -100001;
		int min_num = 100001;

		for (int i = 0; i < nums.size(); i++) {
			if (abs(nums[i]) == min_num) {
				min_num = abs(nums[i]);
				answer = max(answer, nums[i]);
			}
			else if (abs(nums[i]) < min_num) {
				min_num = abs(nums[i]);
				answer = nums[i];
			}
		}

		return answer;
	}
};