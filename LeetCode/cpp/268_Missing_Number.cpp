class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int n = 0, answer;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (n != nums[i]) {
				answer = n;
				break;
			}
			else {
				n++;
			}
		}

		return answer;
	}
};