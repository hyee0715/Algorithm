class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		int min1 = nums[0];
		int min2 = nums[1];

		int max1 = nums[nums.size() - 1];
		int max2 = nums[nums.size() - 2];
		int max3 = nums[nums.size() - 3];

		if (min1 < 0 && min2 < 0) {
			answer = max(min1 * min2 * max1, max1 * max2 * max3);
			return answer;
		}

		answer = max1 * max2 * max3;
		return answer;
	}
};