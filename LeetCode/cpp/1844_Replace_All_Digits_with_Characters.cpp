class Solution {
public:
	string replaceDigits(string s) {
		string answer;

		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 0) {
				answer += s[i];
				continue;
			}

			char c = ((s[i - 1] - 'a') + (s[i] - '0')) + 'a';
			answer += c;
		}

		return answer;
	}
};