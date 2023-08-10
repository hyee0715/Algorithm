class Solution {
public:
	int minPairSum(vector<int>& nums) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() / 2; i++) {
			answer = max(answer, nums[i] + nums[nums.size() - 1 - i]);
		}

		return answer;
	}
};