class Solution {
public:
	string removeKdigits(string num, int k) {
		stack<int> st;

		for (int i = 0; i < num.length(); i++) {
			while (!st.empty() && k > 0 && num[i] - '0' < st.top()) {
				st.pop();
				k--;
				continue;
			}

			st.push(num[i] - '0');
		}

		while (k > 0) {
			st.pop();
			k--;
		}

		string answer;
		while (!st.empty()) {
			answer += st.top() + '0';
			st.pop();
		}

		reverse(answer.begin(), answer.end());

		for (int i = 0; i < answer.length(); i++) {
			if (answer[0] == '0') {
				if (i != 0) {
					break;
				}

				answer.erase(answer.begin());
				i--;
			}
		}

		if (answer.empty()) {
			return "0";
		}

		return answer;
	}
};