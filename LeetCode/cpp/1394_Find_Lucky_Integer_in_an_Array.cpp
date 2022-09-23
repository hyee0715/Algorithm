class Solution {
public:
	bool divideArray(vector<int>& nums) {
		if (nums.size() % 2 != 0)
			return false;

		unordered_map<int, int> um;

		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}

		for (auto m : um) {
			if (m.second % 2 != 0)
				return false;
		}

		return true;
	}
};