class Solution {
public:
	int countDigits(int num) {
		int answer = 0;
		string s = to_string(num);

		for (int i = 0; i < s.length(); i++) {
			if (num % (s[i] - '0') == 0) {
				answer++;
			}
		}

		return answer;
	}
};