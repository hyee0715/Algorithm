class Solution {
public:
	int minMoves(vector<int>& nums) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		for (int i = 1; i < nums.size(); i++) {
			answer += (nums[i] - nums[0]);
		}

		return answer;
	}
};