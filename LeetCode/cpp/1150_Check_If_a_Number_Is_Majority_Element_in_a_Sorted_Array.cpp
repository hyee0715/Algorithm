class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		int cnt = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target)
				cnt++;
		}

		if (cnt > (nums.size() / 2))
			return true;

		return false;
	}
};