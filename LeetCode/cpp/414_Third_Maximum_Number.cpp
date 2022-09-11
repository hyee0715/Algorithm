class Solution {
public:
	int thirdMax(vector<int>& nums) {
		sort(nums.begin(), nums.end(), greater<>());

		int cnt = 1, answer;
		int cur_max = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] < cur_max) {
				cur_max = nums[i];
				cnt++;
			}

			if (cnt == 3) {
				answer = cur_max;
				break;
			}
		}

		if (cnt < 3) {
			answer = nums[0];
		}

		return answer;
	}
};