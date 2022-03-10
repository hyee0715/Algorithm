#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define MAX 100
using namespace std;

int h, w, cnt = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void initialize() {
	memset(visit, false, sizeof(visit));
	memset(map, 0, sizeof(map));
	cnt = 0;
}

void input() {
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < w; j++) {
			map[i][j] = s[j];
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

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 & ny >= 0 && nx < h && ny < w) {
				if (map[nx][ny] == '#' && visit[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
				}
			}
		}
	}
}

void solution() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == '#' && visit[i][j] == false) {
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

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}