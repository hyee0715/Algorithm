class Solution {
public:
	int countDistinctIntegers(vector<int>& nums) {
		set<int> st;

		for (int n : nums) {
			st.insert(n);

			string s = to_string(n);

			reverse(s.begin(), s.end());

			st.insert(stoi(s));
		}

		return st.size();
	}
};