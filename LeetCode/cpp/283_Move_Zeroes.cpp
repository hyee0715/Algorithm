class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int original_size = nums.size();

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		if (nums.size() < original_size) {
			int add_zero = original_size - nums.size();

			while (add_zero--) {
				nums.push_back(0);
			}
		}
	}
};