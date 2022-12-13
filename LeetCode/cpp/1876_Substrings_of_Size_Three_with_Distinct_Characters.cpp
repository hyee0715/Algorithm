class Solution {
public:
	int countGoodSubstrings(string s) {
		set<char> st;
		int answer = 0;
		bool flag;

		if (s.size() < 3) {
			return 0;
		}

		for (int i = 0; i < s.size() - 2; i++) {
			st.clear();
			flag = false;

			for (int j = 0; j < 3; j++) {
				if (st.find(s[i + j]) != st.end()) {
					flag = true;
				}
				else {
					st.insert(s[i + j]);
				}
			}

			if (!flag) {
				answer++;
			}
		}

		return answer;
	}
};