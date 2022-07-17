class Solution {
public:
	bool isPalindrome(int x) {
		string s = to_string(x);
		string rev_s = s;

		reverse(rev_s.begin(), rev_s.end());

		if (s == rev_s)
			return true;
		return false;
	}
};