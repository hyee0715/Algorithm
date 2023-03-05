class Solution {
public:
	bool check(string s, set<string>& st, vector<int>& memo, int start) {
		if (start == s.length()) {
			return true;
		}

		if (memo[start] != -1) {
			return memo[start];
		}

		for (int end = start + 1; end <= s.length(); end++) {
			string str = s.substr(start, end - start);

			if (st.find(str) != st.end()) {
				memo[end] = check(s, st, memo, end);

				if (memo[end] == 1) {
					return memo[end];
				}
			}
		}

		return false;
	}

	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> st(wordDict.begin(), wordDict.end());
		vector<int> memo(s.length() + 1, -1);

		return check(s, st, memo, 0);
	}
};