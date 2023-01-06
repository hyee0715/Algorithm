class Solution {
public:
	bool is_palindrome(string s) {
		string rev_s(s);
		reverse(rev_s.begin(), rev_s.end());

		if (s == rev_s) {
			return true;
		}

		return false;
	}

	int removePalindromeSub(string s) {
		if (is_palindrome(s)) {
			return 1;
		}

		return 2;
	}
};