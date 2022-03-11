#include <iostream>
#include <cstring>
#include <queue>

#define MAX 50
using namespace std;

int w, h, cnt;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
int dy[] = { 1, -1, 0, 0 , 1, -1, 1, -1 };

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

			if (nx >= 0 && ny >= 0 && nx < h && ny < w) {
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
	cnt = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				cnt++;
				bfs(i, j);
			}
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> w >> h;

		if (w == 0 && h == 0) {
			break;
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		solution();
	}

	return 0;
}