class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			if (m.second > 1)
				return true;
		}

		return false;
	}
};