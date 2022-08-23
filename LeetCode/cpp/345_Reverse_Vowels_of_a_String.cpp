class Solution {
public:
	string reverseVowels(string s) {
		string t;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') {
				t += s[i];
			}
		}

		reverse(t.begin(), t.end());

		int idx = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o' || s[i] == 'A' || s[i] == 'I' || s[i] == 'U' || s[i] == 'E' || s[i] == 'O') {
				s[i] = t[idx++];
			}
		}

		return s;
	}
};