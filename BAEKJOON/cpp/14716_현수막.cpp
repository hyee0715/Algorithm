#include <iostream>
#include <cstring>
#include <queue>

#define MAX 260
using namespace std;

int m, n;
int map[MAX][MAX];
bool visit[MAX][MAX];
int answer = 0;

int dx[] = { 0, 0, 1, -1, 1, -1, -1, 1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void input() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (map[nx][ny] == 1 && visit[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				bfs(i, j);
				answer++;
			}
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}