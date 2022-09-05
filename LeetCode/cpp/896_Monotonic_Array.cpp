class Solution {
public:
	bool isMonotonic(vector<int>& nums) {
		bool isIncreasing;

		if (nums.size() < 2)
			return true;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i - 1] == nums[i]) continue;

			if (nums[i - 1] < nums[i]) {
				isIncreasing = true;
				break;
			}
			else {
				isIncreasing = false;
				break;
			}
		}

		for (int i = 1; i < nums.size(); i++) {
			if (isIncreasing && nums[i - 1] > nums[i]) {
				return false;
			}

			if (!isIncreasing && nums[i - 1] < nums[i]) {
				return false;
			}
		}

		return true;
	}
};