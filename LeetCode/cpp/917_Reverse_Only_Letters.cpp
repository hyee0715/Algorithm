class Solution {
public:
	string reverseOnlyLetters(string s) {
		string reverse_str;

		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				reverse_str += s[i];
			}
		}

		reverse(reverse_str.begin(), reverse_str.end());

		int rev_idx = 0;

		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				s[i] = reverse_str[rev_idx++];
			}
		}

		return s;
	}
};