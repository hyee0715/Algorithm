class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> answer(2);
		answer[0] = 100001;
		answer[1] = -1;

		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (nums[mid] == target) {
				answer[0] = min(answer[0], mid);
				answer[1] = max(answer[1], mid);

				right = mid - 1;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		left = 0;
		right = nums.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (nums[mid] == target) {
				answer[0] = min(answer[0], mid);
				answer[1] = max(answer[1], mid);

				left = mid + 1;
			}
			else if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		if (answer[0] == 100001) {
			answer[0] = -1;
		}

		return answer;
	}
};