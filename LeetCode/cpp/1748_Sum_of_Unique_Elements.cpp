class Solution {
public:
	int sumOfUnique(vector<int>& nums) {
		unordered_map<int, int> um;
		int answer = 0;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			if (m.second == 1) {
				answer += m.first;
			}
		}

		return answer;
	}
};