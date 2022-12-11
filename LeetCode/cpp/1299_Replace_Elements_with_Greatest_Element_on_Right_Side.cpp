class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		vector<int> answer;
		set<int> st;

		for (int i = arr.size() - 1; i >= 0; i--) {
			if (st.empty()) {
				st.insert(arr[i]);
				answer.push_back(-1);
				continue;
			}

			answer.push_back(*st.rbegin());
			st.insert(arr[i]);
		}

		reverse(answer.begin(), answer.end());
		return answer;
	}
};