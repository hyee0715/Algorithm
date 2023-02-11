#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	int idx = 0;
	stack<int> st;

	for (int i = 1; i <= order.size(); i++) {
		if (i != order[idx]) {
			if (st.empty() || st.top() != order[idx]) {
				st.push(i);
				continue;
			}

			while (!st.empty() && st.top() == order[idx]) {
				answer++;
				idx++;
				st.pop();
			}
			continue;
		}

		answer++;
		idx++;

		while (!st.empty() && st.top() == order[idx]) {
			answer++;
			idx++;
			st.pop();
		}
	}

	return answer;
}