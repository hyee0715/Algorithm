class Solution {
public:
	int minimumOperations(vector<int>& nums) {
		int answer = 0;

		int left = 0;
		int right = nums.size() - 1;

		long long right_sum = nums[right];
		long long left_sum = nums[left];

		while (left < right) {
			if (left_sum > right_sum) {
				answer++;
				right--;
				right_sum += nums[right];
			}
			else if (left_sum < right_sum) {
				answer++;
				left++;
				left_sum += nums[left];
			}
			else {
				left++;
				right--;

				left_sum = nums[left];
				right_sum = nums[right];
			}
		}

		return answer;
	}
};