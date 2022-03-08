#include <iostream>
#include <cstring>
#include <queue>

#define MAX 1000
using namespace std;

int n, m, cnt = 0;
int map[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int> > q;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}
}

bool isAllRipe() { // 다 익었으면 true, 다 안익었으면 false
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
				return false;
		}
	}

	return true;
}

void bfs() {
	while (!q.empty()) {
		int qs = q.size();

		for (int k = 0; k < qs; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (map[nx][ny] == 0 && visit[nx][ny] == false) {
						visit[nx][ny] = true;
						q.push(make_pair(nx, ny));
						map[nx][ny] = 1;
					}
				}

			}
		}

		cnt++;

		if (isAllRipe()) {
			cout << cnt;
			return;
		}
	}

	if (!isAllRipe()) {
		cout << "-1";
	}
}

void solution() {
	if (isAllRipe()) {
		cout << "0";
		return;
	}

	bfs();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit, false, sizeof(visit));

	input();
	solution();

	return 0;
}