class Solution {
public:
	bool increasingTriplet(vector<int>& nums) {
		int one = 0x7fffffff, two = 0x7fffffff;;

		for (int i = 0; i < nums.size(); i++) {
			if (one >= nums[i]) {
				one = nums[i];
			}
			else if (two >= nums[i]) {
				two = nums[i];
			}
			else {
				return true;
			}
		}

		return false;
	}
};