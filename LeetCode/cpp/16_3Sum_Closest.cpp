class Solution {
public:
	int checkTwoSum(vector<int>& nums, int target, int idx) {
		int curAnswer = 0;
		int gap = INT_MAX;

		int left = idx + 1, right = nums.size() - 1;

		while (left < right) {
			int tempSum = nums[idx] + nums[left] + nums[right];

			if (abs(target - tempSum) < gap) {
				gap = abs(target - tempSum);
				curAnswer = tempSum;
			}

			if (tempSum > target) {
				right--;
			}
			else if (tempSum < target) {
				left++;
			}
			else {
				break;
			}
		}

		return curAnswer;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		int answer = 0;
		int gap = INT_MAX;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			int tempSum = checkTwoSum(nums, target, i);

			if (abs(target - tempSum) < gap) {
				gap = abs(target - tempSum);
				answer = tempSum;
			}
		}

		return answer;
	}
};