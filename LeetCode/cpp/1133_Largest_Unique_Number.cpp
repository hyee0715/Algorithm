class Solution {
public:
	int largestUniqueNumber(vector<int>& nums) {
		int answer = -1;
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			if (m.second == 1) {
				answer = max(answer, m.first);
			}
		}

		return answer;
	}
};