class Solution {
public:
	string minRemoveToMakeValid(string s) {
		string answer;
		int check = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '(' && s[i] != ')') {
				answer += s[i];
				continue;
			}

			if (s[i] == '(') {
				check++;
				answer += s[i];
				continue;
			}

			if (check > 0) { //s[i] == ')'
				answer += s[i];
				check--;
			}
		}

		int idx = answer.length() - 1;

		while (check > 0) {
			if (idx < 0) {
				break;
			}

			if (answer[idx] == '(') {
				answer.erase(answer.begin() + idx);
				check--;
			}

			idx--;
		}

		return answer;
	}
};