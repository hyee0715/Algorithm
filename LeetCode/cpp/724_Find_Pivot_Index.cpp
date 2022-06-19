class Solution {
public:
	int pivotIndex(vector<int>& nums) {
		int left = 0, right = 0;

		for (int i = 1; i < nums.size(); i++)
			right += nums[i];

		if (left == right)
			return 0;

		for (int i = 1; i < nums.size(); i++) {
			left += nums[i - 1];
			right -= nums[i];

			if (left == right)
				return i;
		}

		return -1;
	}
};