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

			if (0 < mid && nums[mid - 1] > nums[mid]) {
				if (nums[0] <= target && target <= nums[mid - 1]) {
					right = mid - 1;
					continue;
				}

				if (nums[mid] <= target && target <= nums[nums.size() - 1]) {
					left = mid + 1;
					continue;
				}
			}

			if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1]) {
				if (nums[0] <= target && target <= nums[mid]) {
					right = mid - 1;
					continue;
				}

				if (nums[mid + 1] <= target && target <= nums[nums.size() - 1]) {
					left = mid + 1;
					continue;
				}
			}

			if (nums[left] <= nums[mid]) {
				if (nums[left] <= target && target <= nums[mid]) {
					right = mid - 1;
				}
				else {
					left = mid + 1;
				}

				continue;
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