class Solution {
	int s_alphabet[26], t_alphabet[26];
public:
	char findTheDifference(string s, string t) {
		char answer;

		memset(s_alphabet, 0, sizeof(s_alphabet));
		memset(t_alphabet, 0, sizeof(t_alphabet));

		for (int i = 0; i < s.size(); i++) {
			s_alphabet[s[i] - 'a']++;
		}

		for (int i = 0; i < t.size(); i++) {
			t_alphabet[t[i] - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			if (s_alphabet[i] != t_alphabet[i]) {
				answer = i + 'a';
			}
		}

		return answer;
	}
};