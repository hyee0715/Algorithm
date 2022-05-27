#include <iostream>
#include <queue>

using namespace std;

long long a, b;

void input() {
	cin >> a >> b;
}

void bfs(long long a, int count) {
	queue<pair<int, int> > q;
	q.push({ a, count });

	while (!q.empty()) {
		long long n = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (n == b) {
			cout << cnt + 1;
			return;
		}

		long long nx = n * 2;
		if (nx <= b)
			q.push({ nx, cnt + 1 });

		nx = (n * 10) + 1;
		if (nx <= b)
			q.push({ nx, cnt + 1 });
	}

	cout << "-1";
}

void solution() {
	bfs(a, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}