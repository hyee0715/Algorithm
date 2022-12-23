class Solution {
public:
	int findMaxK(vector<int>& nums) {
		int answer = -1;
		set<int> st;

		for (int n : nums) {
			st.insert(n);
		}

		sort(nums.begin(), nums.end());

		for (int i = nums.size() - 1; i >= 0; i--) {
			int negative = nums[i] * -1;

			if (st.find(negative) != st.end()) {
				answer = nums[i];
				break;
			}
		}

		return answer;
	}
};