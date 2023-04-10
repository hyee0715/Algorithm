class Solution {
public:
	int findFinalValue(vector<int>& nums, int original) {
		set<int> st;

		for (int i = 0; i < nums.size(); i++) {
			st.insert(nums[i]);
		}

		while (1) {
			if (st.find(original) == st.end()) {
				break;
			}

			original = original * 2;
		}

		return original;
	}
};