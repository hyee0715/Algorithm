class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int answer = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i += 2) {
			answer += min(nums[i], nums[i + 1]);
		}

		return answer;
	}
};