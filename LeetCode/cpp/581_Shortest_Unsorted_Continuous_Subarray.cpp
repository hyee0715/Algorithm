class Solution {
public:
	int findUnsortedSubarray(vector<int>& nums) {
		if (nums.size() == 1) {
			return 0;
		}

		vector<int> v(nums.begin(), nums.end());
		sort(v.begin(), v.end());

		int left = 0, right = nums.size() - 1;

		for (int i = 0; i < v.size(); i++) {
			if (v[i] != nums[i]) {
				left = i;
				break;
			}
		}

		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] != nums[i]) {
				right = i;
				break;
			}
		}

		if (left == 0 && right == nums.size() - 1 && v[left] != nums[left] && v[right] != nums[right]) {
			return nums.size();
		}

		if (left > right || (left == 0 && right == nums.size() - 1)) {
			return 0;
		}

		return right - left + 1;
	}
};