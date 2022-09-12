class Solution {
public:
	int smallestEqual(vector<int>& nums) {
		int answer = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (i % 10 == nums[i] % 10) {
				answer = i;
				break;
			}
		}

		return answer;
	}
};