class Solution {
public:
	int minimumDifference(vector<int>& nums, int k) {
		if (nums.size() == 1) {
			return 0;
		}

		int answer = 100002;

		sort(nums.begin(), nums.end());

		int left = 0;
		int right = k - 1;

		while (right < nums.size()) {
			answer = min(answer, nums[right] - nums[left]);

			left++;
			right++;
		}

		return answer;
	}
};