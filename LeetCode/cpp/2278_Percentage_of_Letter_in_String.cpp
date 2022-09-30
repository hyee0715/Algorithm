class Solution {
public:
	int percentageLetter(string s, char letter) {
		int cnt = 0, answer = 0;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == letter)
				cnt++;
		}

		answer = ((double)cnt / s.size()) * 100;

		return answer;
	}
};