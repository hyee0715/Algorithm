class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int num = nums[0];
		int cnt = 1;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == num) {
				cnt++;

				if (cnt > 2) {
					nums.erase(nums.begin() + i);
					i--;
				}
				continue;
			}

			cnt = 1;
			num = nums[i];
		}

		return nums.size();
	}
};