#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define MAX 600
using namespace std;

int n, m, cnt = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> start;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];

			if (map[i][j] == 'I')
				start = make_pair(i, j);
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

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if ((map[nx][ny] == 'O' || map[nx][ny] == 'P') && visit[nx][ny] == false) {
					if (map[nx][ny] == 'P')
						cnt++;
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(start.first, start.second);

	if (cnt == 0) {
		cout << "TT";
	}
	else {
		cout << cnt;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}