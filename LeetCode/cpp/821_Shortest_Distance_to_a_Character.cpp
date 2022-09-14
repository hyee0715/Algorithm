class Solution {
public:
	vector<int> shortestToChar(string s, char c) {
		vector<int> answer(s.size(), 10001);
		int cnt = 0;
		bool flag = false;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == c) {
				flag = true;
				cnt = 0;
				answer[i] = cnt;
			}

			if (s[i] != c && flag) {
				cnt++;
				answer[i] = cnt;
			}
		}

		cnt = 0;
		flag = false;

		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == c) {
				flag = true;
				cnt = 0;
				answer[i] = cnt;
			}

			if (s[i] != c && flag) {
				cnt++;
				answer[i] = min(answer[i], cnt);
			}
		}

		return answer;
	}
};