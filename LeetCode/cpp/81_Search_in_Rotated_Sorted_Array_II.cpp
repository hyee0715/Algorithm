class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 1) {
			if (nums[0] == target) {
				return true;
			}
			return false;
		}

		int left = 0, right = nums.size() - 1;

		while (left <= right) {
			while (left < right && nums[left] == nums[left + 1]) {
				left++;
			}

			while (left < right && nums[right - 1] == nums[right]) {
				right--;
			}

			int mid = left + (right - left) / 2;

			if (nums[mid] == target) {
				return true;
			}

			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}
			}
			else {
				if (nums[mid] < target && target <= nums[right]) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
		}

		return false;
	}
};