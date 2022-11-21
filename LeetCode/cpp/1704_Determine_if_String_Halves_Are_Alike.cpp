class Solution {
public:
	bool halvesAreAlike(string s) {
		int mid = s.size() / 2;
		int vowels_cnt_1 = 0, vowels_cnt_2 = 0;

		for (int i = 0; i < mid; i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'A' || s[i] == 'E' || s[i] == 'U' || s[i] == 'O' || s[i] == 'I') {
				vowels_cnt_1++;
			}
		}

		for (int i = mid; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'A' || s[i] == 'E' || s[i] == 'U' || s[i] == 'O' || s[i] == 'I') {
				vowels_cnt_2++;
			}
		}

		if (vowels_cnt_1 == vowels_cnt_2) {
			return true;
		}

		return false;
	}
};