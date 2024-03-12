class Solution {
public:
	int countKeyChanges(string s) {
		int answer = 0;

		for (int i = 0; i < s.length(); i++) {
			s[i] = toupper(s[i]);
		}

		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] != s[i + 1]) {
				answer++;
			}
		}

		return answer;
	}
};