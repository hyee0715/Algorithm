class Solution {
public:
	int addDigits(int num) {
		int cnt = 0;
		string s = to_string(num);

		while (s.length() > 1) {
			cnt = 0;
			for (int i = 0; i < s.length(); i++) {
				cnt += (s[i] - '0');
			}

			s = to_string(cnt);
		}

		int answer = s[0] - '0';
		return answer;
	}
};