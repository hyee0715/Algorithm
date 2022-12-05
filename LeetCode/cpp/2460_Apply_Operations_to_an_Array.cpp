class Solution {
public:
	vector<int> applyOperations(vector<int>& nums) {
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] != nums[i + 1]) {
				continue;
			}

			nums[i] = nums[i] * 2;
			nums[i + 1] = 0;
		}

		int zero_count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				nums.erase(nums.begin() + i);
				zero_count++;
				i--;
			}
		}

		while (zero_count > 0) {
			nums.push_back(0);
			zero_count--;
		}

		return nums;
	}
};