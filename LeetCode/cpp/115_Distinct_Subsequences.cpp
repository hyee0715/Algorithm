class Solution {
public:
	int check(string s, string t, int p1, int p2, vector<vector<int>>& memo) {
		if (p2 == t.length()) {
			return 1;
		}

		if (p1 == s.length()) {
			return 0;
		}

		if (memo[p1][p2] != -1) {
			return memo[p1][p2];
		}

		if (s[p1] == t[p2]) {
			memo[p1][p2] = check(s, t, p1 + 1, p2 + 1, memo) + check(s, t, p1 + 1, p2, memo);
		}
		else {
			memo[p1][p2] = check(s, t, p1 + 1, p2, memo);
		}

		return memo[p1][p2];
	}

	int numDistinct(string s, string t) {
		vector<vector<int>> memo(s.length(), vector<int>(t.length(), -1));

		return check(s, t, 0, 0, memo);
	}
};