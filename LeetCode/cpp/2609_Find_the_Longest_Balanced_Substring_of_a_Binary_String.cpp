class Solution {
public:
	int findTheLongestBalancedSubstring(string s) {
		int answer = 0;
		int zero = 0;
		int one = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '0' && one > 0) {
				zero = 0;
				one = 0;
			}

			if (s[i] == '0') {
				zero++;
			}
			else {
				one++;
			}

			if (zero == one) {
				answer = max(answer, zero + one);
			}
			else {
				answer = max(answer, min(zero, one) * 2);
			}
		}

		return answer;
	}
};