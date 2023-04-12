class Solution {
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		if (trust.empty()) {
			if (n == 1) {
				return 1;
			}
			return -1;
		}

		int answer = -1;
		unordered_map<int, set<int>> um;

		for (vector<int> t : trust) {
			um[t[0]].insert(t[1]);
		}

		for (int i = 1; i <= n; i++) {
			if (um.count(i) == 0) {
				for (auto m : um) {
					set<int> st = m.second;
					if (st.find(i) == st.end()) {
						return -1;
					}
				}

				answer = i;
			}
		}

		return answer;
	}
};