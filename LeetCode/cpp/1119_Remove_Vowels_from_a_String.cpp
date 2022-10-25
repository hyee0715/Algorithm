class Solution {
public:
	string removeVowels(string s) {
		string answer;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != 'a' && s[i] != 'i' && s[i] != 'u' && s[i] != 'e' && s[i] != 'o') {
				answer += s[i];
			}
		}

		return answer;
	}
};