class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, vector<int>> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]].push_back(i);
		}

		for (auto m : um) {
			if (m.second.size() >= 2) {
				for (int i = 1; i < m.second.size(); i++) {
					if (abs(m.second[i] - m.second[i - 1]) <= k) {
						return true;
					}
				}
			}
		}

		return false;
	}
};