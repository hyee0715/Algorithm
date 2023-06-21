class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string answer;
		stack<char> st;

		int cnt = 0;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '-') {
				continue;
			}

			st.push(toupper(s[i]));
			cnt++;

			if (i != 0 && cnt == k) {
				cnt = 0;
				st.push('-');
			}
		}

		if (!st.empty() && st.top() == '-') {
			st.pop();
		}

		while (!st.empty()) {
			answer += st.top();
			st.pop();
		}

		return answer;
	}
};