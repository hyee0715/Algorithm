class Solution {
public:
	int sumOfDigits(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums[0];

		int sum = 0;
		while (n >= 10) {
			sum += n / 10;
			n = n % 10;
		}

		sum += n;

		if (sum % 2 == 0)
			return 1;
		return 0;
	}
};