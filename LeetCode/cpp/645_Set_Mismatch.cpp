class Solution {
public:
	vector<int> findErrorNums(vector<int>& nums) {
		vector<int> answer;
		set<int> st;

		for (int i = 0; i < nums.size(); i++) {
			if (st.find(nums[i]) == st.end()) {
				st.insert(nums[i]);
				continue;
			}

			if (st.find(nums[i]) != st.end()) {
				answer.push_back(nums[i]);
			}
		}

		for (int i = 1; i <= nums.size(); i++) {
			if (st.find(i) == st.end()) {
				answer.push_back(i);
			}
		}

		return answer;
	}
};