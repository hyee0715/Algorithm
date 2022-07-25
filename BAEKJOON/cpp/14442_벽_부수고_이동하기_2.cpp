#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>

#define MAX 1000
using namespace std;

int n, m, k, cnt = 1;
vector<vector<int> > map;
bool visit[MAX][MAX][11]; //visit[a][b][c]에서 c는 벽을 부술 수 있는 횟수

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		vector<int> v;
		for (int j = 0; j < m; j++) {
			v.push_back(s[j] - '0');
		}

		map.push_back(v);
	}
}

void bfs(int a, int b, int c) {
	queue<pair<pair<int, int>, pair<int, int> > > q; //x좌표, y좌표, 벽을 부순 횟수, 이동 경로 수
	q.push({ {a, b}, {0, c} });
	visit[a][b][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall_cnt = q.front().second.first;
		int count = q.front().second.second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << count;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//벽이 없는 경우
			if (map[nx][ny] == 0 && visit[nx][ny][wall_cnt] == false) {
				q.push({ {nx, ny}, {wall_cnt, count + 1} });
				visit[nx][ny][wall_cnt] = true;
			}
			//벽이 있을 때 벽을 부수는 경우
			else if (map[nx][ny] == 1 && visit[nx][ny][wall_cnt + 1] == false && wall_cnt < k) {
				q.push({ {nx, ny}, {wall_cnt + 1, count + 1} });
				visit[nx][ny][wall_cnt + 1] = true;
			}
		}
	}

	cout << "-1";
}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(0, 0, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}