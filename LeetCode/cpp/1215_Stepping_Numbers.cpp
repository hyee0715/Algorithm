class Solution {
public:
	vector<int> countSteppingNumbers(int low, int high) {
		vector<int> answer;

		queue<long long> q;

		if (low == 0) {
			answer.push_back(0);
		}

		for (int i = 1; i <= 9; i++) {
			q.push(i);
		}

		while (!q.empty()) {
			long long n = q.front();
			q.pop();

			if (n < high) {
				long long last = n % 10;

				if (last > 0) {
					long long next = n * 10 + last - 1;
					q.push(next);
				}

				if (last < 9) {
					long long next = n * 10 + last + 1;
					q.push(next);
				}
			}

			if (n >= low && n <= high) {
				answer.push_back((int)n);
			}
		}

		return answer;
	}
};