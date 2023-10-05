class Solution {
public:
	int maxProductDifference(vector<int>& nums) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		answer = (nums[nums.size() - 1] * nums[nums.size() - 2]) - (nums[0] * nums[1]);

		return answer;
	}
};