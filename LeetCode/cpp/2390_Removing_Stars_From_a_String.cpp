class Solution {
public:
	string removeStars(string s) {
		string answer;
		stack<char> st;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '*') {
				st.push(s[i]);
				continue;
			}

			if (!st.empty()) {
				st.pop();
			}
		}

		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}

		reverse(answer.begin(), answer.end());
		return answer;
	}
};