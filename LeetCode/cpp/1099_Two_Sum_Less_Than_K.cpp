class Solution {
public:
	int twoSumLessThanK(vector<int>& nums, int k) {
		int answer = -1;

		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] < k) {
					answer = max(answer, nums[i] + nums[j]);
				}
			}
		}

		return answer;
	}
};