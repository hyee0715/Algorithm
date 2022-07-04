class Solution {
public:
	int binary_search(vector<int>& nums, int target, int i, int j) {
		int left = j + 1;
		int right = nums.size() - 1;
		int cnt = 0;
		int max_idx = -1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (nums[i] + nums[j] + nums[mid] < target) {
				left = mid + 1;
				max_idx = max(max_idx, mid);
			}
			else {
				right = mid - 1;
			}
		}

		if (max_idx == -1)
			return 0;

		return max_idx - j;
	}

	int twoSumSmaller(vector<int>& nums, int target, int i) {
		int cnt = 0;

		for (int j = i + 1; j < nums.size() - 1; j++) {
			cnt += binary_search(nums, target, i, j);
		}

		return cnt;
	}

	int threeSumSmaller(vector<int>& nums, int target) {
		if (nums.size() <= 1)
			return 0;

		int answer = 0;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++) {
			answer += twoSumSmaller(nums, target, i);
		}

		return answer;
	}
};