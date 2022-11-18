﻿class Solution {
public:
	int maximumDifference(vector<int>& nums) {
		int answer = -1;

		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] >= nums[j]) {
					continue;
				}

				answer = max(answer, nums[j] - nums[i]);
			}
		}

		return answer;
	}
};