class Solution {
public:
	void twoSum(vector<int>& nums, int idx, vector<vector<int>>& answer) {
		int left = idx + 1;
		int right = nums.size() - 1;

		while (left < right) {
			if (nums[idx] + nums[left] + nums[right] == 0) {
				vector<int> v;
				v.push_back(nums[idx]);
				v.push_back(nums[left]);
				v.push_back(nums[right]);

				answer.push_back(v);

				left++;
				right--;

				while (left < right && nums[right] == nums[right + 1]) {
					right--;
				}
			}
			else if (nums[idx] + nums[left] + nums[right] < 0) {
				left++;
			}
			else {
				right--;

				while (left < right && right < nums.size() - 1 && nums[right] == nums[right + 1]) {
					right--;
				}
			}
		}
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i == 0 || nums[i - 1] != nums[i]) {
				twoSum(nums, i, answer);
			}
		}

		return answer;
	}
};