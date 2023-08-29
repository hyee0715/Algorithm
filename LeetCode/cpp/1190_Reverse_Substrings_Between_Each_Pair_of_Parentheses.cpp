class Solution {
public:
	string reverseParentheses(string s) {
		string answer;
		stack<char> st;

		string temp;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ')') {
				while (!st.empty() && st.top() != '(') {
					temp += st.top();
					st.pop();
				}
				st.pop();

				for (int j = 0; j < temp.length(); j++) {
					st.push(temp[j]);
				}
				temp.clear();
			}
			else {
				st.push(s[i]);
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