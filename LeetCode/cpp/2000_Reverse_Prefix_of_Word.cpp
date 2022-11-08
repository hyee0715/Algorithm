class Solution {
public:
	string reversePrefix(string word, char ch) {
		string s;
		int idx;

		for (int i = 0; i < word.size(); i++) {
			if (word[i] == ch) {
				s += word[i];
				idx = i + 1;
				break;
			}

			s += word[i];
		}

		if (s == word) {
			if (idx == word.size()) {
				reverse(s.begin(), s.end());
			}

			return s;
		}

		reverse(s.begin(), s.end());

		if (idx < word.size()) {
			for (int i = idx; i < word.size(); i++) {
				s += word[i];
			}
		}

		return s;
	}
};