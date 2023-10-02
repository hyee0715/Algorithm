class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> answer(nums.size());

		vector<int> left(nums.size()), right(nums.size());

		left[0] = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			left[i] = left[i - 1] * nums[i];
		}

		right[nums.size() - 1] = nums[nums.size() - 1];

		for (int i = nums.size() - 2; i >= 0; i--) {
			right[i] = right[i + 1] * nums[i];
		}

		for (int i = 0; i < answer.size(); i++) {
			int leftNum = 1;
			int rightNum = 1;

			if (i == 0) {
				rightNum = right[i + 1];
			}
			else if (i == answer.size() - 1) {
				leftNum = left[i - 1];
			}
			else {
				rightNum = right[i + 1];
				leftNum = left[i - 1];
			}

			answer[i] = leftNum * rightNum;
		}

		return answer;
	}
};