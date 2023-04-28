class Solution {
public:
	int search(vector<int>& nums, int target) {
		int answer = -1;
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				answer = mid;
				break;
			}

			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}

			if (nums[mid] <= nums[right]) {
				if (nums[mid] <= target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		return answer;
	}
};