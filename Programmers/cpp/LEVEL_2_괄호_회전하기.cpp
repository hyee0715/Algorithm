#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

bool check(queue<char> q) {
	stack<char> st;

	while (!q.empty()) {
		char c = q.front();
		q.pop();

		if (c == '[' || c == '(' || c == '{') {
			st.push(c);
			continue;
		}

		if (!st.empty()) {
			if ((c == ']' && st.top() == '[') || (c == ')' && st.top() == '(') || (c == '}' && st.top() == '{')) {
				st.pop();
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	if (!st.empty()) {
		return false;
	}

	return true;
}

int solution(string s) {
	int answer = 0;

	queue<char> q;
	for (int i = 0; i < s.length(); i++) {
		q.push(s[i]);
	}

	if (check(q)) {
		answer++;
	}

	for (int i = 0; i < s.length() - 1; i++) {
		char c = q.front();
		q.pop();
		q.push(c);

		if (check(q)) {
			answer++;
		}
	}

	return answer;
}