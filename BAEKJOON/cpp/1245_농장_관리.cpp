#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n, m, answer = 0;
int map[100][70];
bool visit[100][70];
bool flag;

int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int dy[] = { 1, -1, 0, 0 , -1, 1, -1, 1};

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			
			if (map[x][y] < map[nx][ny])
				flag = false;

			if (map[nx][ny] == map[x][y] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != 0 && visit[i][j] == false) {
				flag = true;
				bfs(i, j);
				if (flag) 
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