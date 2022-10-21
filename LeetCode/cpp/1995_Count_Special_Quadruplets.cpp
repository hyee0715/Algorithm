class Solution {
public:
	int countQuadruplets(vector<int>& nums) {
		int answer = 0;

		for (int i = 0; i < nums.size() - 3; i++) {
			for (int j = i + 1; j < nums.size() - 2; j++) {
				for (int k = j + 1; k < nums.size() - 1; k++) {
					for (int a = k + 1; a < nums.size(); a++) {
						if (nums[i] + nums[j] + nums[k] == nums[a]) {
							answer++;
						}
					}
				}
			}
		}

		return answer;
	}
};