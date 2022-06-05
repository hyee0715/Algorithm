class Solution {
public:
	int maximumGap(vector<int>& nums) {
		int max_gap = 0;

		if (nums.size() < 2) {
			return 0;
		}

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i + 1] - nums[i] > max_gap) {
				max_gap = nums[i + 1] - nums[i];
			}
		}

		return max_gap;
	}
};