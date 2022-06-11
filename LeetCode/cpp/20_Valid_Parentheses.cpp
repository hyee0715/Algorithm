class Solution {
	stack<char> st;
public:
	bool isValid(string s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				st.push(s[i]);
			}
			else if (s[i] == ')') {
				if (st.empty()) {
					return false;
				}
				else {
					if (st.top() == '(') {
						st.pop();
					}
					else {
						return false;
					}
				}
			}
			else if (s[i] == ']') {
				if (st.empty()) {
					return false;
				}
				else {
					if (st.top() == '[') {
						st.pop();
					}
					else {
						return false;
					}
				}
			}
			else if (s[i] == '}') {
				if (st.empty()) {
					return false;
				}
				else {
					if (st.top() == '{') {
						st.pop();
					}
					else {
						return false;
					}
				}
			}
		}

		if (!st.empty())
			return false;

		return true;
	}
};