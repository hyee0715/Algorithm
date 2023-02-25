class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		vector<int> sum;
		int answer = INT_MAX;

		sum.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			sum.push_back(sum[i - 1] + nums[i]);
		}

		for (int i = 0; i < sum.size(); i++) {
			if (sum[i] >= target) {
				answer = min(answer, i + 1);
				break;
			}
		}

		if (answer == INT_MAX) {
			return 0;
		}

		int left = 0, right = 1;

		while (right < sum.size() && left < sum.size() - 1) {
			int cal = sum[right] - sum[left];

			if (cal >= target) {
				answer = min(answer, right - left);
				left++;
			}
			else {
				right++;
			}
		}

		return answer;
	}
};