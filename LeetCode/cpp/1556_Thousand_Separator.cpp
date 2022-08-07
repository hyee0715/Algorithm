class Solution {
public:
	string thousandSeparator(int n) {
		string s = to_string(n);
		string answer = "";

		int cnt = 0;

		for (int i = s.size() - 1; i >= 0; i--) {
			if (cnt == 3) {
				cnt = 0;
				answer = '.' + answer;

			}

			cnt++;
			answer = s[i] + answer;

		}

		return answer;
	}
};