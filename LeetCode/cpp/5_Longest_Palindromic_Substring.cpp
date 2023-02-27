class Solution {
public:
	string longestPalindrome(string s) {
		vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
		int maxLength = -1;
		string answer;

		for (int j = 0; j < s.length(); j++) {
			for (int i = 0; i <= j; i++) {
				if (j - i < 2) {
					if (s[i] == s[j]) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = false;
					}
				}
				else {
					if (s[i] == s[j] && dp[i + 1][j - 1] == true) {
						dp[i][j] = true;
					}
					else {
						dp[i][j] = false;
					}
				}

				if (dp[i][j] == true && maxLength < j - i + 1) {
					maxLength = j - i + 1;
					answer = s.substr(i, j - i + 1);
				}
			}
		}

		return answer;
	}
};