class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		vector<int> answer(temperatures.size(), 0);
		stack<pair<int, int>> st;

		for (int i = 0; i < temperatures.size(); i++) {
			if (st.empty() || st.top().first > temperatures[i]) {
				st.push({ temperatures[i], i });
				continue;
			}

			while (!st.empty() && st.top().first < temperatures[i]) {
				pair<int, int> p = st.top();
				st.pop();

				answer[p.second] = i - p.second;
			}

			st.push({ temperatures[i], i });
		}

		while (!st.empty()) {
			pair<int, int> p = st.top();
			st.pop();

			answer[p.second] = 0;
		}

		return answer;
	}
};