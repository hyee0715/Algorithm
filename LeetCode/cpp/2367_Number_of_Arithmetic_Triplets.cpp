class Solution {
public:
	int arithmeticTriplets(vector<int>& nums, int diff) {
		int answer = 0;

		for (int i = 0; i < nums.size() - 2; i++) {
			for (int j = i + 1; j < nums.size() - 1; j++) {
				for (int k = j + 1; k < nums.size(); k++) {
					if (nums[j] - nums[i] == nums[k] - nums[j] && nums[j] - nums[i] == diff) {
						answer++;
					}
				}
			}
		}

		return answer;
	}
};