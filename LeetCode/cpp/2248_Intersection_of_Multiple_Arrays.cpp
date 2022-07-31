class Solution {
public:
	vector<int> intersection(vector<vector<int>>& nums) {
		unordered_map<int, int> um;
		vector<int> answer;

		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				um[nums[i][j]]++;
			}
		}

		for (auto m : um) {
			if (m.second == nums.size()) {
				answer.push_back(m.first);
			}
		}

		sort(answer.begin(), answer.end());
		return answer;
	}
};