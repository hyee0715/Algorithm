class Solution {
public:
	int countLetters(string s) {
		int answer = 1, cnt = 1;

		for (int i = 1; i < s.length(); i++) {
			if (s[i - 1] == s[i]) {
				cnt++;
			}
			else {
				cnt = 1;
			}

			answer += cnt;
		}

		return answer;
	}
};