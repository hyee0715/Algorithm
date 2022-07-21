class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int cnt = 0, answer = -1;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				cnt++;
				answer = max(answer, cnt);
			}
			else {
				answer = max(answer, cnt);
				cnt = 0;
			}
		}

		return answer;
	}
};