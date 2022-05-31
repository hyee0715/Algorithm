#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

#define MAX 101
#define INF 987654321;
using namespace std;

int n, m, friend_cnt, min_idx, min_num = INF;
vector<int> v[MAX];
bool visit[MAX];
int friends[MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}
}

int bfs(int a, int count) {
	queue<pair<int, int> > q;
	q.push({ a, count });
	visit[a] = true;
	friend_cnt = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		friend_cnt += cnt;

		for (int i = 0; i < v[x].size(); i++) {
			int nx = v[x][i];

			if (visit[nx] == false) {
				q.push({ nx, cnt + 1 });
				visit[nx] = true;
			}
		}
	}

	return friend_cnt;
}

void solution() {
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));

		friends[i] = bfs(i, 0);
	}

	for (int i = 1; i <= n; i++) {
		if (min_num > friends[i]) {
			min_num = friends[i];
			min_idx = i;
		}
	}

	cout << min_idx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}