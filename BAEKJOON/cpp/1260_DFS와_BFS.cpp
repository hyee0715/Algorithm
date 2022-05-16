#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 1001
using namespace std;

int n, m, v;
bool visit[MAX];
vector<int> node[MAX];

void input() {
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}
}

void dfs(int x) {
	if (visit[x] == true) return;
	visit[x] = true;
	cout << x << " ";

	for (int i = 0; i < node[x].size(); i++) {
		int nx = node[x][i];

		if (visit[nx] == false)
			dfs(nx);
	}
}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	visit[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";

		for (int i = 0; i < node[x].size(); i++) {
			int nx = node[x][i];

			if (visit[nx] == false) {
				q.push(nx);
				visit[nx] = true;
			}
		}
	}
}

void solution() {
	for (int i = 1; i <= n; i++) {
		sort(node[i].begin(), node[i].end());
	}

	memset(visit, false, sizeof(visit));
	dfs(v);
	cout << "\n";

	memset(visit, false, sizeof(visit));
	bfs(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}