#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 1001
using namespace std;

int n, m, cnt = 0;
vector<int> vec[MAX];
bool visit[MAX];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}

//void dfs(int x) {
//	if (visit[x]) return;
//	visit[x] = true;
//
//	for (int i = 0; i < vec[x].size(); i++) {
//		int nx = vec[x][i];
//		dfs(nx);
//	}
//}

void bfs(int a) {
	queue<int> q;
	q.push(a);
	visit[a] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < vec[x].size(); i++) {
			int nx = vec[x][i];

			if (visit[nx] == false) {
				visit[nx] = true;
				q.push(nx);
			}
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			cnt++;
			//dfs(i);
			bfs(i);
		}
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}