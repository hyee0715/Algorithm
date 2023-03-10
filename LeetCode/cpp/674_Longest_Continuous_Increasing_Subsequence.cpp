class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		int answer = 1;

		int cnt = 1;
		int minNum = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			if (minNum < nums[i]) {
				cnt++;
				answer = max(answer, cnt);
				minNum = nums[i];
			}
			else {
				cnt = 1;
				minNum = nums[i];
			}
		}

		return answer;
	}
};