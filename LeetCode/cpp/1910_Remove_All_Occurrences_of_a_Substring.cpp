class Solution {
public:
	bool isSame(string s, string part) {
		if (s == part) {
			return true;
		}

		return false;
	}

	string removeOccurrences(string s, string part) {
		string answer;
		stack<char> st;

		for (int i = 0; i < s.length(); i++) {
			st.push(s[i]);

			if (st.size() >= part.length() && st.top() == part[part.length() - 1]) {
				string temp;

				for (int j = 0; j < part.length(); j++) {
					temp += st.top();
					st.pop();
				}

				reverse(temp.begin(), temp.end());

				if (!isSame(temp, part)) {
					for (int j = 0; j < temp.length(); j++) {
						st.push(temp[j]);
					}
				}
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