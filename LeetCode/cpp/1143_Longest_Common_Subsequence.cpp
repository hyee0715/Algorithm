class Solution {
public:
	int check(string& text1, string& text2, int p1, int p2, vector<vector<int>>& memo) {
		if (p1 == text1.length() || p2 == text2.length()) {
			return 0;
		}

		if (memo[p1][p2] != -1) {
			return memo[p1][p2];
		}

		if (text1[p1] == text2[p2]) {
			return memo[p1][p2] = check(text1, text2, p1 + 1, p2 + 1, memo) + 1;
		}
		else {
			return memo[p1][p2] = max(check(text1, text2, p1 + 1, p2, memo), check(text1, text2, p1, p2 + 1, memo));
		}

		return memo[p1][p2];
	}

	int longestCommonSubsequence(string text1, string text2) {
		vector<vector<int>> memo(text1.length(), vector<int>(text2.length(), -1));

		return check(text1, text2, 0, 0, memo);
	}
};