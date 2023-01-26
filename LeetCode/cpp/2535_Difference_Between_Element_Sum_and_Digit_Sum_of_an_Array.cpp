class Solution {
public:
	int differenceOfSum(vector<int>& nums) {
		int element_sum = 0, digit_sum = 0;

		for (int i = 0; i < nums.size(); i++) {
			element_sum += nums[i];

			string s = to_string(nums[i]);
			for (int j = 0; j < s.length(); j++) {
				digit_sum += (s[j] - '0');
			}
		}

		return abs(element_sum - digit_sum);
	}
};