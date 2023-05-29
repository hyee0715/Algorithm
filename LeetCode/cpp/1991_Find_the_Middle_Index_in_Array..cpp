class Solution {
public:
	int findMiddleIndex(vector<int>& nums) {
		int answer = -1;

		int right = 0;
		for (int i = 1; i < nums.size(); i++) {
			right += nums[i];
		}

		int left = 0;
		int idx = 0;
		while (idx < nums.size()) {
			if (left == right) {
				answer = idx;
				break;
			}

			left += nums[idx];
			idx++;

			if (idx == nums.size()) {
				break;
			}

			right -= nums[idx];
		}

		return answer;
	}
};