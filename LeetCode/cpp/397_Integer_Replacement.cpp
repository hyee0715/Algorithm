class Solution {
public:
	int bfs(int n) {
		queue<pair<long long, int>> q; //currnet number, operation count
		q.push({ n, 0 });

		while (!q.empty()) {
			long long x = q.front().first;
			int cnt = q.front().second;
			q.pop();

			if (x == 1) {
				return cnt;
			}

			if (x % 2 == 0) {
				long long nx = x / 2;

				if (nx < 0) {
					continue;
				}

				q.push({ nx, cnt + 1 });
			}
			else {
				long long nx = x - 1;

				if (nx < 0) {
					continue;
				}

				q.push({ nx, cnt + 1 });

				nx = x + 1;

				if (nx < 0 || nx >(long long)n + 1) {
					continue;
				}

				q.push({ nx, cnt + 1 });
			}
		}

		return 0;
	}

	int integerReplacement(int n) {
		return bfs(n);
	}
};