class Solution {
public:
	string removeOuterParentheses(string s) {
		string answer = "";
		int open = 0, close = 0;

		string temp = "";
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				open++;
				temp += s[i];
			}
			else {
				close++;
				temp += s[i];
			}

			if (open == close) {
				if (open != 1 && close != 1) {
					for (int j = 1; j < temp.size() - 1; j++) {
						answer += temp[j];
					}
				}

				temp = "";
				open = 0;
				close = 0;
			}
		}

		return answer;
	}
};