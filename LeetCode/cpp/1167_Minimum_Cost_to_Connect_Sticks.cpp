class Solution {
public:
	int connectSticks(vector<int>& sticks) {
		int answer = 0, sum = 0;
		if (sticks.size() == 1) {
			return answer;
		}

		if (sticks.size() == 2) {
			answer = sticks[0] + sticks[1];
			return answer;
		}

		priority_queue<int, vector<int>, greater<>> lo;

		for (int n : sticks) {
			lo.push(n);
		}

		while (lo.size() > 1) {
			int a = 0, b = 0;

			if (!lo.empty()) {
				a = lo.top();
				lo.pop();
			}

			if (!lo.empty()) {
				b = lo.top();
				lo.pop();
			}

			sum = a + b;
			answer += sum;

			lo.push(sum);
		}

		return answer;
	}
};