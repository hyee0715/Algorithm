class Solution {
public:
	string truncateSentence(string s, int k) {
		string answer;

		int cnt = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ' ') {
				cnt++;

				if (cnt == k) {
					break;
				}
			}

			answer += s[i];
		}

		return answer;
	}
};