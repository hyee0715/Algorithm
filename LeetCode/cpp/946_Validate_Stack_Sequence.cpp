class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int popIdx = 0;
		stack<int> st;

		for (int i = 0; i < pushed.size(); i++) {
			while (!st.empty() && st.top() == popped[popIdx]) {
				st.pop();
				popIdx++;
			}

			st.push(pushed[i]);
		}

		while (!st.empty() && st.top() == popped[popIdx]) {
			st.pop();
			popIdx++;
		}

		if (st.empty()) {
			return true;
		}

		return false;
	}
};