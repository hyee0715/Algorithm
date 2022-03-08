#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define MAX 1001
using namespace std;

int n, m, cnt = 1;
int map[MAX][MAX];
bool visit[MAX][MAX][2]; // visit[][][0] : 벽을 부수지 않음, visit[][][1] : 벽을 부숨

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			map[i][j + 1] = s[j] - '0';
		}
	}
}

void bfs(int a, int b, int c, int d) { // (x 좌표, y 좌표, 벽 안부숨(0)/벽 부숨(1), 이동한 거리)
	queue<pair<pair<int, int>, pair<int, int> > > q;
	q.push(make_pair(make_pair(a, b), make_pair(c, d)));
    	visit[a][b][c] = true;
//	visit[a][b][0] = true;
//	visit[a][b][1] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall_break = q.front().second.first;
		int count = q.front().second.second;
		q.pop();

		if (x == n && y == m) {
			cout << count;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx > 0 && ny > 0 && nx <= n && ny <= m) {
				//벽을 부수는 경우
				if (wall_break == 0 && map[nx][ny] == 1 && visit[nx][ny][wall_break + 1] == false) {
					visit[nx][ny][wall_break + 1] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(wall_break + 1, count + 1)));
				}

				//벽을 부수지 않는 경우
				if (map[nx][ny] == 0 && visit[nx][ny][wall_break] == false) {
					visit[nx][ny][wall_break] = true;
					q.push(make_pair(make_pair(nx, ny), make_pair(wall_break, count + 1)));
				}
			}
		}
	}

	cout << "-1";
}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(1, 1, 0, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}