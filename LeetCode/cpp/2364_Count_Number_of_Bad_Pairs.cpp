class Solution {
public:
	long long countBadPairs(vector<int>& nums) {
		long long answer = 0;
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i] - i]++;
			answer += i + 1 - um[nums[i] - i];
		}

		return answer;
	}
};