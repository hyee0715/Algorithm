class Solution {
public:
	int maxScore(string s) {
		int answer = -1;

		int cnt = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			int left = 0, right = 0;

			for (int j = 0; j < cnt; j++) {
				if (s[j] == '0') {
					left++;
				}
			}

			for (int j = cnt; j < s.size(); j++) {
				if (s[j] == '1') {
					right++;
				}
			}

			cnt++;
			int score = left + right;
			answer = max(answer, score);
		}

		return answer;
	}
};