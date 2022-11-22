class Solution {
public:
	bool findSubarrays(vector<int>& nums) {
		set<int> st;

		for (int i = 0; i < nums.size() - 1; i++) {
			int sum = 0;
			sum += nums[i];
			sum += nums[i + 1];

			if (st.find(sum) != st.end()) {
				return true;
			}

			if (st.find(sum) == st.end()) {
				st.insert(sum);
			}
		}

		return false;
	}
};