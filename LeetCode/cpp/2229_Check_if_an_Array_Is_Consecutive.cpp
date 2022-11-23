class Solution {
public:
	bool isConsecutive(vector<int>& nums) {
		set<int> st;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			st.insert(nums[i]);
		}


		int start = nums[0];
		int end = nums[0] + nums.size() - 1;

		for (int i = start; i <= end; i++) {
			if (st.find(i) == st.end()) {
				return false;
			}
		}

		return true;
	}
};