class Solution {
public:
	int maximizeSum(vector<int>& nums, int k) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		answer = nums[nums.size() - 1] * k;
		answer += (k * (k - 1)) / 2;

		return answer;
	}
};