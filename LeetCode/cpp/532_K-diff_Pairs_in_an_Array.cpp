class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		set<int> st;
		int answer = 0;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); i++) {
			if (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
				if (i < nums.size() - 2 && nums[i + 1] == nums[i + 2]) {
					continue;
				}

				if (k == 0 && st.find(nums[i]) == st.end()) {
					answer++;
				}

				continue;
			}

			if (st.find(nums[i]) != st.end()) {
				answer++;
			}

			st.insert(k + nums[i]);
		}

		return answer;
	}
};