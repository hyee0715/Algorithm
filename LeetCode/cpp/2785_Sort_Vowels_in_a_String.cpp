class Solution {
public:
	bool isVowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O') {
			return true;
		}

		return false;
	}

	string sortVowels(string s) {
		vector<char> v;

		for (int i = 0; i < s.length(); i++) {
			if (isVowel(s[i])) {
				v.push_back(s[i]);
			}
		}

		sort(v.begin(), v.end());

		int idx = 0;

		for (int i = 0; i < s.length(); i++) {
			if (isVowel(s[i])) {
				s[i] = v[idx++];
			}
		}

		return s;
	}
};