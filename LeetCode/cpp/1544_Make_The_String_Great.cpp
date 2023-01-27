class Solution {
public:
	string makeGood(string s) {
		if (s.length() == 1) {
			return s;
		}

		stack<char> st;

		for (int i = 0; i < s.length(); i++) {
			if (st.empty()) {
				st.push(s[i]);
			}
			else {
				if (s[i] >= 65 && s[i] <= 90) {
					if (st.top() == (s[i] + 32)) {
						st.pop();
					}
					else {
						st.push(s[i]);
					}
				}
				else if (s[i] >= 97 && s[i] <= 122) {
					if (st.top() == (s[i] - 32)) {
						st.pop();
					}
					else {
						st.push(s[i]);
					}
				}
				else {
					st.push(s[i]);
				}
			}
		}

		string answer;
		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}

		reverse(answer.begin(), answer.end());

		return answer;
	}
};