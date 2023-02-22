class Solution {
public:
	bool isPalindrome(string s) {
		string rev(s);
		reverse(rev.begin(), rev.end());

		if (s == rev) {
			return true;
		}

		return false;
	}

	void check(string s, int start, vector<vector<string>>& answer, vector<vector<int>>& dp, vector<string>& v) {
		if (start == s.length()) {
			answer.push_back(v);
			return;
		}

		for (int end = start; end < s.length(); end++) {
			if (dp[start][end] == -1) {
				if (isPalindrome(s.substr(start, end - start + 1))) {
					dp[start][end] = 1;
				}
				else {
					dp[start][end] = 0;
				}
			}

			if (dp[start][end] == 1) {
				v.push_back(s.substr(start, end - start + 1));

				check(s, end + 1, answer, dp, v);
				v.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
		vector<vector<string>> answer;
		vector<string> v;

		check(s, 0, answer, dp, v);

		return answer;
	}
};